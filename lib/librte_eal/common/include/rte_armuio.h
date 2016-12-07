
#ifndef _RTE_ARMUIO_H_
#define _RTE_ARMUIO_H_

/**
 * @file
 *
 * RTE ARM UIO Interface
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

TAILQ_HEAD(armuio_driver_list, rte_armuio_driver); /**< ARM UIO drivers in D-linked Q. */
TAILQ_HEAD(armuio_device_list, rte_armuio_device); /**< ARM UIO devices in D-linked Q. */
TAILQ_HEAD(armuio_data_list, rte_armuio_data); /**< ARM UIO data in D-linked Q. */

extern struct armuio_driver_list armuio_driver_list; /**< Global list of ARM UIO drivers. */
extern struct armuio_device_list armuio_device_list; /**< Global list of ARM UIO devices. */
extern struct armuio_data_list armuio_data_list; /**< Global list or ARM UIO data. */
/**
 * A structure describing a ARM UIO resource.
 */
struct rte_armuio_resource {
    uint64_t phys_addr;     /**< Physical address, 0 if no resource. */
    uint64_t len;           /**< Length of the resource. */
    void *addr;             /**< Virtual address, NULL when not mapped. */
};

/** Maximum number of ARM UIO resources. */
#define ARMUIO_MAX_RESOURCE (6)

/** Maximum length of UIO device name. */
#define ARMUIO_NAME_MAX_LEN (32)


/** Calculate offset. */
#define UIO_OFFSET(n) ((n) * PAGE_SIZE)
/**
 * A structure describing a ARM UIO device.
 */
struct rte_armuio_device {
    TAILQ_ENTRY(rte_armuio_device) next; /**< Next probed UIO device. */

    char name[ARMUIO_NAME_MAX_LEN];      /**< device name. */

    /**< UIO Memory Resource. */
    struct rte_armuio_resource mem_resource[ARMUIO_MAX_RESOURCE];
    struct rte_armuio_driver  *driver;      /**< Associated driver */
    int                        uio_fd;
    int                        numa_node;   /**< NUMA node connection */
};

/**
 * Initialisation function for the driver called during ARM UIO probing.
 */
typedef int (armuio_devinit_t)(struct rte_armuio_driver *,struct rte_armuio_device *);

/**
 * Uninitialisation function for the driver called during hotplugging.
 */
typedef int (armuio_devuninit_t)(struct rte_armuio_device *);

/**
 * A structure describing a ARM UIO driver.
 */
struct rte_armuio_driver {
    TAILQ_ENTRY(rte_armuio_driver) next;        /**< Next in list. */
    
    char                name[ARMUIO_NAME_MAX_LEN]; /**< Driver name. */
    armuio_devinit_t   *dev_init;                  /**< Device init. funcion. */
    armuio_devuninit_t *dev_uninit;                /**< Device uninit. function. */

};

/**
 * A structure describing a UIO data.
 */
struct rte_armuio_data {
    TAILQ_ENTRY(rte_armuio_data) next; /**< Next in list. */
    
    char  name[ARMUIO_NAME_MAX_LEN];
    void *data;
};

/**
 * Register a ARM UIO driver.
 *
 * @param driver
 *   A pointer to a rte_armuio_driver structure describing the driver
 *   to be registered.
 *
 * @author lixu
 */
void rte_eal_armuio_register(struct rte_armuio_driver *driver);

/**
 * Unregister a ARM UIO driver.
 *
 * @param driver
 *   A pointer to a rte_armuio_driver structure describing the driver
 *   to be unregistered.
 *
 * @author lixu
 */
void rte_eal_armuio_unregister(struct rte_armuio_driver *driver);

/**
 * Init ARM UIO device.
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
void *rte_eal_armuio_dev_data_alloc(char *name, uint32_t len);

/**
 * Free device data.
 *
 * @param name
 *   Name of the data to be free.
 *
 * @author lixu
 */
void rte_eal_armuio_dev_data_free(char *name);


#ifdef __cplusplus    
}
#endif

#endif /* _RTE_ARMUIO_H_ */
