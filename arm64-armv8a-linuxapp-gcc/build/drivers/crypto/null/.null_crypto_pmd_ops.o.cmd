cmd_null_crypto_pmd_ops.o = gcc -Wp,-MD,./.null_crypto_pmd_ops.o.d.tmp  -pthread  -march=armv8-a+crc -D__ARM_FEATURE_CRC32=1 -DRTE_MACHINE_CPUFLAG_NEON -DRTE_MACHINE_CPUFLAG_CRC32  -I/root/lixu/arm64-armv8a-linuxapp-gcc/include -include /root/lixu/arm64-armv8a-linuxapp-gcc/include/rte_config.h -O3 -W -Wall -Wstrict-prototypes -Wmissing-prototypes -Wmissing-declarations -Wold-style-definition -Wpointer-arith -Wcast-align -Wnested-externs -Wcast-qual -Wformat-nonliteral -Wformat-security -Wundef -Wwrite-strings -Werror   -o null_crypto_pmd_ops.o -c /root/lixu/drivers/crypto/null/null_crypto_pmd_ops.c 