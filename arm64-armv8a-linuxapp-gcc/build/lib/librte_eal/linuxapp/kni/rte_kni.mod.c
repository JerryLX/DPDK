#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

__visible struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0x879e21b6, __VMLINUX_SYMBOL_STR(module_layout) },
	{ 0x1629a83a, __VMLINUX_SYMBOL_STR(alloc_pages_current) },
	{ 0x2d3385d3, __VMLINUX_SYMBOL_STR(system_wq) },
	{ 0x2a9ef3c1, __VMLINUX_SYMBOL_STR(device_remove_file) },
	{ 0x6dee52f6, __VMLINUX_SYMBOL_STR(netdev_info) },
	{ 0x361c2a17, __VMLINUX_SYMBOL_STR(kmalloc_caches) },
	{ 0x4f453793, __VMLINUX_SYMBOL_STR(pci_bus_read_config_byte) },
	{ 0xd2b09ce5, __VMLINUX_SYMBOL_STR(__kmalloc) },
	{ 0x9a908b80, __VMLINUX_SYMBOL_STR(test_and_clear_bit) },
	{ 0xf9a482f9, __VMLINUX_SYMBOL_STR(msleep) },
	{ 0x1fdc7df2, __VMLINUX_SYMBOL_STR(_mcount) },
	{ 0x17a142df, __VMLINUX_SYMBOL_STR(__copy_from_user) },
	{ 0x1d00b9e6, __VMLINUX_SYMBOL_STR(up_read) },
	{ 0xd6ee688f, __VMLINUX_SYMBOL_STR(vmalloc) },
	{ 0x8c7d039e, __VMLINUX_SYMBOL_STR(param_ops_int) },
	{ 0xc8f47688, __VMLINUX_SYMBOL_STR(napi_disable) },
	{ 0x6a70ca9, __VMLINUX_SYMBOL_STR(skb_pad) },
	{ 0x7d6bb587, __VMLINUX_SYMBOL_STR(cpu_online_mask) },
	{ 0x18fef9cb, __VMLINUX_SYMBOL_STR(xen_start_info) },
	{ 0x79aa04a2, __VMLINUX_SYMBOL_STR(get_random_bytes) },
	{ 0x2bfb3dd6, __VMLINUX_SYMBOL_STR(dev_mc_add_excl) },
	{ 0xe7fe8a07, __VMLINUX_SYMBOL_STR(pci_disable_device) },
	{ 0xe0ca5d52, __VMLINUX_SYMBOL_STR(dev_uc_add_excl) },
	{ 0x880e2c69, __VMLINUX_SYMBOL_STR(pci_disable_msix) },
	{ 0x5a2cd098, __VMLINUX_SYMBOL_STR(hwmon_device_unregister) },
	{ 0xb147a855, __VMLINUX_SYMBOL_STR(dql_reset) },
	{ 0xdc768f6, __VMLINUX_SYMBOL_STR(netif_carrier_on) },
	{ 0x805debed, __VMLINUX_SYMBOL_STR(pci_disable_sriov) },
	{ 0xc0a3d105, __VMLINUX_SYMBOL_STR(find_next_bit) },
	{ 0x195ef6ba, __VMLINUX_SYMBOL_STR(netif_carrier_off) },
	{ 0x3184dc7b, __VMLINUX_SYMBOL_STR(__dev_kfree_skb_any) },
	{ 0xeae3dfd6, __VMLINUX_SYMBOL_STR(__const_udelay) },
	{ 0xaf79363f, __VMLINUX_SYMBOL_STR(mutex_unlock) },
	{ 0x999e8297, __VMLINUX_SYMBOL_STR(vfree) },
	{ 0xc9fd9053, __VMLINUX_SYMBOL_STR(pci_bus_write_config_word) },
	{ 0xa87cf413, __VMLINUX_SYMBOL_STR(clear_bit) },
	{ 0x91715312, __VMLINUX_SYMBOL_STR(sprintf) },
	{ 0x3a429478, __VMLINUX_SYMBOL_STR(__put_net) },
	{ 0x2e30281b, __VMLINUX_SYMBOL_STR(kthread_create_on_node) },
	{ 0xa9c5c7bf, __VMLINUX_SYMBOL_STR(netif_napi_del) },
	{ 0x7d11c268, __VMLINUX_SYMBOL_STR(jiffies) },
	{ 0x695292dd, __VMLINUX_SYMBOL_STR(down_read) },
	{ 0xe2d5255a, __VMLINUX_SYMBOL_STR(strcmp) },
	{ 0x12793064, __VMLINUX_SYMBOL_STR(kthread_bind) },
	{ 0x33580f3a, __VMLINUX_SYMBOL_STR(__netdev_alloc_skb) },
	{ 0xacc5b5d2, __VMLINUX_SYMBOL_STR(csum_ipv6_magic) },
	{ 0x2afa1786, __VMLINUX_SYMBOL_STR(__pskb_pull_tail) },
	{ 0xab40cca9, __VMLINUX_SYMBOL_STR(__init_waitqueue_head) },
	{ 0x567ba27, __VMLINUX_SYMBOL_STR(param_ops_charp) },
	{ 0x9a9e87f0, __VMLINUX_SYMBOL_STR(netif_schedule_queue) },
	{ 0x39b13e, __VMLINUX_SYMBOL_STR(misc_register) },
	{ 0x706d051c, __VMLINUX_SYMBOL_STR(del_timer_sync) },
	{ 0xd3259d65, __VMLINUX_SYMBOL_STR(test_and_set_bit) },
	{ 0xdcb764ad, __VMLINUX_SYMBOL_STR(memset) },
	{ 0x92ddac5, __VMLINUX_SYMBOL_STR(netif_rx_ni) },
	{ 0x55d738c6, __VMLINUX_SYMBOL_STR(unregister_pernet_subsys) },
	{ 0x4d96141b, __VMLINUX_SYMBOL_STR(netif_tx_wake_queue) },
	{ 0xd6769c48, __VMLINUX_SYMBOL_STR(netif_tx_stop_all_queues) },
	{ 0x8443544d, __VMLINUX_SYMBOL_STR(xen_dma_ops) },
	{ 0x866893c0, __VMLINUX_SYMBOL_STR(dev_err) },
	{ 0x87c44e0c, __VMLINUX_SYMBOL_STR(__mutex_init) },
	{ 0x27e1a049, __VMLINUX_SYMBOL_STR(printk) },
	{ 0x6d52a4ee, __VMLINUX_SYMBOL_STR(ethtool_op_get_link) },
	{ 0xd9705ffb, __VMLINUX_SYMBOL_STR(kthread_stop) },
	{ 0x449ad0a7, __VMLINUX_SYMBOL_STR(memcmp) },
	{ 0xd48fdeef, __VMLINUX_SYMBOL_STR(dql_completed) },
	{ 0xcd279169, __VMLINUX_SYMBOL_STR(nla_find) },
	{ 0x70f49738, __VMLINUX_SYMBOL_STR(free_netdev) },
	{ 0x9166fada, __VMLINUX_SYMBOL_STR(strncpy) },
	{ 0xe3e48c52, __VMLINUX_SYMBOL_STR(register_netdev) },
	{ 0xf8e398fc, __VMLINUX_SYMBOL_STR(memstart_addr) },
	{ 0x5a921311, __VMLINUX_SYMBOL_STR(strncmp) },
	{ 0x5792f848, __VMLINUX_SYMBOL_STR(strlcpy) },
	{ 0x5a73e482, __VMLINUX_SYMBOL_STR(skb_push) },
	{ 0xf312a1e3, __VMLINUX_SYMBOL_STR(mutex_lock) },
	{ 0x2e42f399, __VMLINUX_SYMBOL_STR(dev_close) },
	{ 0xfdaecf96, __VMLINUX_SYMBOL_STR(netif_set_real_num_rx_queues) },
	{ 0x16e5c2a, __VMLINUX_SYMBOL_STR(mod_timer) },
	{ 0xace2708f, __VMLINUX_SYMBOL_STR(netif_set_real_num_tx_queues) },
	{ 0x455e2d05, __VMLINUX_SYMBOL_STR(netif_napi_add) },
	{ 0x9dcb4f34, __VMLINUX_SYMBOL_STR(dma_release_from_coherent) },
	{ 0x2072ee9b, __VMLINUX_SYMBOL_STR(request_threaded_irq) },
	{ 0xe081085b, __VMLINUX_SYMBOL_STR(skb_pull) },
	{ 0x2724ba66, __VMLINUX_SYMBOL_STR(__ioremap) },
	{ 0xafddde76, __VMLINUX_SYMBOL_STR(up_write) },
	{ 0x1ea26579, __VMLINUX_SYMBOL_STR(down_write) },
	{ 0x794d0748, __VMLINUX_SYMBOL_STR(__get_page_tail) },
	{ 0x9f46ced8, __VMLINUX_SYMBOL_STR(__sw_hweight64) },
	{ 0x98650d39, __VMLINUX_SYMBOL_STR(dma_alloc_from_coherent) },
	{ 0x85343299, __VMLINUX_SYMBOL_STR(dev_open) },
	{ 0xe523ad75, __VMLINUX_SYMBOL_STR(synchronize_irq) },
	{ 0x27bad2ed, __VMLINUX_SYMBOL_STR(pci_find_capability) },
	{ 0x8cc1a227, __VMLINUX_SYMBOL_STR(device_create_file) },
	{ 0xc6cbbc89, __VMLINUX_SYMBOL_STR(capable) },
	{ 0x7ec5aeb9, __VMLINUX_SYMBOL_STR(napi_gro_receive) },
	{ 0xf5a5e6ed, __VMLINUX_SYMBOL_STR(_dev_info) },
	{ 0x40a9b349, __VMLINUX_SYMBOL_STR(vzalloc) },
	{ 0x1592756e, __VMLINUX_SYMBOL_STR(__free_pages) },
	{ 0x618911fc, __VMLINUX_SYMBOL_STR(numa_node) },
	{ 0x8853c249, __VMLINUX_SYMBOL_STR(__alloc_skb) },
	{ 0x12a38747, __VMLINUX_SYMBOL_STR(usleep_range) },
	{ 0x64d2b576, __VMLINUX_SYMBOL_STR(pci_bus_read_config_word) },
	{ 0xd0c38e2c, __VMLINUX_SYMBOL_STR(__napi_schedule) },
	{ 0x4e9dffb5, __VMLINUX_SYMBOL_STR(ip_fast_csum) },
	{ 0xdb7305a1, __VMLINUX_SYMBOL_STR(__stack_chk_fail) },
	{ 0xb2e55898, __VMLINUX_SYMBOL_STR(cpu_possible_mask) },
	{ 0xd62c833f, __VMLINUX_SYMBOL_STR(schedule_timeout) },
	{ 0xaff6d89a, __VMLINUX_SYMBOL_STR(kfree_skb) },
	{ 0xae4a1bda, __VMLINUX_SYMBOL_STR(csum_tcpudp_nofold) },
	{ 0xae0cf102, __VMLINUX_SYMBOL_STR(alloc_netdev_mqs) },
	{ 0xb4f9f74, __VMLINUX_SYMBOL_STR(napi_complete_done) },
	{ 0xf337fe0b, __VMLINUX_SYMBOL_STR(eth_type_trans) },
	{ 0x7f24de73, __VMLINUX_SYMBOL_STR(jiffies_to_usecs) },
	{ 0xcf836a74, __VMLINUX_SYMBOL_STR(wake_up_process) },
	{ 0x67c0818f, __VMLINUX_SYMBOL_STR(register_pernet_subsys) },
	{ 0x83488271, __VMLINUX_SYMBOL_STR(pskb_expand_head) },
	{ 0xc72d6ceb, __VMLINUX_SYMBOL_STR(netdev_err) },
	{ 0xee215cef, __VMLINUX_SYMBOL_STR(pci_enable_msi_range) },
	{ 0x1d3f0ffe, __VMLINUX_SYMBOL_STR(ether_setup) },
	{ 0xcc5005fe, __VMLINUX_SYMBOL_STR(msleep_interruptible) },
	{ 0x315b022d, __VMLINUX_SYMBOL_STR(kmem_cache_alloc_trace) },
	{ 0xd9cbeadf, __VMLINUX_SYMBOL_STR(dummy_dma_ops) },
	{ 0x65345022, __VMLINUX_SYMBOL_STR(__wake_up) },
	{ 0xf6ebc03b, __VMLINUX_SYMBOL_STR(net_ratelimit) },
	{ 0xb3f7646e, __VMLINUX_SYMBOL_STR(kthread_should_stop) },
	{ 0xc992058c, __VMLINUX_SYMBOL_STR(netdev_warn) },
	{ 0xcb128141, __VMLINUX_SYMBOL_STR(prepare_to_wait_event) },
	{ 0xb078792, __VMLINUX_SYMBOL_STR(eth_validate_addr) },
	{ 0x9c55cec, __VMLINUX_SYMBOL_STR(schedule_timeout_interruptible) },
	{ 0x37a0cba, __VMLINUX_SYMBOL_STR(kfree) },
	{ 0x4829a47e, __VMLINUX_SYMBOL_STR(memcpy) },
	{ 0xb630ed30, __VMLINUX_SYMBOL_STR(___pskb_trim) },
	{ 0x7894c976, __VMLINUX_SYMBOL_STR(param_array_ops) },
	{ 0x55b48cbc, __VMLINUX_SYMBOL_STR(pci_disable_msi) },
	{ 0x731dba7a, __VMLINUX_SYMBOL_STR(xen_domain_type) },
	{ 0xae8c4d0c, __VMLINUX_SYMBOL_STR(set_bit) },
	{ 0x708501c9, __VMLINUX_SYMBOL_STR(skb_add_rx_frag) },
	{ 0x71e61270, __VMLINUX_SYMBOL_STR(put_page) },
	{ 0x45a55ec8, __VMLINUX_SYMBOL_STR(__iounmap) },
	{ 0xba94354f, __VMLINUX_SYMBOL_STR(pci_get_device) },
	{ 0x9c5bc552, __VMLINUX_SYMBOL_STR(finish_wait) },
	{ 0x27cfcca7, __VMLINUX_SYMBOL_STR(dev_warn) },
	{ 0xa2a47e45, __VMLINUX_SYMBOL_STR(unregister_netdev) },
	{ 0x745fd844, __VMLINUX_SYMBOL_STR(ndo_dflt_bridge_getlink) },
	{ 0xc3384fed, __VMLINUX_SYMBOL_STR(pci_dev_put) },
	{ 0xb072047e, __VMLINUX_SYMBOL_STR(netif_wake_subqueue) },
	{ 0x8f678b07, __VMLINUX_SYMBOL_STR(__stack_chk_guard) },
	{ 0x2e0d2f7f, __VMLINUX_SYMBOL_STR(queue_work_on) },
	{ 0x3952d339, __VMLINUX_SYMBOL_STR(pci_vfs_assigned) },
	{ 0x9e0c711d, __VMLINUX_SYMBOL_STR(vzalloc_node) },
	{ 0x28318305, __VMLINUX_SYMBOL_STR(snprintf) },
	{ 0xae606cbe, __VMLINUX_SYMBOL_STR(consume_skb) },
	{ 0x27c497d1, __VMLINUX_SYMBOL_STR(pci_enable_device_mem) },
	{ 0xe09a27bf, __VMLINUX_SYMBOL_STR(skb_tstamp_tx) },
	{ 0xf45305cf, __VMLINUX_SYMBOL_STR(skb_put) },
	{ 0xe827b03f, __VMLINUX_SYMBOL_STR(hwmon_device_register) },
	{ 0xac508627, __VMLINUX_SYMBOL_STR(misc_deregister) },
	{ 0xdf1fa5fc, __VMLINUX_SYMBOL_STR(__init_rwsem) },
	{ 0x9e7d6bd0, __VMLINUX_SYMBOL_STR(__udelay) },
	{ 0xc79b977e, __VMLINUX_SYMBOL_STR(device_set_wakeup_enable) },
	{ 0xf20dabd8, __VMLINUX_SYMBOL_STR(free_irq) },
	{ 0xbd11135f, __VMLINUX_SYMBOL_STR(pci_save_state) },
	{ 0xce4be0fd, __VMLINUX_SYMBOL_STR(alloc_etherdev_mqs) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "7CEA35F1F1A1967546FCD95");
