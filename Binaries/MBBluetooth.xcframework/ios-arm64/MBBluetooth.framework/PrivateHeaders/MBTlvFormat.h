//
//  MBTlvFormat.h
//  MBBluetooth
//
//  Created by chenxiuwu on 2023/7/31.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface MBTlvObject : NSObject<NSCopying>

@property (nonatomic, assign) UInt8 type;
@property (nonatomic, strong) NSData *data;

+ (instancetype)objectWithType:(UInt8)type data:(NSData *)data;

- (instancetype)initWithType:(UInt8)type data:(NSData *)data;

@end

/// TLV数据格式
/// -----------------------------
/// | Type |  Legth |  V     |
/// | 1字节 |  2字节 | payload |
/// ------------------------------

@interface MBTlvFormat : NSObject

/// 生成TLV格式数据
/// - Parameters:
///   - type: 数据类型
///   - data: 负载数据
+ (nullable NSData *)tlvWithType:(UInt8)type value:(NSData *)data;

/// 合并TLV格式数据
/// - Parameter objects: MBTlvObject数组
+ (nullable NSData *)mergeTlvObjects:(NSArray<MBTlvObject *> *)objects;

/// 解析TLV格式数据
/// - Parameter data: 待解析的数据
+ (nullable NSArray<MBTlvObject *> *)parseData:(NSData *)data;
@end

NS_ASSUME_NONNULL_END
