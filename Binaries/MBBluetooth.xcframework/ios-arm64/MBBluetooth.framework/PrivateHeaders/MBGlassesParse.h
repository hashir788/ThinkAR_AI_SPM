//
//  MBGlassesParse.h
//  MBBluetooth
//
//  Created by chenxiuwu on 2023/6/27.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

#define META_CMD_MAGIC_REQ    0x4D45
#define META_CMD_MAGIC_RSP    0x424f

@class MBGlassesFrame;
@interface MBGlassesParse : NSObject

/// 将`MBFrameProtocol`数据转换成通信协议帧
/// - Parameters:
///   - head: 协议头(magic)
///   - command: 协议命令
///   - data: 透传数据
///   - maxSize: 外设MTU大小
+ (NSArray<NSData *> *)frameByHead:(uint16_t)head
                           command:(uint16_t)command
                              data:(nullable NSData *)data
                           maxSize:(NSInteger)maxSize;

/// 将`MBFrameProtocol`数据转换成通信协议帧
/// - Parameters:
///   - head: 协议头(magic)
///   - command: 协议命令
///   - data: 透传数据
///   - reserveds: `Common_Data`格式数据
///   - maxSize: 外设MTU大小
+ (NSArray<NSData *> *)frameByHead:(uint16_t)head
                           command:(uint16_t)command
                              data:(nullable NSData *)data
                         reserveds:(NSArray<NSNumber *> *)reserveds
                           maxSize:(NSInteger)maxSize;

/// 解析完整的数据帧
/// - Parameters:
///   - data: 接收到的新数据
///   - cache: 本地缓存的数据，用于组装被拆分的数据帧
///   - responseData: 需要给发送回复的数据
///   - Retrun: 解析结果 0： cache为一个完整的数据帧，1：cache为不完整的数据帧，-1：数据解析异常
+ (NSInteger)parseReceivedData:(NSData *)data
                         cache:(NSData  * _Nullable __autoreleasing * _Nullable)cache
                  responseData:(NSData  * _Nullable __autoreleasing * _Nullable)responseData;

/// 从完整的数据帧中解析业务数据
/// - Parameter data: 完整的数据帧
+ (nullable MBGlassesFrame *)parseFrameData:(NSData *)data;

+ (nullable MBGlassesFrame *)parseStreaming:(NSData *)streamData;

+ (nullable NSString *)hexStringWithData:(NSData *)data;

@end

NS_ASSUME_NONNULL_END
