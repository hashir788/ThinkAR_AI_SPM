//
//  MBBluetoothDevice.h
//  MBTimeWheel
//
//  Created by chenxiuwu on 2023/6/21.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>

#import "MBBluetoothState.h"
#import "MBFrameProtocol.h"
#import "MBDeviceModel.h"

NS_ASSUME_NONNULL_BEGIN

typedef void (^MBTaskCompletion)(id<MBFrameProtocol> _Nullable frame, NSError *_Nullable error);

/// Please register notifications on the main queue
FOUNDATION_EXTERN NSString *const MBDeviceConnectStateDidChangedNotification;
FOUNDATION_EXTERN NSString *const MBDeviceDidReceivedFrameDataNotification;

FOUNDATION_EXTERN NSString *const MBDeviceSendFrameErrorNotification;

/// Received data from perihperal
/// - Parameters:
///   - frame:  Communication protocol frame
/// - Return Value: respone frame to peripheral, or ignore if return value is nil
typedef id<MBFrameProtocol> _Nullable (^MBDidReceivedForCharacteristic)(id<MBFrameProtocol> frame);

@protocol MBBluetoothDevice <NSObject, NSCopying>

/// Device identifier
@property (nonatomic, copy, readonly) NSString *deviceId;

/// mac address
@property (nonatomic, copy, nullable) NSString *deviceMac;

/// glasses's model
@property (nonatomic, copy) MBDeviceModel model;

@property (nonatomic, assign) MBConnectState state;

@property (nonatomic, strong, readonly) CBPeripheral *peripheral;

+ (id<MBBluetoothDevice>)deviceWithPeripheral:(CBPeripheral *)peripheral;

- (id<MBBluetoothDevice>)initWithPeripheral:(CBPeripheral *)peripheral;

/// connect current device
- (void)connect:(nullable void(^)(BOOL, NSError * _Nullable))completion;

/// the peripherals connected to the system whose services match a given set of criteria
- (void)retrieveConnected:(nullable void(^)(BOOL, NSError * _Nullable))completion;

- (void)connect:(BOOL)isRetrieve completion:(nullable void(^)(BOOL, NSError * _Nullable))completion;

/// peripheral service discovery succeeded
/// - Parameter service: peripheral service
- (void)didDiscoverCharacteristicsForService:(CBService *)service;

///
/// - Parameter characteristic: The characteristic for which to configure value notifications.
- (void)didUpdateNotificationStateForCharacteristic:(CBCharacteristic *)characteristic;

/// Received data from perihperal
/// - Parameter characteristic: The characteristic for which to configure value notifications.
- (void)didReceivedForCharacteristic:(CBCharacteristic *)characteristic;

/// send data to peripheral
/// - Parameters:
///   - frame: Communication protocol frame
///   - completion: The completion to call when the task request is complete or timeout
- (void)sendFrame:(id<MBFrameProtocol>)frame completion:(nullable MBTaskCompletion)completion;

- (void)sendData:(NSData *)data;

/// Disconnect peripherals
/// - Parameter shouldUnbind: Whether to send the unbind command
- (void)disconnect:(BOOL)shouldUnbind;

- (void)disconnect:(BOOL)shouldUnbind completion:(nullable MBTaskCompletion)completion;

@optional

///  The manufacturer data of a peripheral.
@property (nonatomic, copy, nullable) NSData *manufacturerData;

@property (nonatomic, copy, nullable) NSDictionary *connectOpions;

/// An L2CAP channel has been enabled.
/// - Parameter channel: A live L2CAP connection to a remote device.
- (void)didOpenL2CAPChannel:(CBL2CAPChannel *)channel;

/// Register request command callbacks received from peripherals
- (void)registerCommand:(UInt16)command tag:(nullable NSString *)tag listener:(MBDidReceivedForCharacteristic)listener;

- (void)removeListenForCommand:(UInt16)command tag:(nullable NSString *)tag;

- (void)cancelFrames:(NSArray<id<MBFrameProtocol>>*)frames;

@end

NS_ASSUME_NONNULL_END
