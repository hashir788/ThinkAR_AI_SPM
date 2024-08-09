/******************************************************
 *                                                      
 * Copyright (C) 2021-2021 MetaBounds Corporation       
 *                                                      
 * @Author: yuxuewen@meta-bounds.com                   
 * @Create Time: Mon 02 Jan 2023 11:39:25 PM PST
 * @File Name: metaglass_crc.h
 * @Description:                                       
 *                                                      
 ******************************************************/

#ifndef __METAGLASS_CRC_H__
#define __METAGLASS_CRC_H__

#include <stdint.h>

#ifdef  __cplusplus
extern "C" {
#endif

uint8_t metaglass_crc8(uint8_t *ptr, uint16_t len, uint8_t crc_origin);

#ifdef  __cplusplus
} /* extern "C" */
#endif

#endif
