cmd_e1000_vf.o = gcc -Wp,-MD,./.e1000_vf.o.d.tmp  -pthread  -march=armv8-a+crc -D__ARM_FEATURE_CRC32=1 -DRTE_MACHINE_CPUFLAG_NEON -DRTE_MACHINE_CPUFLAG_CRC32  -I/root/dpdk-stable-16.07.1/build/include -include /root/dpdk-stable-16.07.1/build/include/rte_config.h -O3 -W -Wall -Wstrict-prototypes -Wmissing-prototypes -Wmissing-declarations -Wold-style-definition -Wpointer-arith -Wcast-align -Wnested-externs -Wcast-qual -Wformat-nonliteral -Wformat-security -Wundef -Wwrite-strings -Wno-uninitialized -Wno-unused-parameter -Wno-unused-variable  -o e1000_vf.o -c /root/dpdk-stable-16.07.1/drivers/net/e1000/base/e1000_vf.c 
