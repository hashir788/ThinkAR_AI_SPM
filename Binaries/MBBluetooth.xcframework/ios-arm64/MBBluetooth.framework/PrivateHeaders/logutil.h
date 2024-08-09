/*
 * LogUtil.h
 *
 *  Created on: 2022-12-12
 *      Author: yuxuewen
 */

#ifndef LOGUTIL_H_
#define LOGUTIL_H_

#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>


#define MLOG_ENABLE              1

#define MLOG_LEVEL_NONE          0
#define MLOG_LEVEL_ERROR         1
#define MLOG_LEVEL_WARNING       2
#define MLOG_LEVEL_INFO          3
#define MLOG_LEVEL_DEBUG         4

#ifndef MLOG_LEVEL_MODULE
#define MLOG_LEVEL_MODULE        MLOG_LEVEL_DEBUG
#endif

#if MLOG_ENABLE
#define MLOG_D(...)      do {                                                   \
                            if(MLOG_LEVEL_MODULE >= MLOG_LEVEL_DEBUG) {         \
                                printf("[P-D] " __VA_ARGS__);                     \
                            }                                                   \
                        } while(0)                                              \
	
#define MLOG_I(...)     do {                                                    \
                            if(MLOG_LEVEL_MODULE >= MLOG_LEVEL_INFO) {          \
                                printf("[P-I] " __VA_ARGS__);                     \
                            }                                                   \
                        } while(0)

#define MLOG_W(...)     do {                                                    \
                            if(MLOG_LEVEL_MODULE >= MLOG_LEVEL_WARNING) {       \
                                printf("[P-W] " __VA_ARGS__);                     \
                            }                                                   \
                        } while(0)

#define MLOG_E(...)     do {                                                    \
                            if(MLOG_LEVEL_MODULE >= MLOG_LEVEL_ERROR) {         \
                                printf("[P-E] " __VA_ARGS__);                     \
                            }                                                   \
                        } while(0)

#else   // #if MLOG_ENABLE
#define MLOG_D(...)					
#define MLOG_I(...)
#define MLOG_W(...)
#define MLOG_E(...)
#endif  // #if MLOG_ENABLE



#endif /* LOGUTIL_H_ */
