/******************************************************
 *                                                      
 * Copyright (C) 2022-2023 MetaBounds Corporation       
 *                                                      
 * @author 秦洋月(qinyangyue@Meta-bounds.com): yuxuewen@meta-bounds.com                   
 *
 *                                                      
 ******************************************************/

#ifndef __METAGLASS_MUTEX_H__
#define __METAGLASS_MUTEX_H__

#include "metaglass_platform.h"

#ifdef  __cplusplus
extern "C" {
#endif

int mg_mutex_init(mg_mutex* mutex);
int mg_mutex_destroy(mg_mutex* mutex);
int mg_mutex_lock(mg_mutex* mutex);
int mg_mutex_unlock(mg_mutex* mutex);


#ifdef  __cplusplus
} /* extern "C" */
#endif

#endif

