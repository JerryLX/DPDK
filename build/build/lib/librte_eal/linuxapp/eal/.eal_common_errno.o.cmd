cmd_eal_common_errno.o = gcc -Wp,-MD,./.eal_common_errno.o.d.tmp  -pthread  -march=armv8-a+crc -D__ARM_FEATURE_CRC32=1 -DRTE_MACHINE_CPUFLAG_NEON -DRTE_MACHINE_CPUFLAG_CRC32  -I/root/dpdk-stable-16.07.1/build/include -include /root/dpdk-stable-16.07.1/build/include/rte_config.h -I/root/dpdk-stable-16.07.1/lib/librte_eal/linuxapp/eal/include -I/root/dpdk-stable-16.07.1/lib/librte_eal/common -I/root/dpdk-stable-16.07.1/lib/librte_eal/common/include -W -Wall -Wstrict-prototypes -Wmissing-prototypes -Wmissing-declarations -Wold-style-definition -Wpointer-arith -Wcast-align -Wnested-externs -Wcast-qual -Wformat-nonliteral -Wformat-security -Wundef -Wwrite-strings -O3   -o eal_common_errno.o -c /root/dpdk-stable-16.07.1/lib/librte_eal/common/eal_common_errno.c 
