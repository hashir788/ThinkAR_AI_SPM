/******************************************************
 *                                                      
 * Copyright (C) 2022-2023 MetaBounds Corporation       
 *                                                      
 * @author 秦洋月(qinyangyue@Meta-bounds.com): yuxuewen@meta-bounds.com                   
 *
 *                                                      
 ******************************************************/

#ifndef __META_GLASS_EXT_H__
#define __META_GLASS_EXT_H__

#include <stdint.h>
#include "metaglass_platform.h"
#include "metaglass_type.h"

#define META_BT_NAME_MAX_SIZE 24
#define META_BT_ADDR_SIZE     6

/**
 * 实时状态信息,用于主从设备间同步
 */
typedef __packed_struct{
    /** 经典蓝牙状态, 0---未连接， 1---连接*/
    uint8_t bt_state;
    /** ble状态 0---未连接， 1---连接*/
    uint8_t ble_state;

} meta_ext_state_t;

typedef __packed_struct {
    uint8_t addr[META_BT_ADDR_SIZE];
} meta_ext_addr_t;


typedef __packed_struct {
    uint32_t userId;
    char bt_name[META_BT_NAME_MAX_SIZE];
    meta_ext_addr_t bt_addr;
    meta_ext_addr_t ble_addr;
    struct meta_version version;
    uint32_t key;
    uint32_t config;
} meta_ext_config_t;


/** se token **/
typedef __packed_struct {
    uint32_t key;
    uint32_t id;
} meta_se_token_t;



#endif
