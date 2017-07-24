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
#include <ctype.h>
#include <errno.h>
#include <signal.h>

#include <rte_common.h>
#include <rte_log.h>
#include <rte_eal.h>
#include <rte_per_lcore.h>
#include <rte_launch.h>
#include <rte_atomic.h>
#include <rte_cycles.h>
#include <rte_lcore.h>
#include <rte_per_lcore.h>
#include <rte_interrupts.h>
#include <rte_pci.h>
#include <rte_random.h>
#include <rte_debug.h>
#include <rte_ip.h>
#include <rte_lpm.h>
#include <rte_trie.h>
#define RING_SIZE 16384
#define MAX_BULK 32
#define BURST_SIZE 128
#define OPTIMIZATION
static uint64_t timer_period = 100000000;

static int enabled_port_mask = 3;

#define IPV4_L3FWD_LPM_NUM_ROUTES \
	(sizeof(ipv4_l3fwd_lpm_route_array) / sizeof(ipv4_l3fwd_lpm_route_array[0]))
#define IPV4_L3FWD_LPM_MAX_RULES         1024
#define IPV4_L3FWD_LPM_NUMBER_TBL8S (1 << 8)

struct rte_trie *trie_lookup_struct;
struct ipv4_l3fwd_lpm_route {
	uint32_t ip;
	uint8_t  depth;
	uint8_t  if_out;
};

static struct ipv4_l3fwd_lpm_route ipv4_l3fwd_lpm_route_array[] = {
{IPv4(3, 168, 1, 0), 24, 0},
    {IPv4(4, 167, 1, 0), 22, 0},
    {IPv4(5, 166, 1, 0), 22, 0},
    {IPv4(6, 165, 1, 0), 26, 0},
    {IPv4(7, 164, 1, 0), 22, 0},
    {IPv4(8, 163, 1, 0), 26, 0},
    {IPv4(9, 162, 1, 0), 22, 0},
    {IPv4(10, 161, 1, 0), 24, 0},
    {IPv4(11, 160, 1, 0), 22, 0},
//	{IPv4(64, 168, 1, 0), 24, 0},
//	{IPv4(64, 168, 0, 16), 24, 1},
/*	{IPv4(64, 168, 1, 0), 24, 0},
	{IPv4(74, 120, 38, 0), 22, 1},
	{IPv4(64, 168, 1, 240), 28, 2},
	{IPv4(74, 168, 1, 192), 26, 3},
	{IPv4(76, 24, 24, 53), 23, 4},
	{IPv4(8, 8, 8, 8), 24, 5},
*/  //	{IPv4(1, 1, 1, 0), 13, 6},
//	{IPv4(1, 1, 1, 0), 16, 7},

    };
static
void setup_lpm(const int socketid)
{
	struct rte_lpm_config config_ipv4;
	unsigned i;
	int ret;
	char s[64];

	/* create the LPM table */
	config_ipv4.max_rules = IPV4_L3FWD_LPM_MAX_RULES;
	config_ipv4.number_tbl8s = IPV4_L3FWD_LPM_NUMBER_TBL8S;
	config_ipv4.flags = 0;
	//void(config_ipv4);
    snprintf(s, sizeof(s), "IPV4_L3FWD_LPM_%d", socketid);
	trie_lookup_struct =
			rte_trie_create(s, socketid);
	if (trie_lookup_struct == NULL)
		rte_exit(EXIT_FAILURE,
			"Unable to create the l3fwd LPM table on socket %d\n",
			socketid);
	/* populate the LPM table */
	for (i = 0; i < IPV4_L3FWD_LPM_NUM_ROUTES; i++) {

		/* skip unused ports */
/*		if ((1 << ipv4_l3fwd_lpm_route_array[i].if_out &
				enabled_port_mask) == 0)
			continue;
*/
        (void)enabled_port_mask;
		ret = rte_trie_add(trie_lookup_struct,
			ipv4_l3fwd_lpm_route_array[i].ip,
			ipv4_l3fwd_lpm_route_array[i].depth,
			ipv4_l3fwd_lpm_route_array[i].if_out,socketid);
   //     uint32_t ip = ipv4_l3fwd_lpm_route_array[i].ip;
     // const  uint32_t *papa = (const uint32_t *)(&(trie_lookup_struct->tbl24[ip>>8]));
       // printf("====%x\n",*papa);
		if (ret < 0) {
			rte_exit(EXIT_FAILURE,
				"Unable to add entry %u to the l3fwd LPM table on socket %d\n",
				i, socketid);
		}

		printf("LPM: Adding route 0x%08x / %d (%d)\n",
			(unsigned)ipv4_l3fwd_lpm_route_array[i].ip,
			ipv4_l3fwd_lpm_route_array[i].depth,
			ipv4_l3fwd_lpm_route_array[i].if_out);
	}
    (void)ret;
    (void)config_ipv4;

}





int main(int argc, char *argv[])
{
    unsigned count = 0, hit=0;
    uint64_t cur_tsc, prev_tsc = 0;
    uint32_t next_hop;
	int ret = rte_eal_init(argc, argv);
    int i;
    if (ret < 0)
		rte_exit(EXIT_FAILURE, "Error with EAL initialization\n");
    
    setup_lpm(0);
    uint32_t ip;
//    rte_trie_print(trie_lookup_struct);
    while(1){
//    for(i=0;i<100;i++){
        cur_tsc = rte_rdtsc();

    //    ip=(uint32_t)cur_tsc&0xffffffff;
//            ip = lrand48()&0xcaffffff;
            ip = rand();
            //    ip = 0xca000000;
    //        ip = 0x03030303;
     //       ip = 0xd4f8b0;
        if(unlikely(cur_tsc-prev_tsc >= timer_period)){
            printf("lookup speed: %d, hit:%d\n", count,hit);
            count = 0;
            hit=0;
            prev_tsc = cur_tsc;
        }
    //    printf("ip = %8x\t ",ip);
        if(rte_trie_lookup(trie_lookup_struct,ip,&next_hop)==0)
        {
    //        printf("ip = %8x\t next_hop = %d\n", ip, next_hop);
     //       printf("next_hop =  %d\n",next_hop);
            hit++;
        }
        else
        {
  //          printf("route miss \n");
        }
//        printf("\n");

        (void)ip;
        (void)next_hop;
        count++;
    }
    rte_trie_free(trie_lookup_struct);
    (void)i;
    return 0;

}
