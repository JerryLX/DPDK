/*-
 *   BSD LICENSE
 *
 *   Copyright(c) 2010-2015 Intel Corporation. All rights reserved.
 *   All rights reserved.
 *
 *   Redistribution and use in source and binary forms, with or without
 *   modification, are permitted provided that the following conditions
 *   are met:
 *
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in
 *       the documentation and/or other materials provided with the
 *       distribution.
 *     * Neither the name of Intel Corporation nor the names of its
 *       contributors may be used to endorse or promote products derived
 *       from this software without specific prior written permission.
 *
 *   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *   A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *   OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *   LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *   DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *   THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *   OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <inttypes.h>
#include <sys/types.h>
#include <sys/queue.h>
#include <netinet/in.h>
#include <setjmp.h>
#include <stdarg.h>
#include <ctype.h>
#include <errno.h>
#include <getopt.h>
#include <signal.h>
#include <stdbool.h>

#include <rte_common.h>
#include <rte_log.h>
#include <rte_malloc.h>
#include <rte_memory.h>
#include <rte_memcpy.h>
#include <rte_memzone.h>
#include <rte_eal.h>
#include <rte_per_lcore.h>
#include <rte_launch.h>
#include <rte_atomic.h>
#include <rte_cycles.h>
#include <rte_prefetch.h>
#include <rte_lcore.h>
#include <rte_per_lcore.h>
#include <rte_branch_prediction.h>
#include <rte_interrupts.h>
#include <rte_pci.h>
#include <rte_random.h>
#include <rte_debug.h>
#include <rte_ether.h>
#include <rte_ethdev.h>
#include <rte_ring.h>
#include <rte_mempool.h>
#include <rte_mbuf.h>
#include <rte_meter.h>


#define RX_RING_SIZE 128
#define TX_RING_SIZE 512

#define NUM_MBUFS 32768
#define MBUF_CACHE_SIZE 256
#define BURST_SIZE 256

// static uint64_t timer_period = 100000000;
// static uint64_t speed = 0;
// static uint64_t tspeed = 0;

#define nTEST_CORE 1
#define nQUEUE 16

#define TIME_TX_DRAIN                   200000ULL


/*
 * Traffic metering configuration
 *
 */
#define APP_MODE_FWD                    0
#define APP_MODE_SRTCM_COLOR_BLIND      1
#define APP_MODE_SRTCM_COLOR_AWARE      2
#define APP_MODE_TRTCM_COLOR_BLIND      3
#define APP_MODE_TRTCM_COLOR_AWARE      4

#define APP_MODE	APP_MODE_SRTCM_COLOR_BLIND


#include "main.h"


#define APP_PKT_FLOW_POS                33
#define APP_PKT_COLOR_POS               5


#if APP_PKT_FLOW_POS > 64 || APP_PKT_COLOR_POS > 64
#error Byte offset needs to be less than 64
#endif



/*
 * NIC configuration
 *
 ***/
static struct rte_eth_conf port_conf_default = {
	.rxmode = {
		.mq_mode	= ETH_MQ_RX_RSS,
		.max_rx_pkt_len = ETHER_MAX_LEN,
		.split_hdr_size = 0,
		.header_split   = 0,
		.hw_ip_checksum = 1,
		.hw_vlan_filter = 0,
		.jumbo_frame    = 0,
		.hw_strip_crc   = 0,
	},
	.rx_adv_conf = {
		.rss_conf = {
			.rss_key = NULL,
			.rss_hf = ETH_RSS_IP,
		},
	},
	.txmode = {
		.mq_mode = ETH_DCB_NONE,
	},
};
static uint64_t count_rx=0;
static uint64_t count_tx=0;
static uint64_t count_drop=0;
static unsigned nb_ports;

static struct rte_eth_dev_tx_buffer *tx_buffer[nQUEUE];

struct rte_meter_srtcm_params app_srtcm_params[] = {
	{.cir = 1000000 * 46,  .cbs = 2048, .ebs = 2048},
};

struct rte_meter_trtcm_params app_trtcm_params[] = {
	{.cir = 1000000 * 46,  .pir = 1500000 * 46,  .cbs = 2048, .pbs = 2048},
};


static volatile bool force_quit;

#define APP_FLOWS_MAX  256

