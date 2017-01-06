
#define pr_fmt(fmt) KBUILD_MODNAME ": " fmt

#include <linux/device.h>
#include <linux/module.h>
#include <linux/pci.h>
#include <linux/platform_device.h>
#include <linux/uio_driver.h>
#include <linux/io.h>
#include <linux/version.h>
#include <linux/slab.h>


#include "compat.h"

struct rte_uio_plf_dev {
	struct uio_info info;
	struct platform_device *pdev;
};


/**
 * Template to r/w something
 */
static ssize_t
show_something(struct device *dev, struct device_attribute *attr,
                 char *buf)
{
    return snprintf(buf, 10, "%u\n", dev_num_vf(dev));
}

static ssize_t
store_something(struct device *dev, struct device_attribute *attr,
                  const char *buf, size_t count)
{
    int err = 0;

    return err ? err : count;
}

static DEVICE_ATTR(max_vfs, S_IRUGO | S_IWUSR, show_something, store_something);

static struct attribute *dev_attrs[] = {
    &dev_attr_something.attr,
    NULL,
};

static const struct attribute_group dev_attr_grp = {
    .attrs = dev_attrs,
};

static int plf_uio_probe(struct platform_device *pdev)
{
   struct rte_uio_plf_dev *udev;
   int err;

   udev = kzalloc(sizeof(struct rte_uio_plf_dev),GFP_KERNEL);
   if(!udev)
       return -ENOMEM;

   udev->info.name = "plf_uio";
   udev->info.version = "0.1";
   udev->info.handler = plf_uio_irqhandler;
   udev->info.irqcontrol = plf_uio_irqcontrol;

   udev->info.priv = udev;
   udev->pdev = dev;

   err = sysfs_create_group(&dev->dev.kobj, &dev_attr_grp);
   if (err != 0)
       goto fail_free;

   err = uio_register_device(&dev->dev, &udev->info);
   if(err != 0)
       goto fail_remove_group;

   platform_set_drvdata(dev,udev);
   return 0;

fail_remove_group:
   sysfs_remove_group(&dev->dev.kobj, &dev_attr_grp);
fail_free:
   kfree(udev);
   return err;
}

static void
plf_uio_remove(struct platform_device *dev)
{
    struct rte_uio_plf_dev *udev = platform_get_drvdata(dev);

    sysfs_remove_group(&dev->dev.kobj, &dev_attr_grp);
    uio_unregister_device(&udev->info);
    platform_set_drvdata(dev,NULL);
    kfree(udev);
}

static struct platform_driver plf_uio_driver = {
    .probe = plf_uio_probe,
    .remove = plf_uio_remove,
}

static int __init
plfuio_plf_init_module(void)
{
    return platform_driver_register(&plf_uio_driver);
}

static void __exit
plfuio_plf_exit_module(void)
{
    platform_driver_unregister(&plf_uio_driver);
}

module_init(pltuio_plf_init_module);
module_exit(pltuio_plf_exit_module);

MODULE_DESCRIPTION("UIO driver for Arm platform");
MODULE_LICENSE("GPL");
MODULE_AUTHOR("LAB 1219");
