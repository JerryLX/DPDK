/**
 * Like eal_pci_uio.c. 
 * Alloc UIO resource for platform device.
 *
 * @author lixu
 */
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <inttypes.h>
#include <sys/stat.h>
#include <sys/mman.h>


#include <rte_log.h>
#include <rte_platform.h>
#include <rte_eal_memconfig.h>
#include <rte_common.h>
#include <rte_malloc.h>

#include "eal_platform_init.h"
#include "eal_filesystem.h"

void *platform_map_addr = NULL;

static int
platform_mknod_uio_dev(const char *sysfs_uio_path, unsigned uio_num)
{
	FILE *f;
	char filename[PATH_MAX];
	int ret;
	unsigned major, minor;
	dev_t dev;

	/* get the name of the sysfs file that contains the major and minor
	 * of the uio device and read its content */
	snprintf(filename, sizeof(filename), "%s/dev", sysfs_uio_path);

	f = fopen(filename, "r");
	if (f == NULL) {
		RTE_LOG(ERR, EAL, "%s(): cannot open sysfs to get major:minor\n",
			__func__);
		return -1;
	}

	ret = fscanf(f, "%u:%u", &major, &minor);
	if (ret != 2) {
		RTE_LOG(ERR, EAL, "%s(): cannot parse sysfs to get major:minor\n",
			__func__);
		fclose(f);
		return -1;
	}
	fclose(f);

	/* create the char device "mknod /dev/uioX c major minor" */
	snprintf(filename, sizeof(filename), "/dev/uio%u", uio_num);
	dev = makedev(major, minor);
	ret = mknod(filename, S_IFCHR | S_IRUSR | S_IWUSR, dev);
	if (f == NULL) {
		RTE_LOG(ERR, EAL, "%s(): mknod() failed %s\n",
			__func__, strerror(errno));
		return -1;
	}

	return ret;
}

/*
 * Return the uioX char device used for a platform device.
 * On success, return the UIO number.
 */
static int
platform_get_uio_dev(struct rte_platform_device *dev, char *dstbuf,
        unsigned int buflen, int create)
{
    unsigned int uio_num;
    struct dirent *e;
    DIR *dir;
    char dirname[PATH_MAX];

    snprintf(dirname, sizeof(dirname),
            "%s/%s/uio",platform_get_sysfs_path(),
            dev->name);

    /* need to fullfill */
	dir = opendir(dirname);
	if (dir == NULL) {
		/* retry with the parent directory */
		snprintf(dirname, sizeof(dirname),
				"%s/%s", platform_get_sysfs_path(),
				dev->name);
		dir = opendir(dirname);

		if (dir == NULL) {
			RTE_LOG(ERR, EAL, "Cannot opendir %s\n", dirname);
			return -1;
		}
	}

	/* take the first file starting with "uio" */
	while ((e = readdir(dir)) != NULL) {
		/* format could be uio%d ...*/
		int shortprefix_len = sizeof("uio") - 1;
		/* ... or uio:uio%d */
		int longprefix_len = sizeof("uio:uio") - 1;
		char *endptr;

		if (strncmp(e->d_name, "uio", 3) != 0)
			continue;

		/* first try uio%d */
		errno = 0;
		uio_num = strtoull(e->d_name + shortprefix_len, &endptr, 10);
		if (errno == 0 && endptr != (e->d_name + shortprefix_len)) {
			snprintf(dstbuf, buflen, "%s/uio%u", dirname, uio_num);
			break;
		}

		/* then try uio:uio%d */
		errno = 0;
		uio_num = strtoull(e->d_name + longprefix_len, &endptr, 10);
		if (errno == 0 && endptr != (e->d_name + longprefix_len)) {
			snprintf(dstbuf, buflen, "%s/uio:uio%u", dirname, uio_num);
			break;
		}
	}
	closedir(dir);

	/* No uio resource found */
	if (e == NULL)
		return -1;

	/* create uio device if we've been asked to */
	if (internal_config.create_uio_dev && create &&
			platform_mknod_uio_dev(dstbuf, uio_num) < 0)
		RTE_LOG(WARNING, EAL, "Cannot create /dev/uio%u\n", uio_num);

    return uio_num;
}

/*
 * Free uio resource for platform device.
 */
void
platform_uio_free_resource(struct rte_platform_device *dev,
        struct mapped_platform_resource *uio_res)
{
    rte_free(uio_res);
/*
    if(dev->intr_handle.uio_cfg_fd >= 0) {
        close(dev->intr_handle.uio_cfg_fd);
        dev->intr_handle.uio_cfg_fd = -1;
    }
*/
	if (dev->intr_handle.fd) {
		close(dev->intr_handle.fd);
		dev->intr_handle.fd = -1;
		dev->intr_handle.type = RTE_INTR_HANDLE_UNKNOWN;
	} 
}

/*
 * Alloc uio resource for platform device.
 */
int
platform_uio_alloc_resource(struct rte_platform_device *dev,
        struct mapped_platform_resource **uio_res)
{
    char dirname[PATH_MAX];
//    char cfgname[PATH_MAX];
    char devname[PATH_MAX]; /* contains the /dev/uioX */
    int uio_num;
    
    /* find uio resource */
    uio_num = platform_get_uio_dev(dev, dirname, sizeof(dirname), 1);
    if(uio_num < 0){
        RTE_LOG(WARNING, EAL, "platform dev %s not managed by UIO driver, "
                "skipping\n", dev->name);
        return 1;
    }
    snprintf(devname, sizeof(devname), "/dev/uio%u", uio_num);

    /* save fd if in primary process */
    dev->intr_handle.fd = open(devname, O_RDWR);
    if (dev->intr_handle.fd < 0){
        RTE_LOG(ERR, EAL, "Cannot open %s\n",devname);
        goto error;
    }

    /* platform device has no config */
    /*
    snprintf(cfgname, sizeof(cfgname),
        "/sys/class/uio/uio%u/device/config", uio_num);
    dev->intr_handle.uio_cfg_fd = open(cfgname, O_RDWR);
    if(dev->intr_handle.uio_cfg_fd < 0){
        RTE_LOG(ERR, EAL, "Cannot open %s\n", cfgname);
        goto error;
    }
    */

    if (dev->kdrv == RTE_KDRV_PLF_UIO)
        dev->intr_handle.type = RTE_INTR_HANDLE_UIO;
    else{
        RTE_LOG(ERR, EAL, "not implement yet\n");
        goto error;
    }

    /* allocate the mapping details for secondary processes */
    *uio_res = rte_zmalloc("UIO_RES", sizeof(**uio_res), 0);
    if(*uio_res == NULL){
        RTE_LOG(ERR, EAL,
                "%s(): cannot store uio map details\n", __func__);
        goto error;
    }

    snprintf((*uio_res)->path, sizeof((*uio_res)->path), "%s", devname);
    memcpy(&(*uio_res)->name, &dev->name, sizeof((*uio_res)->name));


    return 0;
error:
    platform_uio_free_resource(dev, *uio_res);
    return -1;
}
