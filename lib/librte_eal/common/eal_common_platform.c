
#include <string.h>
#include <inttypes.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/queue.h>
#include <sys/mman.h>
#include <dirent.h>
#include <fcntl.h>

#include <rte_interrupts.h>
#include <rte_log.h>
#include <rte_platform.h>
#include <rte_per_lcore.h>
#include <rte_memory.h>
#include <rte_memzone.h>
#include <rte_eal.h>
#include <rte_string_fns.h>
#include <rte_common.h>
#include <rte_devargs.h>

#include "eal_private.h"

#define FILE_TRUE 1
#define FILE_MAX 256

#define SYSFS_PLATFORM_DEVICES "/sys/bus/platform/devices"

const char *platform_get_sysfs_path(void)
{
	const char *path = NULL;

	path = getenv("SYSFS_PLATFORM_DEVICES");
	if (path == NULL)
		return SYSFS_PLATFORM_DEVICES;

	return path;
}

struct platform_driver_list platform_driver_list;
struct platform_device_list platform_device_list;
//struct platform_data_list platform_data_list;

struct dev_file_info {
    int            flag;
    struct dirent *file;
};

struct dev_file_info dev_file[FILE_MAX];


static struct rte_platform_driver *rte_check_platform_drv_is_reg(char *drv_name)
{
    struct rte_platform_driver *acc_drv;
    int len;

    TAILQ_FOREACH(acc_drv, &platform_driver_list, next)
    {
        if (strlen(drv_name) != strlen(acc_drv->name))
            continue;

        len = strlen(drv_name);
        if(strncmp(drv_name, acc_drv->name, len) == 0)
            return acc_drv;    
    }

    return NULL;
}

void rte_eal_platform_register(struct rte_platform_driver *driver)
{
    if(!driver) {
        RTE_LOG(ERR,EAL,"driver is null!\n");
        return;
    }
    if(!(driver->devinit)) {
        RTE_LOG(ERR,EAL,"dev_init is null\n");
        return;
    }
    if(!(driver->devuninit)) {
        RTE_LOG(ERR,EAL,"dev_uninit is null\n");
        return;
    }
    if(rte_check_platform_drv_is_reg(driver->name)) {
        RTE_LOG(ERR,EAL,"call rte_check_platform_drv_is_reg failed!\n");
        return;
    }

    TAILQ_INSERT_TAIL(&platform_driver_list, driver, next);
}

void rte_eal_platform_unregister(struct rte_platform_driver *driver)
{
//    struct rte_platform_driver *drv_temp;
//    int len;

    if(!driver){
        RTE_LOG(ERR,EAL,"driver is null\n");
        return;
    }
    TAILQ_REMOVE(&platform_driver_list, driver, next);

//    TAILQ_FOREACH (drv_temp, &platform_driver_list, next)
//    {
//        RTE_LOG(ERR,EAL,"%s",drv_temp->name);
//        if (strlen(drv_temp->name) == strlen(driver->name)) {
//            len = strlen(driver->name);
//            if (strncmp(drv_temp->name, driver->name,len) == 0) {
//                TAILQ_REMOVE (&platform_driver_list,drv_temp);
//                return;
//            }
//        }
//    }  
//    RTE_LOG(ERR,EAL,"dev is not found!\n");

}

void *
platform_map_resource(void *requested_addr, int fd, off_t offset, size_t size,
        int additional_flags)
{
    void *mapaddr;

    mapaddr = mmap(requested_addr, size, PROT_READ | PROT_WRITE,
            MAP_SHARED | additional_flags, fd, offset);
    if(mapaddr == MAP_FAILED){
     RTE_LOG(ERR, EAL, "%s(): cannot mmap(%d, %p, 0x%lx, 0x%lx): %s (%p)\n",
               __func__, fd, requested_addr,
              (unsigned long)size, (unsigned long)offset,
               strerror(errno), mapaddr);
    } else
        RTE_LOG(DEBUG, EAL, "  Platform memory mapped at %p\n", mapaddr);
    
    return mapaddr;
}

void
platform_unmap_resource(void *requested_addr, size_t size)
{
    if (requested_addr == NULL)
        return;

    /* Unmap the Platform memory resource of device */
    if (munmap(requested_addr, size)) {
        RTE_LOG(ERR, EAL, "%s(): cannot munmap(%p, 0x%lx): %s\n",
            __func__, requested_addr, (unsigned long)size,
            strerror(errno));
     } else
         RTE_LOG(DEBUG, EAL, "  Platform memory unmapped at %p\n",
              requested_addr);
}

