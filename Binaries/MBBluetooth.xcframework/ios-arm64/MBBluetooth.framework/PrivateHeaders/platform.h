/******************************************************
 *                                                      
 * Copyright (C) 2022-2023 MetaBounds Corporation
 *                                                      
 * @author 秦洋月(qinyangyue@Meta-bounds.com): yuxuewen@meta-bounds.com                   
 *                 
 *                                                      
 ******************************************************/

#ifndef __METAGLASS_LINUX_PLATFORM_H__
#define __METAGLASS_LINUX_PLATFORM_H__

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

#define __packed_struct struct __attribute__((packed, aligned(1)))
#define __packed_union  union  __attribute__((packed, aligned(1)))

#define mg_malloc(size) malloc(size)
#define mg_free(p)      free(p)

#define mg_sprintf      sprintf

#define mg_mutex        pthread_mutex_t

#endif
