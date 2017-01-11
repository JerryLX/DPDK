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
	{ 0x731dba7a, __VMLINUX_SYMBOL_STR(xen_domain_type) },
	{ 0x8443544d, __VMLINUX_SYMBOL_STR(xen_dma_ops) },
	{ 0x18fef9cb, __VMLINUX_SYMBOL_STR(xen_start_info) },
	{ 0x361c2a17, __VMLINUX_SYMBOL_STR(kmalloc_caches) },
	{ 0xd9cbeadf, __VMLINUX_SYMBOL_STR(dummy_dma_ops) },
	{ 0x8f678b07, __VMLINUX_SYMBOL_STR(__stack_chk_guard) },
	{ 0x2724ba66, __VMLINUX_SYMBOL_STR(__ioremap) },
	{ 0xc919abf4, __VMLINUX_SYMBOL_STR(__uio_register_device) },
	{ 0x866893c0, __VMLINUX_SYMBOL_STR(dev_err) },
	{ 0xdb7305a1, __VMLINUX_SYMBOL_STR(__stack_chk_fail) },
	{ 0x45a55ec8, __VMLINUX_SYMBOL_STR(__iounmap) },
	{ 0x76c75c4f, __VMLINUX_SYMBOL_STR(sysfs_create_group) },
	{ 0x2627d1c8, __VMLINUX_SYMBOL_STR(device_property_read_u32_array) },
	{ 0x315b022d, __VMLINUX_SYMBOL_STR(kmem_cache_alloc_trace) },
	{ 0x27e1a049, __VMLINUX_SYMBOL_STR(printk) },
	{ 0x37a0cba, __VMLINUX_SYMBOL_STR(kfree) },
	{ 0x69f5e730, __VMLINUX_SYMBOL_STR(uio_unregister_device) },
	{ 0xa8ee7e1, __VMLINUX_SYMBOL_STR(sysfs_remove_group) },
	{ 0x1fdc7df2, __VMLINUX_SYMBOL_STR(_mcount) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=uio";

MODULE_ALIAS("of:N*T*Chisilicon,hns-nic-v1*");
MODULE_ALIAS("of:N*T*Chisilicon,hns-nic-v2*");
MODULE_ALIAS("acpi*:HISI00C1:*");
MODULE_ALIAS("acpi*:HISI00C2:*");

MODULE_INFO(srcversion, "D20F827C8FBB512B656FBC5");
