/******************************************************
 *                                                      
 * Copyright (C) 2022-2023 MetaBounds Corporation
 *                                                      
 * @author 秦洋月(qinyangyue@Meta-bounds.com): yuxuewen@meta-bounds.com                   
 *                      
 *                                                      
 ******************************************************/

#ifndef __METAGLASS_VERSION_H__
#define __METAGLASS_VERSION_H__

#define MG_VERSION_MAJOR    1
#define MG_VERSION_MINOR    0
#define MG_VERSION_REVISION 2
#define MG_VERSION_BUILD    "FFFFFFF"
#define MG_COMPLETE_TIME    "2022-08-17 11:53"

#ifdef  __cplusplus
extern "C" {
#endif

void metaglass_version_info(char* ver);

#ifdef  __cplusplus
} /* extern "C" */
#endif

#endif
