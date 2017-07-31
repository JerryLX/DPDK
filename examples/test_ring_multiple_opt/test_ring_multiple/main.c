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
#include <rte_ring.h>

#define RING_SIZE 4096
#define BURST_SIZE 256


static uint64_t timer_period = 100000000;
static struct rte_ring *r;
static volatile bool force_quit;

static void
test_ring_main_loop(void)
{
    unsigned i, count = 0, lcore_id;
    void **src = NULL, **dst = NULL;
    uint64_t cur_tsc, prev_tsc = 0;
    
    src = malloc(RING_SIZE*2*sizeof(void *));
    for (i = 0; i < RING_SIZE*2; i++)
        src[i] = (void *)(unsigned long)i;

    dst = malloc(RING_SIZE*2*sizeof(void *));
    memset(dst, 0, RING_SIZE*2*sizeof(void *));
    
    lcore_id = rte_lcore_id();

    while(!force_quit){
        cur_tsc = rte_rdtsc();
        if(unlikely(cur_tsc-prev_tsc >= timer_period)){
            printf("LCORE:%d,multi-producer/consumer speed: %d\n", lcore_id,count);
            count = 0;
            prev_tsc = cur_tsc;
        }
        rte_ring_mp_enqueue_burst(r, src, BURST_SIZE);
        rte_ring_mc_dequeue_burst(r, dst, BURST_SIZE);
        count += BURST_SIZE;
    }
}

static int 
test_ring_one_core(__attribute__((unused)) void *dummy)
{
    test_ring_main_loop();
    return 0;
}

static void
signal_handler(int signum)
{
    if(signum == SIGINT || signum == SIGTERM){
        printf("\n\nSignal %d erceived, preparing to exit...\n",
                signum);
        force_quit = true;
    }
}

int main(int argc, char *argv[])
{
    unsigned lcore_id;

	int ret = rte_eal_init(argc, argv);
	if (ret < 0)
		rte_exit(EXIT_FAILURE, "Error with EAL initialization\n");
 
    force_quit = false;
    signal(SIGINT, signal_handler);
    signal(SIGTERM, signal_handler);
    r = rte_ring_create("test", RING_SIZE, SOCKET_ID_ANY, 0);

    rte_eal_mp_remote_launch(test_ring_one_core, NULL, CALL_MASTER);
    RTE_LCORE_FOREACH_SLAVE(lcore_id) {
        if (rte_eal_wait_lcore(lcore_id) < 0) {
            ret = -1;
            break;
        }
    }

    return 0;
}
