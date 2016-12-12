
/*
 * Scan the content of the platform bus, and the devices in the devices
 * list
 *
 * by lixu
 */
int 
rte_eal_platform_scan(void)
{
	struct dirent *e;
	DIR *dir;
	char dirname[PATH_MAX];
	uint16_t domain;
	uint8_t bus, devid, function;

	dir = opendir(platform_get_sysfs_path());
	if (dir == NULL) {
		RTE_LOG(ERR, EAL, "%s(): opendir failed: %s\n",
			__func__, strerror(errno));
		return -1;
	}

	while ((e = readdir(dir)) != NULL) {
		if (e->d_name[0] == '.')
			continue;

		if (parse_pci_addr_format(e->d_name, sizeof(e->d_name), &domain,
				&bus, &devid, &function) != 0)
			continue;

		snprintf(dirname, sizeof(dirname), "%s/%s",
				pci_get_sysfs_path(), e->d_name);
		if (pci_scan_one(dirname, domain, bus, devid, function) < 0)
			goto error;
	}
	closedir(dir);
	return 0;

error:
    closedir(dir);
    return -1;
}

/* 
 * Init the Platform EAL subsystem 
 *
 * by lixu
 */
int
rte_eal_platform_init(void)
{
    TAILQ_INIT(&platform_driver_list);
    TAILQ_INIT(&platform_device_list);

    /* do something here */
    if (rte_eal_platform_scan() < 0){
        RTE_LOG(ERR, EAL, "%s(): Cannnot scan platform vbus", __func__);
    }
    return 0;
}

