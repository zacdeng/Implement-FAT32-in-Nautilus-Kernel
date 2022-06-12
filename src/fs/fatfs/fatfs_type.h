//
// Created by Zachary Deng on 6/5/22.
//

#ifndef NAUTILUS_FATFS_TYPE_H
#define NAUTILUS_FATFS_TYPE_H

#include "fatfs.h"

#define INFO(fmt, args...)  INFO_PRINT("fat32: " fmt, ##args)
#define DEBUG(fmt, args...) DEBUG_PRINT("fat32: " fmt, ##args)
#define ERROR(fmt, args...) ERROR_PRINT("fat32: " fmt, ##args)

#ifndef NAUT_CONFIG_DEBUG_FAT32_FILESYSTEM_DRIVER
#undef DEBUG
#define DEBUG(fmt, args...)
#endif

#define BLOCK_SIZE 512

struct fatfs_state {
    struct nk_block_dev_characteristics chars;
    struct nk_block_dev *dev;
    struct nk_fs        *fs;

    // ... state from our perspective
    // probably at least the mapping <-> blockdev / pdrv
    struct fatfs_bootrecord bootrecord;
    struct fatfs_char	table_chars;
};

#endif //NAUTILUS_FATFS_TYPE_H
