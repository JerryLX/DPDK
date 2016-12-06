
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
#include <rte_armuio.h>
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

struct armuio_driver_list armuio_driver_list;
struct armuio_device_list armuio_device_list;
struct armuio_data_list armuio_data_list;

struct dev_file_info {
    int            flag;
    struct dirent *file;
}

struct dev_file_info dev_file[FILE_MAX];

struct rte_armuio_driver *rte_check_armuio_drv_is_reg(char *drv_name)
{
    struct rte_armuio_driver *acc_drv;
    int len;

    TAILQ_FOREACH(acc_drv, &armuio_driver_list, next)
    {
        if (strlen(drv_name) != strlen(acc_drv->name))
            continue;

        len = strlen(drv_name);
        if(strncmp(drv_name, acc_drv->name, len) == 0)
            return acc_drv;    
    }

    return NULL;
}

void rte_eal_armuio_register(struct rte_armuio_driver *driver)
{
    if(!driver) {
        RTE_LOG(ERR,EAL,"driver is null!\n");
        return;
    }
    if(!(driver->dev_init)) {
        RTE_LOG(ERR,EAL,"dev_init is null\n");
        return
    }
    if(!(driver->dev_uninit)) {
        RTE_LOG(ERR,EAL,"dev_uninit is null\n");
        return
    }
    if(rte_check_armuio_drv_is_reg(driver->name)) {
        RTE_LOG(ERR,EAL,"call rte_check_armuio_drv_is_reg failed!\n");
        return;
    }

    TAILQ_INSERT_TAIL(&armuio_driver_list, driver, next);
}

void rte_eal_armuio_unregister(struct rte_armuio_driver *driver)
{
    struct rte_armuio_driver *drv_temp = NULL;
    struct rte_armuio_driver *drv_next = NULL;
    int len;

    if(!driver){
        RTE_LOG(ERR,EAL,"driver is null\n");
        return;
    }

    for(drv_temp = TAILQ_FIRST(&armuio_driver_list);
            drv_temp!=NULL; drv_temp=drv_next) {
        if (strlen(drv_temp->name) == strlen(driver->name)) {
            len = strlen(driver->name);
            if (strncmp(drv_temp->name, driver->name,len) == 0) {
                TAILQ_REMOVE (armuio_driver_list,drv_temp, next);
                return;
            }
        }
        //?????????????????
        drv_next = TAILQ_NEXT(drv_next,next);
    }
    RTE_LOG(ERR,EAL,"dev is not found!\n");
}