/*
struct rte_platform_data *rte_platform_check_name_is_alloc(char *name)
{
    struct rte_platform_data *uio_data;
    int len;

    TAILQ_FOREACH(uio_data, &platform_data_list,next)
    {
        if(strlen(name) != strlen(uio_data->name))
            continue;

        len = strlen(name);
        if(strncmp(name, uio_data->name, len) == 0)
            return uio_data;
    }

    return NULL;
}


void *rte_eal_platform_data_alloc(char *name, uint32_t len)
{
    struct rte_platform_data *uio_data;

    if(!name){
        RTE_LOG(ERR,EAL,"name is null!\n");
        return NULL;
    }
    if(len == 0){
        RTE_LOG(ERR,EAL,"invalid len = %u!\n",len);
        return NULL;
    }
    if(rte_platform_check_name_is_alloc(name)){
        RTE_LOG(ERR,EAL,"name: %s, has been allocated!\n", name);
        return NULL;
    }
    uio_data = (struct rte_platform_data *)malloc(len + sizeof(struct rte_platform_data));
    
    if(!uio_data){
        RTE_LOG(ERR,EAL,"call malloc failed!\n");
        return NULL;
    }
    
    memset((void *)uio_data,0,len+sizeof(struct rte_platform_data));
    uio_data->name = malloc(strlen(name)+1);
    strncpy(uio_data->name,name,strlen(name));
    uio_data->data = (void *)((uint8_t *)uio_data + sizeof(struct rte_platform_data));
    
    TAILQ_INSERT_TAIL(&platform_data_list, uio_data, next);
    return uio_data->data;
}

void rte_eal_platform_data_free(char *name)
{
    struct rte_platform_data *uio_data_temp; 

    if(!name){
        RTE_LOG(ERR,EAL,"name is null!\n");
        return;
    }

    TAILQ_FOREACH(uio_data_temp,&platform_data_list,next){
        if(strlen(uio_dta_temp->name) == strlen(name)){
            if(strncmp(uio_data_temp->name,name,strlen(name))==0){
                free(uio_data_temp->name);
                free((void *)((uint8_t *)uio_data_temp->data - sizeof(struct rte_platform_data)));
                TAILQ_REMOVE(&platform_data_list,uio_data_temp,next);
                return;
            }
        }
    }
    RTE_LOG(ERR,EAL,"name: %s not found!\n",name);
}
*/
/*
 * If name match, call the devinit() function of the
 * driver.
 */
static int
rte_eal_platform_probe_one_driver(struct rte_platform_driver *dr, struct rte_platform_device *dev)
{
	int ret;
    unsigned int len;
    const struct rte_platform_id *id;
	for (id = dr->id_table; id != NULL; id++) {

		/* check if device's identifiers match the driver's ones */
        len = strlen(id->name);
        if(len != strlen(dev->name) ||
                strncmp(id->name, dev->name, len)) 
            continue;

		if (dr->drv_flags & RTE_PCI_DRV_NEED_MAPPING) {
			/* map resources for devices that use plf_uio */
			ret = rte_eal_platform_map_device(dev);
			if (ret != 0)
				return ret;
		}

		/* reference driver structure */
		dev->driver = dr;

		/* call the driver devinit() function */
		return dr->devinit(dr, dev);
	}
	/* return positive value if driver doesn't support this device */
	return 1;
}
/*
 * If name match, call the devinit() function of all
 * registered driver for the given device. Return -1 if initialization
 * failed, return 1 if no driver is found for this device.
 */
static int
platform_probe_all_drivers(struct rte_platform_device *dev)
{
	struct rte_platform_driver *dr = NULL;
	int rc = 0;

	if (dev == NULL)
		return -1;

	TAILQ_FOREACH(dr, &platform_driver_list, next) {
		rc = rte_eal_platform_probe_one_driver(dr, dev);
		if (rc < 0)
			/* negative value is an error */
			return -1;
		if (rc > 0)
			/* positive value means driver doesn't support it */
			continue;
		return 0;
	}
	return 1;
}


/*
 * Scan the content of the Platform vbus, and call the devinit() function for
 * all registered drivers that have a matching entry in its id_table
 * for discovered devices.
 */
int
rte_eal_platform_probe(void)
{
	struct rte_platform_device *dev = NULL;
	int ret = 0;

	TAILQ_FOREACH(dev, &platform_device_list, next) {
		ret = platform_probe_all_drivers(dev);
		if (ret < 0)
			rte_exit(EXIT_FAILURE, "Requested device %s" 
				 " cannot be used\n", dev->name);
	}

	return 0;
}


