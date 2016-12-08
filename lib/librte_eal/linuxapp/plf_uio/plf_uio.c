
#define pr_fmt(fmt) KBUILD_MODNAME ": " fmt

#include <linux/device.h>
#include <linux/module.h>
#include <linux/pci.h>
#include <linux/uio_driver.h>
#include <linux/io.h>
#include <linux/msi.h>
#include <linux/version.h>
#include <linux/slab.h>

#ifdef CONFIG_XEN_DOM0
#include <xen/xen.h>
#endif

#include "compat.h"

struct rte_uio_pci_dev {
	struct uio_info info;
	struct pci_dev *pdev;
	enum rte_intr_mode mode;
};

static int __init
pltuio_plt_init_module(void)
{
}

static void __exit
pltuio_plt_exit_module(void)
{
}

module_init(pltuio_plt_init_module);
module_exit(pltuio_plt_exit_module);

MODULE_DESCRIPTION("UIO driver for Arm platform");
MODULE_LICENSE("GPL");
MODULE_AUTHOR("LAB 1219");
