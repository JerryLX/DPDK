cmd_test_timer.o = gcc -Wp,-MD,./.test_timer.o.d.tmp  -pthread  -march=armv8-a+crc -D__ARM_FEATURE_CRC32=1 -DRTE_MACHINE_CPUFLAG_NEON -DRTE_MACHINE_CPUFLAG_CRC32  -I/root/dpdk-stable-16.07.1/build/include -include /root/dpdk-stable-16.07.1/build/include/rte_config.h -O3 -W -Wall -Wstrict-prototypes -Wmissing-prototypes -Wmissing-declarations -Wold-style-definition -Wpointer-arith -Wcast-align -Wnested-externs -Wcast-qual -Wformat-nonliteral -Wformat-security -Wundef -Wwrite-strings -D_GNU_SOURCE   -o test_timer.o -c /root/dpdk-stable-16.07.1/app/test/test_timer.c 
