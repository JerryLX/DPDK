
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
    int len;

    if(!driver){
        RTE_LOG(ERR,EAL,"driver is null\n");
        return;
    }

    TAILQ_FOREACH (drv_temp, &armuio_driver_list, next)
    {
        if (strlen(drv_temp->name) == strlen(driver->name)) {
            len = strlen(driver->name);
            if (strncmp(drv_temp->name, driver->name,len) == 0) {
                TAILQ_REMOVE (armuio_driver_list,drv_temp, next);
                return;
            }
        }
    }
    RTE_LOG(ERR,EAL,"dev is not found!\n");
}

struct rte_armuio_data *rte_armuio_check_name_is_alloc(char *name)
{
    struct rte_armuio_data *uio_data;
    int len;

    TAILQ_FOREACH(uio_data, &armuio_data_list,next)
    {
        if(strlen(name) != strlen(uio_data->name))
            continue;

        len = strlen(name);
        if(strncmp(name, uio_data->name, len) == 0)
            return uio_data;
    }

    return NULL;
}


void *rte_eal_armuio_data_alloc(char *name, uint32_t len)
{
    struct rte_armuio_data *uio_data;

    if(!name){
        RTE_LOG(ERR,EAL,"name is null!\n");
        return NULL;
    }
    if(len == 0){
        RTE_LOG(ERR,EAL,"invalid len = %u!\n",len);
        return NULL;
    }
    if(rte_armuio_check_name_is_alloc(name)){
        RTE_LOG(ERR,EAL,"name: %s, has been allocated!\n", name);
        return NULL;
    }
    uio_data = (struct rte_armuio_data *)malloc(len + sizeof(struct rte_armuio_data));
    
    if(!uio_data){
        RTE_LOG(ERR,EAL,"call malloc failed!\n");
        return NULL;
    }
    
    memset((void *)uio_data,0,len+sizeof(struct rte_armuio_data));
    strncpy(uio_data->name,name,strlen(name));
    uio_data->data = (void *)((uint8_t *)uio_data + sizeof(struct rte_armuio_data));
    
    TAILQ_INSERT_TAIL(&armuio_data_list, uio_data, next);
    return uio_data->data;
}

void rte_eal_armuio_data_free(char *name)
{
    struct rte_armuio_data *uio_data_temp; 

    if(!name){
        RTE_LOG(ERR,EAL,"name is null!\n");
        return;
    }

    TAILQ_FOREACH(uio_data_temp,&armuio_data_list,next){
        if(strlen(uio_dta_temp->name) == strlen(name)){
            if(strncmp(uio_data_temp->name,name,strlen(name))==0){
                free((void *)((uint8_t *)uio_data_temp->data - sizeof(struct rte_armuio_data)));
                TAILQ_REMOVE(&armuio_data_list,uio_data_temp,next);
                return;
            }
        }
    }
    RTE_LOG(ERR,EAL,"name: %s not found!\n",name);
}



