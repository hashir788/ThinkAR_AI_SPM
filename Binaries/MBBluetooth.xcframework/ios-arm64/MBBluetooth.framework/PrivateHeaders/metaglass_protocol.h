/******************************************************
 *                                                      
 * Copyright (C) 2022-2022 MetaBounds Corporation       
 *                                                      
 * @author 秦洋月(qinyangyue@Meta-bounds.com): yuxuewen@meta-bounds.com                   
 * 
 *                                                      
 ******************************************************/

#ifndef __META_GLASS_PROTOCOL_H__
#define __META_GLASS_PROTOCOL_H__

#include <stdint.h>
#include <stdbool.h>

#include "metaglass_type.h"

/** cmd接收完全 */
#define META_CMD_STATE_OK    0
/** cmd还有子包 */
#define META_CMD_STATE_LEFT  1
/** cmd数据错误 */
#define META_CMD_STATE_ERR   2


#define M_MIN(x,y) ( (x<y) ? (x) : (y) )
#define M_MAX(x,y) ( (x>y) ? (x) : (y) )

/* request operation */
typedef int (^WriteRequest)(void* instance, uint8_t *data, uint16_t len);
/* msg callback*/
typedef void (^MsgCallback)(void* instance, struct meta_cmd_head* head, uint8_t* value);


/** 如果包太大，包要存到cache中 */
typedef struct
{
    /* msgHead*/
    struct meta_cmd_head head;
    /* 存储的数据*/
    uint8_t* buf;
} MsgCache;

typedef struct 
{
    struct meta_cmd_head* head;
    uint8_t* data;
    uint8_t* buf;
} MsgBufPtr;

/** 
 * 消息handler
 * 当接收的包不完全时，放入接收cache中
 * 当发送的包超过tx_max_size, 需要分多包发送时，可以放入发送cache中
 **/
typedef struct
{
    /* 最大的发送大小，不同通道不一样 */
    uint16_t tx_max_size;
    /* 发送缓存大小 */
    uint16_t tx_cache_size;
    /* 接收缓存大小 */
    uint16_t rx_cache_size;
    /* 保存rx缓存*/
    bool rx_cache_save;
    /* tx msg */
    MsgBufPtr msgTx;
    /* rx msg */
    MsgBufPtr msgRx;
    /* tx cache */
    MsgCache cacheTx;
    /* rx cache */
    MsgCache cacheRx;
    /* request operation */
    WriteRequest writeRequest;
    /* msg callback*/
    MsgCallback msgCallback;
    /* hold instance */
    void* instance;
    /* 内部使用*/
    bool inited;

} MsgHandler;

#ifdef  __cplusplus
extern "C" {
#endif

int mg_protocol_init(MsgHandler* handler);
int mg_protocol_recvMsg(MsgHandler* handler, uint8_t* data, uint16_t len);
int mg_protocol_sendMsgReq(MsgHandler* handler, uint16_t type, uint8_t* data, uint16_t dataLen);
int mg_protocol_sendMsgRsp(MsgHandler* handler, uint16_t type, uint8_t* data, uint16_t dataLen);
int mg_protocol_deInit(MsgHandler* handler);

#ifdef  __cplusplus
} /* extern "C" */
#endif


#endif

