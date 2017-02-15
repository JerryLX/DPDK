#include <sys/queue.h>
#include <stdio.h>
#include <errno.h>
#include <stdint.h>
#include <stdarg.h>

#include <rte_common.h>
#include <rte_interrupts.h>
#include <rte_byteorder.h>
#include <rte_log.h>
#include <rte_debug.h>
#include <rte_ether.h>
#include <rte_ethdev.h>
#include <rte_memory.h>
#include <rte_memzone.h>
#include <rte_eal.h>
#include <rte_atomic.h>
#include <rte_malloc.h>
#include <rte_dev.h>
#include <rte_platform.h>
#include "hns_ethdev.h"


static struct rte_platform_id platform_id_hns_map[]={
    {.name = "HISI00C2:03"},
    {0}
};

static int func(struct hns_adapter * hns){
    (void)hns;
    return 0;
}

static int
eth_hns_dev_init (struct rte_eth_dev *eth_dev){
    struct hns_adapter *hns=eth_dev->data->dev_private;
    int rc = func(hns);
    return rc;
}

static int
eth_hns_dev_uninit (struct rte_eth_dev *eth_dev){
    struct hns_adapter *hns = eth_dev->data->dev_private;
    int rc = func(hns);
    return rc;
}



static struct eth_driver rte_hns_pmd ={
    .platform_drv={
        .name= "rte_hns_pmd",
        .id_table = platform_id_hns_map,
        .drv_flags = RTE_PLATFORM_DRV_NEED_MAPPING | RTE_PLATFORM_DRV_INTR_LSC,
    },
    .eth_dev_init = eth_hns_dev_init,
    .eth_dev_uninit = eth_hns_dev_uninit,
    .dev_private_size = sizeof (struct hns_adapter),
};

/**
static struct eth_driver rte_hnsvf_pmd ={
    .platform_drv={
        .name="rte_hnsvf_pmd",
        .id_table = platform_id_hnsvf_map,
        .drv_flags = RTE_PLATFORM_DRV_NEED_MAPPING | RTE_PLATFORM_DRV_INTR_LSC,
    },
    .eth_dev_init = eth_hnsvf_dev_init,
    .eth_dev_uninit = eth_hnsvf_dev_uninit,
    .dev_private_size = sizeof (struct hns_adapter),
};
*/


static int
rte_hns_pmd_init(const char *name __rte_unused, const char *params __rte_unused)
{
    rte_eth_platform_driver_register(&rte_hns_pmd);
    return 0;
}

static int
rte_hns_pmd_uninit(const char *name)
{
    (void)name;
    return 0;
}

/**
static int
rte_hnsvf_pmd_init(const char *name __rte_unused, const char *params __rte_unused)
{
    PMD_INIT_FUNC_TRACE();
    rte_eth_platform_driver_register(&rte_hnsvf_pmd);
    return 0;
}
*/
static struct rte_driver rte_hns_driver = {
    .type = PMD_PDEV,
    .init = rte_hns_pmd_init,
    .uninit = rte_hns_pmd_uninit,
};

/**
static struct rte_driver rte_hnsvf_driver = {
    .type = PMD_PDEV,
    .init = rte_hnsvf_pmd_init,
};
*/

PMD_REGISTER_DRIVER(rte_hns_driver, hns);
/*PMD_REGISTER_DRIVER(rte_hnsvf_driver, hnsvf);*/

