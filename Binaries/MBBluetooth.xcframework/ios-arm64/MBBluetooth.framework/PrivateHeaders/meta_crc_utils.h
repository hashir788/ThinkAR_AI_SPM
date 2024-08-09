//
// Created by yuxuewen on 2022/3/29.
//

#ifndef MBGLASS_META_CRC_UTILS_H
#define MBGLASS_META_CRC_UTILS_H

#include <stdint.h>

#ifdef  __cplusplus
extern "C" {
#endif

void meta_crc32(const void *pvData, uint32_t ui32NumBytes, uint32_t *pui32CRC);

#ifdef  __cplusplus
}
#endif

#endif //MBGLASS_META_CRC_UTILS_H
