cmd_test_ring_perf.o = gcc -Wp,-MD,./.test_ring_perf.o.d.tmp  -pthread  -march=armv8-a+crc -D__ARM_FEATURE_CRC32=1 -DRTE_MACHINE_CPUFLAG_NEON -DRTE_MACHINE_CPUFLAG_CRC32  -I/root/dpdk-stable-16.07.1/app/test/build/include -I/root/dpdk-stable-16.07.1/arm64-armv8a-linuxapp-gcc/include -include /root/dpdk-stable-16.07.1/arm64-armv8a-linuxapp-gcc/include/rte_config.h -O3 -W -Wall -Wstrict-prototypes -Wmissing-prototypes -Wmissing-declarations -Wold-style-definition -Wpointer-arith -Wcast-align -Wnested-externs -Wcast-qual -Wformat-nonliteral -Wformat-security -Wundef -Wwrite-strings -D_GNU_SOURCE   -o test_ring_perf.o -c test_ring_perf.c 
