
#include <string.h>
#include <dirent.h>

#include <rte_log.h>
#include <rte_platform.h>
#include <rte_eal_memconfig.h>
#include <rte_malloc.h>
#include <rte_devargs.h>
#include <rte_memcpy.h>

#include "eal_filesystem.h"
#include "eal_private.h"
#include "eal_platform_init.h"

static int
platform_get_kernel_driver_by_path(const char *filename, char *dri_name)
{
	int count;
	char path[PATH_MAX];
	char *name;

	if (!filename || !dri_name)
		return -1;

	count = readlink(filename, path, PATH_MAX);
	if (count >= PATH_MAX)
		return -1;

	/* For device does not have a driver */
	if (count < 0){
//		RTE_LOG(INFO, EAL, "there is no driver in %s\n", filename);
        return 1;
    }

	path[count] = '\0';

	name = strrchr(path, '/');
	if (name) {
		strncpy(dri_name, name + 1, strlen(name + 1) + 1);
		return 0;
	}

    return -1;
}

/* 
 * unbind kernel driver for this device 
 * by lixu
 */
int
platform_unbind_kernel_driver(struct rte_platform_device *dev)
{
	int n;
	FILE *f;
	char filename[PATH_MAX];
	char buf[BUFSIZ];
    char *name = dev->name;

	/* open /sys/bus/platform/devices/devname/driver */
	snprintf(filename, sizeof(filename),
		"%s/%s/driver/unbind", platform_get_sysfs_path(),
		name);

	f = fopen(filename, "w");
	if (f == NULL) /* device was not bound */
		return 0;

	n = snprintf(buf, sizeof(buf), "%s\n",
	             name);
	if ((n < 0) || (n >= (int)sizeof(buf))) {
		RTE_LOG(ERR, EAL, "%s(): snprintf failed\n", __func__);
		goto error;
	}
	if (fwrite(buf, n, 1, f) == 0) {
		RTE_LOG(ERR, EAL, "%s(): could not write to %s\n", __func__,
				filename);
		goto error;
	}

	fclose(f);
	return 0;

error:
	fclose(f);
	return -1;
}

/* Map platform device */
int
rte_eal_platform_map_device(struct rte_platform_device *dev)
{
    int ret = -1;

    ret = platform_uio_map_resource(dev);
    return ret;
}

/* Scan one platform sysfs entry, and fill the devices list from it. */
static int
platform_scan_one(const char *dirname, const char *dev_name)
{
	char filename[PATH_MAX];
//	unsigned long tmp;
	struct rte_platform_device *dev;
	char driver[PATH_MAX];
	int ret, len;

	dev = malloc(sizeof(*dev));
	if (dev == NULL)
		return -1;

	memset(dev, 0, sizeof(*dev));

    len = strlen(dev_name)+1;
    dev->name = malloc(len+1);
    memset(dev->name,0,len);
    snprintf(dev->name, len, "%s", dev_name);

	/* parse driver */
	snprintf(filename, sizeof(filename), "%s/driver", dirname);
	ret = platform_get_kernel_driver_by_path(filename, driver);
	if (ret < 0) {
		RTE_LOG(ERR, EAL, "Fail to get kernel driver\n");
		free(dev);
		return -1;
	}
//  RTE_LOG(INFO, EAL, "%s has driver: %s\n", dev_name, driver);

	/* device is valid, add in list (sorted) */
	if (TAILQ_EMPTY(&platform_device_list)) {
		TAILQ_INSERT_TAIL(&platform_device_list, dev, next);
	} else {
		struct rte_platform_device *dev2;
		int ret;

		TAILQ_FOREACH(dev2, &platform_device_list, next) {
			ret = rte_eal_compare_platform_name(dev, dev2);
			if (ret != 0)
				continue;

			else { /* already registered */
//              RTE_LOG(INFO, EAL, "%s already registered, %s\n", dev_name, dev2->name);
				memmove(dev2->mem_resource, dev->mem_resource,
					sizeof(dev->mem_resource));
				free(dev);
			    return 0;
			}
		}
        
		TAILQ_INSERT_TAIL(&platform_device_list, dev, next);
	}

	return 0;
}

void *
platform_find_max_end_va(void)
{
	const struct rte_memseg *seg = rte_eal_get_physmem_layout();
	const struct rte_memseg *last = seg;
	unsigned i = 0;

	for (i = 0; i < RTE_MAX_MEMSEG; i++, seg++) {
		if (seg->addr == NULL)
			break;

		if (seg->addr > last->addr)
			last = seg;

	}
	return RTE_PTR_ADD(last->addr, last->len);
}

/*
 * Scan the content of the platform bus, and the devices in the devices
 * list
 *
 * by lixu
 */
int 
rte_eal_platform_scan(void)
{
	struct dirent *e;
	DIR *dir;
	char dirname[PATH_MAX];
    char devname[PATH_MAX];

	dir = opendir(platform_get_sysfs_path());
	if (dir == NULL) {
		RTE_LOG(ERR, EAL, "%s(): opendir failed: %s\n",
			__func__, strerror(errno));
		return -1;
	}

	while ((e = readdir(dir)) != NULL) {
		if (e->d_name[0] == '.')
			continue;

		snprintf(dirname, sizeof(dirname), "%s/%s",
				platform_get_sysfs_path(), e->d_name);

        snprintf(devname, sizeof(devname), "%s", e->d_name);

        //for debug
//	    RTE_LOG(INFO, EAL, "scanning dir: %s\n", dirname);	
        if (platform_scan_one(dirname, devname) < 0)
			goto error;
	}
	closedir(dir);
	return 0;

error:
    closedir(dir);
    return -1;
}

/* 
 * Init the Platform EAL subsystem 
 *
 * by lixu
 */
int
rte_eal_platform_init(void)
{
    TAILQ_INIT(&platform_driver_list);
    TAILQ_INIT(&platform_device_list);

    /* do something here */
    if (rte_eal_platform_scan() < 0){
        RTE_LOG(ERR, EAL, "%s(): Cannnot scan platform vbus", __func__);
    }

//for debug
//  struct rte_platform_device* dev;
//  if(TAILQ_EMPTY(&platform_device_list)) RTE_LOG(ERR, EAL, "no platform device found!\n");
//  TAILQ_FOREACH(dev, &platform_device_list, next) {
//     RTE_LOG(INFO, EAL,"dev: %s\n", dev->name);
//  }
 
    return 0;
}

