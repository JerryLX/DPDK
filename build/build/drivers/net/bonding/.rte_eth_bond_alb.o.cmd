cmd_rte_eth_bond_alb.o = gcc -Wp,-MD,./.rte_eth_bond_alb.o.d.tmp  -pthread  -march=armv8-a+crc -D__ARM_FEATURE_CRC32=1 -DRTE_MACHINE_CPUFLAG_NEON -DRTE_MACHINE_CPUFLAG_CRC32  -I/root/dpdk-stable-16.07.1/build/include -include /root/dpdk-stable-16.07.1/build/include/rte_config.h -O3 -W -Wall -Wstrict-prototypes -Wmissing-prototypes -Wmissing-declarations -Wold-style-definition -Wpointer-arith -Wcast-align -Wnested-externs -Wcast-qual -Wformat-nonliteral -Wformat-security -Wundef -Wwrite-strings   -o rte_eth_bond_alb.o -c /root/dpdk-stable-16.07.1/drivers/net/bonding/rte_eth_bond_alb.c 
