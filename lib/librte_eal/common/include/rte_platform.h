
#ifndef _RTE_PLATFORM_H_
#define _RTE_PLATFORM_H_

/**
 * @file
 *
 * RTE Platform Interface
 * by lixu
 */

#ifdef __cplusplus
extern "C" {
#endif


#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>
#include <sys/queue.h>
#include <stdint.h>
#include <inttypes.h>
#include <string.h>
#include <rte_interrupts.h>
#include <rte_pci_platform.h>


#ifdef __cplusplus
#define RTE_PLATFORM_DEVICE(name) \
        (*name)                   
#else
#define RTE_PLATFORM_DEVICE(name)          \
        .name = (*name)           
#endif


TAILQ_HEAD(platform_driver_list, rte_platform_driver); /**< Platform drivers in D-linked Q. */
TAILQ_HEAD(platform_device_list, rte_platform_device); /**< Platform devices in D-linked Q. */
//TAILQ_HEAD(platform_data_list, rte_platform_data); /**< Platform data in D-linked Q. */

extern struct platform_driver_list platform_driver_list; /**< Global list of Platform drivers. */
extern struct platform_device_list platform_device_list; /**< Global list of Platform devices. */
//extern struct platform_data_list  platform_data_list; /**< Global list of Platform data. */
/**
 * A structure describing a Platform UIO resource.
 */
struct rte_platform_resource {
    uint64_t phys_addr;     /**< Physical address, 0 if no resource. */
    uint64_t len;           /**< Length of the resource. */
    void *addr;             /**< Virtual address, NULL when not mapped. */
};

/** Pathname of Platform devices directory. */
const char *platform_get_sysfs_path(void);

/** Maximum number of platform resources. */
#define PLATFORM_MAX_RESOURCE (6)

/** Maximum length of platform device name. */
#define PLATFORM_NAME_MAX_LEN (32)

/** Calculate offset. */
#define PAGE_SIZE (sysconf(_SC_PAGESIZE))
#define UIO_OFFSET(n) ((n) * PAGE_SIZE)

/**
 * A structure describing a Platform UIO device.
 */
struct rte_platform_device {
    TAILQ_ENTRY(rte_platform_device) next; /**< Next probed UIO device. */

    char *name;      /**< device name. */
    int uio_num;     /**< uio device number */
    /**< UIO Memory Resource. */
    struct rte_platform_resource mem_resource[PLATFORM_MAX_RESOURCE];
    struct rte_platform_driver  *driver;      /**< Associated driver */
    struct rte_intr_handle       intr_handle;
	enum rte_kernel_driver       kdrv;        /**< Kernel driver passthrough */
    int                          uio_fd;
    int                          numa_node;   /**< NUMA node connection */
};

/**
 * Initialisation function for the driver called during platform probing.
 */
typedef int (platform_devinit_t)(struct rte_platform_driver *,struct rte_platform_device *);

/**
 * Uninitialisation function for the driver called during hotplugging.
 */
typedef int (platform_devuninit_t)(struct rte_platform_device *);

/**
 * A structure describing a Platform mapping.
 */
struct platform_map{
    void *addr;
    char *path;
    uint64_t offset;
    uint64_t size;
    uint64_t phaddr;
};

/**
 * A structure describing a mapped Platform resource.
 * For multi-process we need to reproduce all Platform mappings in
 * secondary processes, so save then in a tailq.
 */
struct mapped_platform_resource {
    TAILQ_ENTRY(mapped_platform_resource) next;

    char name[32];
    char path[PATH_MAX];
    int nb_maps;
    struct platform_map maps[PLATFORM_MAX_RESOURCE];
};

/** mapped platform device list */
TAILQ_HEAD(mapped_platform_res_list, mapped_platform_resource);

/**
 * A structure describing an ID for a platform device
 */
struct rte_platform_id {
    const char *name;    
};

/**
 * A structure describing a Platform UIO driver.
 */
struct rte_platform_driver {
    TAILQ_ENTRY(rte_platform_driver) next;        /**< Next in list. */
    
    const char                 *name;                      /**< Driver name. */
    platform_devinit_t   *devinit;                  /**< Device init. funcion. */
    platform_devuninit_t *devuninit;                /**< Device uninit. function. */
	uint32_t drv_flags;                              /**< Flags contolling handling of device. */

    const struct rte_platform_id *id_table;          /**< ID table. */
};
/** Device needs Platform mapping  */
#define RTE_PLATFORM_DRV_NEED_MAPPING 0x0001
/** Device needs to be unbound even if no module is provided */
#define RTE_PLATFORM_DRV_FORCE_UNBIND 0x0004
/** Device driver supports link state interrupt */
#define RTE_PLATFORM_DRV_INTR_LSC	0x0008
/** Device driver supports detaching capability */
#define RTE_PLATFORM_DRV_DETACHABLE	0x0010


/**
 * A structure describing a platform data.
 */
//struct rte_platform_data {
//    TAILQ_ENTRY(rte_platform_data) next; /**< Next in list. */
//    
//    char *name;
//    void *data;
//};


/**
 * Compare two platform device.
 * @return
 *  - 1: not equal.
 *  - 0: equal.
 */
static inline int
rte_eal_compare_name(const char *name1, const char *name2)
{
    int len1 = strlen(name1);
    int len2 = strlen(name2);

    if(len1 != len2) return 1;
    return strncmp(name1,name2,len1);
}

static inline int
rte_eal_compare_platform_name(const struct rte_platform_device* d1, 
        const struct rte_platform_device *d2)
{
    return d1->uio_num - d2->uio_num;
}


/**
 * Scan the content of the Platform vbus, and the devices in the devices
 * list
 *
 * @return
 *  0 on success, negative on error
 */
int rte_eal_platform_scan(void);

/**
 * Map the Platform device resources in user space virtual memory address
 *
 * @param dev
 *   A pointer to a rte_platform_device structure describing the device
 *   to use
 *
 * @return
 *   0 on success, negative on error and positive if no driver
 *   is found for the device.
 */
int rte_eal_platform_map_device(struct rte_platform_device *dev);

/**
 * @internal
 * Map a particular resource from a file.
 *
 * @author lixu
 */
void *platform_map_resource(void *requested_addr, int fd, off_t offset,
        size_t size, int additional_flags);

/**
 * @internal
 * Unmap a particular resource.
 *
 * @author lixu
 */
void platform_unmap_resource(void *requested_addr, size_t size);

/**
 * Probe the platform vbus for registed drivers.
 * 
 * Call the probe() function for all registered drivers.
 *
 * @return 
 *   - 0 on success
 *   - Negative on error.
 * 
 * @author lixu
 */
int rte_eal_platform_probe(void);

/**
 * Register a Platform driver.
 *
 * @param driver
 *   A pointer to a rte_platform_driver structure describing the driver
 *   to be registered.
 *
 * @author lixu
 */
void rte_eal_platform_register(struct rte_platform_driver *driver);

/**
 * Unregister a Platform UIO driver.
 *
 * @param driver
 *   A pointer to a rte_platform_driver structure describing the driver
 *   to be unregistered.
 *
 * @author lixu
 */
void rte_eal_platform_unregister(struct rte_platform_driver *driver);

/**
 * Init Platform UIO device.
 *
 * @author lixu 
 */
//maybe should not put it here
//int rte_eal_armuio_init(void);

/**
 * Alloc device data.
 *
 * @param name
 *   Name of the data.
 * @param len
 *   Length of the data to be allocated.
 *
 * @author lixu
 */
//void *rte_eal_platform_dev_data_alloc(char *name, uint32_t len);

/**
 * Free device data.
 *
 * @param name
 *   Name of the data to be free.
 *
 * @author lixu
 */
//void rte_eal_platform_dev_data_free(char *name);


#ifdef __cplusplus    
}
#endif

#endif /* _RTE_PLATFORM_UIO_H_ */

