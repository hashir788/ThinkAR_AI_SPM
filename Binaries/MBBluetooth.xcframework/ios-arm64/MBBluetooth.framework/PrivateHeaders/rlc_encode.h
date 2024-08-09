/******************************************************
 *                                                      
 * Copyright (C) 2021-2021 MetaBounds Corporation       
 *                                                      
 * @Author: yuxuewen@meta-bounds.com                   
 * @Create Time: Thu 04 Aug 2022 12:48:57 AM PDT
 * @File Name: rlc_encode.h
 * @Description:                                       
 *                                                      
 ******************************************************/

#ifndef __RLC_ENCODE_H__ 
#define __RLC_ENCODE_H__

#include <stdint.h>

#ifdef  __cplusplus
extern "C" {
#endif

/**
 * Compress by rlc
 * @param srcBuf  src byte buf
 * @param srcSize src byte buf size
 * @param dstBuf  dst byte buf
 * @param dstSize dst buye buf size
 * @return        size after compress 
 */
int rlc_compress(uint8_t* srcBuf, int srcSize, uint8_t* dstBuf, int dstSize);

/**
 * UnCompress by rlc
 * @param srcBuf  src byte buf
 * @param srcSize src byte buf size
 * @param dstBuf  dst byte buf
 * @param dstSize dst buye buf size
 * @return        size after uncompress 
 */
int rlc_uncompress(uint8_t* srcBuf, int srcSize, uint8_t* dstBuf, int dstSize);


#ifdef  __cplusplus
} /* extern "C" */
#endif

#endif

