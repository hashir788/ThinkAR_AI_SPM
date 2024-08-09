//
//  MBBigDataManager.h
//  MBBluetooth
//
//  Created by baiwhte on 2023/9/30.
//

#import <Foundation/Foundation.h>
#import "MBCommonData.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(UInt8, MBGlassesDataPacket) {
    /** 数据包 */
    CMD_BINARY_PACKET_1A     = 0x1A,
};

@interface MBCommonDataManager : NSObject

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

@property (nonatomic, readonly, class) MBCommonDataManager *shared;

/// 发送CommonData数据
- (void)sendData:(MBCommonData *)data;

- (void)stopData:(MBCommonData *)data;

- (void)stopAllTasks;

/// 接收CommonData数据
- (void)receivedFrame:(id<MBFrameProtocol>)frame;

@end

NS_ASSUME_NONNULL_END
