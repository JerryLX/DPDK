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
	{ 0x567ba27, __VMLINUX_SYMBOL_STR(param_ops_charp) },
	{ 0x5d7c7856, __VMLINUX_SYMBOL_STR(pci_unregister_driver) },
	{ 0xf68fe41, __VMLINUX_SYMBOL_STR(__pci_register_driver) },
	{ 0xe2d5255a, __VMLINUX_SYMBOL_STR(strcmp) },
	{ 0x27e1a049, __VMLINUX_SYMBOL_STR(printk) },
	{ 0x731dba7a, __VMLINUX_SYMBOL_STR(xen_domain_type) },
	{ 0x8443544d, __VMLINUX_SYMBOL_STR(xen_dma_ops) },
	{ 0x18fef9cb, __VMLINUX_SYMBOL_STR(xen_start_info) },
	{ 0x361c2a17, __VMLINUX_SYMBOL_STR(kmalloc_caches) },
	{ 0xd9cbeadf, __VMLINUX_SYMBOL_STR(dummy_dma_ops) },
	{ 0xbe08b37a, __VMLINUX_SYMBOL_STR(__dynamic_dev_dbg) },
	{ 0xf5a5e6ed, __VMLINUX_SYMBOL_STR(_dev_info) },
	{ 0xc919abf4, __VMLINUX_SYMBOL_STR(__uio_register_device) },
	{ 0x76c75c4f, __VMLINUX_SYMBOL_STR(sysfs_create_group) },
	{ 0x562b21d, __VMLINUX_SYMBOL_STR(dev_notice) },
	{ 0xdd9df43d, __VMLINUX_SYMBOL_STR(pci_intx_mask_supported) },
	{ 0x1ac13854, __VMLINUX_SYMBOL_STR(pci_enable_msix) },
	{ 0x2724ba66, __VMLINUX_SYMBOL_STR(__ioremap) },
	{ 0x866893c0, __VMLINUX_SYMBOL_STR(dev_err) },
	{ 0x83bc7f28, __VMLINUX_SYMBOL_STR(pci_set_master) },
	{ 0xfaff1c41, __VMLINUX_SYMBOL_STR(pci_enable_device) },
	{ 0x315b022d, __VMLINUX_SYMBOL_STR(kmem_cache_alloc_trace) },
	{ 0x6cbffc9d, __VMLINUX_SYMBOL_STR(pci_check_and_mask_intx) },
	{ 0x478f514, __VMLINUX_SYMBOL_STR(pci_intx) },
	{ 0xb070e55b, __VMLINUX_SYMBOL_STR(pci_cfg_access_unlock) },
	{ 0xd44abef3, __VMLINUX_SYMBOL_STR(pci_cfg_access_lock) },
	{ 0x505d0f99, __VMLINUX_SYMBOL_STR(remap_pfn_range) },
	{ 0x880e2c69, __VMLINUX_SYMBOL_STR(pci_disable_msix) },
	{ 0x37a0cba, __VMLINUX_SYMBOL_STR(kfree) },
	{ 0xe7fe8a07, __VMLINUX_SYMBOL_STR(pci_disable_device) },
	{ 0x69f5e730, __VMLINUX_SYMBOL_STR(uio_unregister_device) },
	{ 0xa8ee7e1, __VMLINUX_SYMBOL_STR(sysfs_remove_group) },
	{ 0x45a55ec8, __VMLINUX_SYMBOL_STR(__iounmap) },
	{ 0xb19a8c14, __VMLINUX_SYMBOL_STR(pci_bus_type) },
	{ 0x28318305, __VMLINUX_SYMBOL_STR(snprintf) },
	{ 0x8f678b07, __VMLINUX_SYMBOL_STR(__stack_chk_guard) },
	{ 0xdb7305a1, __VMLINUX_SYMBOL_STR(__stack_chk_fail) },
	{ 0xbbc4478c, __VMLINUX_SYMBOL_STR(pci_enable_sriov) },
	{ 0x805debed, __VMLINUX_SYMBOL_STR(pci_disable_sriov) },
	{ 0xc4271362, __VMLINUX_SYMBOL_STR(pci_num_vf) },
	{ 0x3c80c06c, __VMLINUX_SYMBOL_STR(kstrtoull) },
	{ 0x1fdc7df2, __VMLINUX_SYMBOL_STR(_mcount) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=uio";


MODULE_INFO(srcversion, "47AE41AD0F20FAA13A85D76");
