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
#include <rte_reorder.h>
#include <rte_prefetch.h>

#define NUM_MBUFS 2048
#define MBUF_CACHE_SIZE 128
#define BURST_SIZE 9
#define REORDER_SIZE 8

static uint64_t timer_period = 100000000;

int main(int argc, char *argv[])
{
    uint64_t cur_tsc, prev_tsc = 0;
    struct rte_reorder_buffer *b = NULL;
    const unsigned int size = REORDER_SIZE;
    const unsigned int num_bufs = 512;
    struct rte_mbuf *bufs[num_bufs];
    struct rte_mbuf *robufs[num_bufs];
    unsigned i, count=0, cnt;
    struct rte_mempool *mbuf_pool;

	int ret = rte_eal_init(argc, argv);
	if (ret < 0)
		rte_exit(EXIT_FAILURE, "Error with EAL initialization\n");

    mbuf_pool = rte_pktmbuf_pool_create("MBUF_POOL",
            NUM_MBUFS, MBUF_CACHE_SIZE, 0,
            RTE_MBUF_DEFAULT_BUF_SIZE, rte_socket_id());

    b = rte_reorder_create("test_reorder", rte_socket_id(), size);
    ret = rte_mempool_get_bulk(mbuf_pool, (void *)bufs, num_bufs);
    for(i = 0; i < num_bufs; i++)
        bufs[i]->seqn = i;
    
    for(;;){
        cur_tsc = rte_rdtsc();
        if(unlikely(cur_tsc-prev_tsc >= timer_period)){
            printf("reorder speed: %d\n", count);
            count = 0;
            prev_tsc = cur_tsc;
        }
        for(i = 0; i< BURST_SIZE; i++){
            ret = rte_reorder_insert_opt(b, bufs[i]);
            if(ret < 0) printf("wrong!:%d\n",i);
        }
        cnt = rte_reorder_drain_opt(b, robufs, BURST_SIZE);
//        rte_reorder_reset(b);
        //memcpy(bufs, robufs, cnt * sizeof(struct rte_mbuf*));
//        rte_prefetch0(bufs[0]);
        for(i = 0; i< BURST_SIZE; i++){
            bufs[i]->seqn += BURST_SIZE;
        }
        //printf("%d\n",cnt);
        count += cnt;
        //count++;
    }
    return 0;
}
