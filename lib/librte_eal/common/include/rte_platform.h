
#ifndef _RTE_PLATFORM_H_
#define _RTE_PLATFORM_H_

/**
 * @file
 *
 * RTE Platform Interface
 */

#ifdef __cplusplus
extern "C" {
#endif

#define PAGE_SIZE 4096

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>
#include <sys/queue.h>
#include <stdint.h>
#include <inttypes.h>

#include <rte_interrupts.h>

TAILQ_HEAD(platform_driver_list, rte_platform_driver); /**< Platform drivers in D-linked Q. */
TAILQ_HEAD(platform_device_list, rte_platform_device); /**< Platform devices in D-linked Q. */
TAILQ_HEAD(platform_data_list, rte_platform_data); /**< Platform data in D-linked Q. */

extern struct platform_driver_list platform_driver_list; /**< Global list of Platform drivers. */
extern struct platform_device_list platform_device_list; /**< Global list of Platform devices. */
extern struct platform_data_list  platform_data_list; /**< Global list of Platform data. */
/**
 * A structure describing a Platform UIO resource.
 */
struct rte_platform_resource {
    uint64_t phys_addr;     /**< Physical address, 0 if no resource. */
    uint64_t len;           /**< Length of the resource. */
    void *addr;             /**< Virtual address, NULL when not mapped. */
};

/** Maximum number of platform resources. */
#define PLATFORM_MAX_RESOURCE (6)

/** Maximum length of platform device name. */
#define PLATFORM_NAME_MAX_LEN (32)


/** Calculate offset. */
#define UIO_OFFSET(n) ((n) * PAGE_SIZE)
/**
 * A structure describing a Platform UIO device.
 */
struct rte_platform_device {
    TAILQ_ENTRY(rte_platform_device) next; /**< Next probed UIO device. */

    char *name;      /**< device name. */

    /**< UIO Memory Resource. */
    struct rte_platform_resource mem_resource[PLATFORM_MAX_RESOURCE];
    struct rte_platform_driver  *driver;      /**< Associated driver */
    int                        uio_fd;
    int                        numa_node;   /**< NUMA node connection */
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
 * A structure describing a Platform UIO driver.
 */
struct rte_platform_driver {
    TAILQ_ENTRY(rte_armuio_driver) next;        /**< Next in list. */
    
    char                 *name; /**< Driver name. */
    platform_devinit_t   *dev_init;                  /**< Device init. funcion. */
    platform_devuninit_t *dev_uninit;                /**< Device uninit. function. */

};

/**
 * A structure describing a platform data.
 */
struct rte_platform_data {
    TAILQ_ENTRY(rte_platform_data) next; /**< Next in list. */
    
    char *name;
    void *data;
};

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
void *rte_eal_platform_dev_data_alloc(char *name, uint32_t len);

/**
 * Free device data.
 *
 * @param name
 *   Name of the data to be free.
 *
 * @author lixu
 */
void rte_eal_platform_dev_data_free(char *name);


#ifdef __cplusplus    
}
#endif

#endif /* _RTE_PLATFORM_UIO_H_ */
