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
	{ 0x6f5b2f3c, __VMLINUX_SYMBOL_STR(platform_driver_unregister) },
	{ 0x444894b0, __VMLINUX_SYMBOL_STR(__platform_driver_register) },
	{ 0x684a84d, __VMLINUX_SYMBOL_STR(phy_attach_direct) },
	{ 0xdcb764ad, __VMLINUX_SYMBOL_STR(memset) },
	{ 0xbe08b37a, __VMLINUX_SYMBOL_STR(__dynamic_dev_dbg) },
	{ 0xe3e48c52, __VMLINUX_SYMBOL_STR(register_netdev) },
	{ 0xfbc824b6, __VMLINUX_SYMBOL_STR(put_device) },
	{ 0xa25d2547, __VMLINUX_SYMBOL_STR(phy_connect_direct) },
	{ 0xc919abf4, __VMLINUX_SYMBOL_STR(__uio_register_device) },
	{ 0xce4be0fd, __VMLINUX_SYMBOL_STR(alloc_etherdev_mqs) },
	{ 0xc34cc567, __VMLINUX_SYMBOL_STR(hnae_get_handle) },
	{ 0x866893c0, __VMLINUX_SYMBOL_STR(dev_err) },
	{ 0x2627d1c8, __VMLINUX_SYMBOL_STR(device_property_read_u32_array) },
	{ 0xd5645d69, __VMLINUX_SYMBOL_STR(acpi_node_get_property_reference) },
	{ 0xa2a47e45, __VMLINUX_SYMBOL_STR(unregister_netdev) },
	{ 0x69f5e730, __VMLINUX_SYMBOL_STR(uio_unregister_device) },
	{ 0x70f49738, __VMLINUX_SYMBOL_STR(free_netdev) },
	{ 0x420aa57f, __VMLINUX_SYMBOL_STR(phy_disconnect) },
	{ 0x3c3b3bdf, __VMLINUX_SYMBOL_STR(module_put) },
	{ 0x97fdbab9, __VMLINUX_SYMBOL_STR(_raw_spin_unlock_irqrestore) },
	{ 0x96220280, __VMLINUX_SYMBOL_STR(_raw_spin_lock_irqsave) },
	{ 0xf8e398fc, __VMLINUX_SYMBOL_STR(memstart_addr) },
	{ 0xd2b09ce5, __VMLINUX_SYMBOL_STR(__kmalloc) },
	{ 0x8443544d, __VMLINUX_SYMBOL_STR(xen_dma_ops) },
	{ 0x18fef9cb, __VMLINUX_SYMBOL_STR(xen_start_info) },
	{ 0x731dba7a, __VMLINUX_SYMBOL_STR(xen_domain_type) },
	{ 0xd9cbeadf, __VMLINUX_SYMBOL_STR(dummy_dma_ops) },
	{ 0x37a0cba, __VMLINUX_SYMBOL_STR(kfree) },
	{ 0x39818de9, __VMLINUX_SYMBOL_STR(device_destroy) },
	{ 0x33a5fe01, __VMLINUX_SYMBOL_STR(iommu_map) },
	{ 0x94117ad8, __VMLINUX_SYMBOL_STR(iommu_attach_device) },
	{ 0x4c40a246, __VMLINUX_SYMBOL_STR(iommu_domain_alloc) },
	{ 0x361c2a17, __VMLINUX_SYMBOL_STR(kmalloc_caches) },
	{ 0x79aa04a2, __VMLINUX_SYMBOL_STR(get_random_bytes) },
	{ 0x315b022d, __VMLINUX_SYMBOL_STR(kmem_cache_alloc_trace) },
	{ 0x98082893, __VMLINUX_SYMBOL_STR(__copy_to_user) },
	{ 0x3a5801b4, __VMLINUX_SYMBOL_STR(device_get_mac_address) },
	{ 0x17a142df, __VMLINUX_SYMBOL_STR(__copy_from_user) },
	{ 0x8f678b07, __VMLINUX_SYMBOL_STR(__stack_chk_guard) },
	{ 0xdb7305a1, __VMLINUX_SYMBOL_STR(__stack_chk_fail) },
	{ 0xc72d6ceb, __VMLINUX_SYMBOL_STR(netdev_err) },
	{ 0x5433890c, __VMLINUX_SYMBOL_STR(dev_get_stats) },
	{ 0x60b6221e, __VMLINUX_SYMBOL_STR(class_destroy) },
	{ 0x6bc3fbc0, __VMLINUX_SYMBOL_STR(__unregister_chrdev) },
	{ 0x9f45be4, __VMLINUX_SYMBOL_STR(device_create) },
	{ 0xeaf043dd, __VMLINUX_SYMBOL_STR(__class_create) },
	{ 0x6393dc27, __VMLINUX_SYMBOL_STR(__register_chrdev) },
	{ 0x5178a3c7, __VMLINUX_SYMBOL_STR(mdio_bus_type) },
	{ 0x4377d72d, __VMLINUX_SYMBOL_STR(bus_find_device) },
	{ 0xdd329fd, __VMLINUX_SYMBOL_STR(uio_event_notify) },
	{ 0x27e1a049, __VMLINUX_SYMBOL_STR(printk) },
	{ 0x9166fada, __VMLINUX_SYMBOL_STR(strncpy) },
	{ 0x1fdc7df2, __VMLINUX_SYMBOL_STR(_mcount) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=uio";

MODULE_ALIAS("acpi*:HISI00C1:*");
MODULE_ALIAS("acpi*:HISI00C2:*");

MODULE_INFO(srcversion, "E9F3A3FCE81336CE69872B9");
