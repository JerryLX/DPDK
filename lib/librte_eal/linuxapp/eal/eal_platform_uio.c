/*
 * Return the uioX char device used for a platform device.
 * On success, return the UIO number.
 *
 * by lixu
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

    return uio_num;
}
    
/*
 * Alloc uio resource for platform device.
 * 
 * by lixu
 */
int
platform_uio_alloc_resource(struct rte_platform_device *dev)
{
    char dirname[PATH_MAX];
    char cfgname[PATH_MAX];
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

    snprintf(cfgname, sizeof(cfgname),
        "/sys/class/uio/uio%u/device/config", uio_num);
    dev->intr_handle.uio_cfg_fd = open(cfgname, O_RDWR);
    if(dev->intr_handle.uio_cfg_fd < 0){
        RTE_LOG(ERR, EAL, "Cannot open %s\n", cfgname);
        goto error;
    }

error:
    platform_uio_free_resource(dev);
    return -1;
}