FLOW_METER app_flows[APP_FLOWS_MAX];

static int color[3]={0,0,0};


static int
app_configure_flow_table(void)
{
	uint32_t i, j;
	int ret;
//printf("hz:%lu\n", rte_get_tsc_hz());
	for (i = 0, j = 0; i < APP_FLOWS_MAX;
			i ++, j = (j + 1) % RTE_DIM(PARAMS)) {
		ret = FUNC_CONFIG(&app_flows[i], &PARAMS[j]);
		if (ret)
			return ret;
	}

	return 0;
}

static inline void
app_set_pkt_color(uint8_t *pkt_data, enum policer_action color)
{
	pkt_data[APP_PKT_COLOR_POS] = (uint8_t)color;
}

static inline int
app_pkt_handle(struct rte_mbuf *pkt, uint64_t time)
{
	uint8_t input_color, output_color;
	uint8_t *pkt_data = rte_pktmbuf_mtod(pkt, uint8_t *);
	uint32_t pkt_len = rte_pktmbuf_pkt_len(pkt) - sizeof(struct ether_hdr);
	uint8_t flow_id = (uint8_t)(pkt_data[APP_PKT_FLOW_POS] & (APP_FLOWS_MAX - 1));
	input_color = pkt_data[APP_PKT_COLOR_POS];
    enum policer_action action;
//    printf("flow_id = %d, input_color = %d\n", flow_id, input_color); 
	/* color input is not used for blind modes */
	output_color = (uint8_t) FUNC_METER(&app_flows[flow_id], time, pkt_len,
		(enum rte_meter_color) input_color);
    color[output_color]++; 
	/* Apply policing and set the output color */
	action = policer_table[input_color][output_color];
   // printf("input_color= %d, output_color= %d, action= %d\n",input_color, output_color, action);
	app_set_pkt_color(pkt_data, action);
    return output_color;
    //return action;
}



/*
 * Initialises a given port using global settings and with the rx buffers
 * coming from the mbuf_pool passed as parameter
 */
static inline int
port_init(uint8_t port, struct rte_mempool *mbuf_pool)
{
	struct rte_eth_conf port_conf = port_conf_default;
	const uint16_t rx_rings = 16, tx_rings = 16;
	int retval;
	uint16_t q;

	if (port >= rte_eth_dev_count())
		return -1;


    printf("init port: %d\n", port);
    retval = rte_eth_dev_configure(port, rx_rings, tx_rings, &port_conf);
	if (retval != 0)
		return retval;

	for (q = 0; q < rx_rings; q++) {
		retval = rte_eth_rx_queue_setup(port, q, RX_RING_SIZE,
				rte_eth_dev_socket_id(port), NULL, mbuf_pool);
		if (retval < 0)
			return retval;
	}
	for (q = 0; q < tx_rings; q++) {
		retval = rte_eth_tx_queue_setup(port, q, TX_RING_SIZE,
				rte_eth_dev_socket_id(port), NULL);
		if (retval < 0)
			return retval;
	}


	//initialize tx_buffer for port_tx
	if(port)
	{
		for(q=0;q<16;q++){
			tx_buffer[q] = rte_zmalloc_socket("tx_buffer",
			RTE_ETH_TX_BUFFER_SIZE(BURST_SIZE), 0,
			rte_eth_dev_socket_id(port));
			if (tx_buffer[q] == NULL)
				rte_exit(EXIT_FAILURE, "Port %d TX buffer allocation error\n",
						port);

			rte_eth_tx_buffer_init(tx_buffer[q], BURST_SIZE);
		}
	}

	retval  = rte_eth_dev_start(port);	

    if (retval < 0)
		return retval;
    printf("after start port\n");
    
	struct ether_addr addr;

	rte_eth_macaddr_get(port, &addr);
	printf("Port %u MAC: %02"PRIx8" %02"PRIx8" %02"PRIx8
			" %02"PRIx8" %02"PRIx8" %02"PRIx8"\n",
			(unsigned)port,
			addr.addr_bytes[0], addr.addr_bytes[1],
			addr.addr_bytes[2], addr.addr_bytes[3],
			addr.addr_bytes[4], addr.addr_bytes[5]);

	rte_eth_promiscuous_enable(port);

	return 0;
}



