//
//  MBDeviceSerice.h
//  MBBluetooth
//
//  Created by chenxiuwu on 2023/8/4.
//

#import <Foundation/Foundation.h>
#import "MBBluetoothDevice.h"
#import "MBGlassesResponse.h"

NS_ASSUME_NONNULL_BEGIN

@interface MBDeviceFrameService : NSObject

@property (class, nonatomic, strong, readonly) id<MBBluetoothDevice> device;

+ (void)sendFrame:(id<MBFrameProtocol>)frame completion:(nullable void(^)(MBGlassesResponse *))completion;

+ (void)registerCommand:(UInt16)command tag:(nullable NSString *)tag listener:(MBDidReceivedForCharacteristic)listener;

+ (void)removeListenForCommand:(UInt16)command tag:(nullable NSString *)tag;

@end

NS_ASSUME_NONNULL_END
