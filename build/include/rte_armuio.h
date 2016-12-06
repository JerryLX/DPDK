
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

extern struct armuio_driver_list armuio_driver_list; /**< Global list of ARM UIO drivers. */
extern struct armuio_device_list armuio_device_list; /**< Global list of ARM UIO devices. */

/**
 * A structure describing a ARM UIO resource.
 */
struct rte_armuio_resource {
    uint64_t phys_addr;     /**< Physical address, 0 if no resource. */
    uint64_t len;           /**< Length of the resource. */
    void *addr;             /**< Virtual address, NULL when not mapped. */
}

struct rte_arm
#ifdef __cplusplus    
}
#endif

#endif /* _RTE_ARMUIO_H_ */