//static __attribute__((noreturn)) int
//main_loop(__attribute__((unused)) void *dummy)
static void main_loop(void);
static int test_qos_one_core (__attribute__ ((unused)) void *dummy)
{
    main_loop();
    return 0;
}

static void main_loop(void)
{
	uint64_t current_time, last_time = rte_rdtsc();
	uint32_t lcore_id = rte_lcore_id();
	uint16_t qid;
	uint16_t port_tx=1;
	uint16_t port_rx=0;
	printf("Core %u: port RX = %d, port TX = %d\n", lcore_id, port_rx, port_tx);

	while (!force_quit) {
		uint64_t time_diff;
		int i, nb_rx;

		/* Mechanism to avoid stale packets in the output buffer */
		current_time = rte_rdtsc();
		time_diff = current_time - last_time;
		if (unlikely(time_diff > TIME_TX_DRAIN)) {
			/* Flush tx buffer */
			for(qid=0;qid<16;qid++){
				rte_eth_tx_buffer_flush(port_tx, qid, tx_buffer[qid]);
			}
			last_time = current_time;
		}
		/* Read packet burst from NIC RX */
		for(qid=0;qid<16;qid++){
			struct rte_mbuf *pkts_rx[BURST_SIZE];
			nb_rx = rte_eth_rx_burst(port_rx, qid, pkts_rx, BURST_SIZE);
            count_rx+=nb_rx;
			/* Handle packets */
			for (i = 0; i < nb_rx; i ++) {
				struct rte_mbuf *pkt = pkts_rx[i];

				/* Handle current packet */
				if (  app_pkt_handle(pkt, current_time) == DROP)  //||DROP)
                {	
                    count_drop++;
                    rte_pktmbuf_free(pkt);
                }
				else{
                    count_tx++;
					rte_eth_tx_buffer(port_tx, qid, tx_buffer[qid], pkt);
                }
			}
		}
	}
}

static void
signal_handler(int signum)
{
    if(signum == SIGINT || signum == SIGTERM){
        printf("Signal %d erceived, preparing to exit...\n",
                signum);
        force_quit = true;
    }
}





/* Main function, does initialisation and calls the per-lcore functions */
int
main(int argc, char *argv[])
{
	struct rte_mempool *mbuf_pool;
	uint8_t portid;

	/* init EAL */
	int ret = rte_eal_init(argc, argv);

	if (ret < 0)
		rte_exit(EXIT_FAILURE, "Error with EAL initialization\n");
	argc -= ret;
	argv += ret;
    
    force_quit=false;
    signal(SIGINT, signal_handler);
    signal(SIGTERM, signal_handler);
    
	nb_ports = rte_eth_dev_count();
    printf("num of ports: %d\n", nb_ports);
	if (nb_ports < 2 || (nb_ports & 1))
		rte_exit(EXIT_FAILURE, "Error: number of ports must be even\n");

	mbuf_pool = rte_pktmbuf_pool_create("MBUF_POOL",
		NUM_MBUFS * nb_ports, MBUF_CACHE_SIZE, 0,
		RTE_MBUF_DEFAULT_BUF_SIZE, rte_socket_id());
	if (mbuf_pool == NULL)
		rte_exit(EXIT_FAILURE, "Cannot create mbuf pool\n");

	/* initialize all ports */
	for (portid = 0; portid < nb_ports; portid++)
		if (port_init(portid, mbuf_pool) != 0)
			rte_exit(EXIT_FAILURE, "Cannot init port %"PRIu8"\n",
					portid);

    printf("after port init\n");

	/* App configuration */
	ret = app_configure_flow_table();
	if (ret < 0)
		rte_exit(EXIT_FAILURE, "Invalid configure flow table\n");


	/* Launch per-lcore init on every lcore */
	rte_eal_mp_remote_launch(test_qos_one_core, NULL, CALL_MASTER);
    printf("\n============statistics==================\n\n");
    printf("count_rx   = %lu\n", count_rx);
    printf("count_tx   = %lu\n", count_tx);
    printf("count_drop = %lu\n",count_drop);


    printf("%d, %d, %d\n", color[0],color[1],color[2]);
    printf("\n============statistics==================\n\n");

	return 0;
}
