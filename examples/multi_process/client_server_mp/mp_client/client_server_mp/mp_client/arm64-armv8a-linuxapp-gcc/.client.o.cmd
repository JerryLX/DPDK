cmd_client.o = gcc -Wp,-MD,./.client.o.d.tmp  -pthread  -march=armv8-a+crc -D__ARM_FEATURE_CRC32=1 -DRTE_MACHINE_CPUFLAG_NEON -DRTE_MACHINE_CPUFLAG_CRC32  -I/root/dpdk-stable-16.07.1/examples/multi_process/client_server_mp/mp_client/client_server_mp/mp_client/arm64-armv8a-linuxapp-gcc/include -I/root/dpdk-stable-16.07.1/arm64-armv8a-linuxapp-gcc/include -include /root/dpdk-stable-16.07.1/arm64-armv8a-linuxapp-gcc/include/rte_config.h -W -Wall -Wstrict-prototypes -Wmissing-prototypes -Wmissing-declarations -Wold-style-definition -Wpointer-arith -Wcast-align -Wnested-externs -Wcast-qual -Wformat-nonliteral -Wformat-security -Wundef -Wwrite-strings -O3 -I/root/dpdk-stable-16.07.1/examples/multi_process/client_server_mp/mp_client/../shared   -o client.o -c /root/dpdk-stable-16.07.1/examples/multi_process/client_server_mp/mp_client/client.c 
