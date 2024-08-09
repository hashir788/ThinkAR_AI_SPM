/******************************************************
 *                                                      
 * Copyright (C) 2022-2023 MetaBounds Corporation
 *                                                      
 * @author 秦洋月(qinyangyue@Meta-bounds.com): yuxuewen@meta-bounds.com                   
 *                        
 *                                                      
 ******************************************************/

#ifndef __METAFLASS_LOG_H__
#define __METAFLASS_LOG_H__

#if defined(ANDROID)
#include "android/logutil.h"
#elif defined(FREQCHIP)
#include "freqchip/logutil.h"
#elif defined(AMBIQ)
#include "ambiq/logutil.h"
#elif defined(AIROHA)
#include "airoha/logutil.h"
#elif defined(LINUX)
#include "linux/logutil.h"
#else
#include "logutil.h"
#endif


#endif
