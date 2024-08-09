//
//  MBDevice.h
//  MBTimeWheel
//
//  Created by chenxiuwu on 2023/6/21.
//

#import <Foundation/Foundation.h>
#import "MBBluetoothDevice.h"
//#import "MBDataStream.h"

NS_ASSUME_NONNULL_BEGIN

/// 莫界眼镜设备
@interface MBGlassesDevice : NSObject<MBBluetoothDevice>

/**
 * 用户相关信息
 * */
@property (nonatomic, assign) NSInteger userId;
/// 云端生成的Token（公有）
@property (nonatomic, assign) NSUInteger cloudToken;
/// 外设生成的Token（私有）
@property (nonatomic, copy, nullable) NSString *deviceToken;
@property (nonatomic, copy, readonly, nullable) NSString *btMacAddress;

@property (nonatomic, assign, readonly) NSInteger boot;
@property (nonatomic, assign, readonly) NSInteger deviceType;

//@property (nonatomic, copy) NSString *bleMacAddress;

/// 断开连接
/// - Parameter frame: 断开连接前需要发送的命令
//- (void)disconnect:(nullable id<MBFrameProtocol>)frame;

//- (void)unbind;

//@property (nonatomic, strong, nullable) id<MBDataStream> dataStream;

@end

NS_ASSUME_NONNULL_END
