cmd_cxgbe_ethdev.o = gcc -Wp,-MD,./.cxgbe_ethdev.o.d.tmp  -pthread  -march=armv8-a+crc -D__ARM_FEATURE_CRC32=1 -DRTE_MACHINE_CPUFLAG_NEON -DRTE_MACHINE_CPUFLAG_CRC32  -I/root/dpdk-stable-16.07.1/build/include -include /root/dpdk-stable-16.07.1/build/include/rte_config.h -I/root/dpdk-stable-16.07.1/drivers/net/cxgbe/base/ -I/root/dpdk-stable-16.07.1/drivers/net/cxgbe -O3 -W -Wall -Wstrict-prototypes -Wmissing-prototypes -Wmissing-declarations -Wold-style-definition -Wpointer-arith -Wcast-align -Wnested-externs -Wcast-qual -Wformat-nonliteral -Wformat-security -Wundef -Wwrite-strings -Wno-deprecated   -o cxgbe_ethdev.o -c /root/dpdk-stable-16.07.1/drivers/net/cxgbe/cxgbe_ethdev.c 
