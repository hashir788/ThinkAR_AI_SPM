//
//  MBDeviceManager.h
//  MBBluetooth
//
//  Created by chenxiuwu on 2023/7/27.
//

#import <Foundation/Foundation.h>
#import "MBBluetoothDevice.h"
#import "MBFrameProtocol.h"

#import "MBCenterOptions.h"
#import "MBBluetoothState.h"
#import "MBDeviceModel.h"

@import CoreBluetooth;

NS_ASSUME_NONNULL_BEGIN

FOUNDATION_EXTERN NSString *const MBBluetoothStateDidChangedNotification;
FOUNDATION_EXTERN NSString *const MBBluetoothScanTimeoutChangedNotification;

///  peripheral discovery succeeded
@interface MBScannedDevice : NSObject

/// The peripheral to which the central is scanned.
@property (nonatomic, strong) CBPeripheral *peripheral;

/// The Received Signal Strength Indicator (RSSI), in decibels, of the peripheral.
@property (nonatomic, assign) NSInteger rssi;

/// The mac address of the peripheral.
@property (nonatomic, copy) NSString *mac;

/// The name of the peripheral.
@property (nonatomic, copy) NSString *name;

/// custom pid & uid
@property (nonatomic, copy) NSString *model;

/// A Boolean value that indicates whether the advertising event type is connectable.
@property (nonatomic, assign) BOOL isConnectable;

@end

@interface MBDeviceManager : NSObject

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

@property (nonatomic, readonly, class) MBDeviceManager *shared;

/// 蓝牙是否可用
@property (nonatomic, assign, readonly, getter=isEnabled) BOOL enabled;

@property (nonatomic, assign, readonly) MBBluetoothState state;

@property (nonatomic, assign, readonly) BOOL isScanning;

@property (nonatomic, assign, readonly, getter=isDeviceAvailable) BOOL deviceAvailable;

/// 当前使用的设备
@property (nonatomic, strong, readonly, nullable) id<MBBluetoothDevice> selectedDevice;

@property (nonatomic, assign) MBDeviceModel deviceType;

- (void)setupWithOptions:(nullable MBCreationOptions *)options;

/// Scans for peripherals that are advertising services.
/// - Parameters:
///   - options: A dictionary of options for customizing the scan
///   - completion: scan result callback
- (void)scanForOptions:(nullable MBScanOptions *)options
               devices:(void(^)(MBScannedDevice *))devices
            completion:(nullable void(^)(BOOL, NSError *_Nullable))completion;

- (void)scanForOptions:(nullable MBScanOptions *)options
                filter:(nullable MBScanFilter *)filter
               devices:(void(^)(MBScannedDevice *))devices
            completion:(nullable void(^)(BOOL, NSError * _Nullable))completion;

- (void)stopScan;

/// Establishes a local connection to a peripheral.
/// - Parameters:
///   - mac: mac address of the peripheral
///   - userId: id of the user
///   - token: device token
///   - model: deice model
///   - completion: connection result callback
- (void)connectWithMac:(NSString *)mac
                userId:(NSInteger)userId
                 token:(NSString *)token
                 model:(nullable NSString *)model
            completion:(nullable void(^)(_Nullable id<MBBluetoothDevice> device, NSError *_Nullable error))completion;

/// Establishes a local connection to a peripheral.
/// - Parameters:
///   - mac: mac address of the peripheral
///   - name: name of the peripheral
///   - userId: id of the user
///   - token: device token
///   - model: deice model
///   - completion: connection result callback
- (void)connectWithMac:(NSString *)mac
                  name:(nullable NSString *)name
                userId:(NSInteger)userId
                 token:(NSString *)token
                 model:(nullable NSString *)model
            completion:(nullable void(^)(_Nullable id<MBBluetoothDevice> device, NSError *_Nullable error))completion;

- (void)disconnect:(BOOL)shouldUnbind completion:(nullable MBTaskCompletion)completion;

/// disconnect perihperal and not any callback
- (void)implicitDisconnect;

- (void)traceLogWithLevel:(MBBluetoothLogLevel)level block:(void(^)(NSString *))block;

- (void)retrieveConnectedPeripheral;

//- (MBDeviceModel)deviceModelWithModel:(NSString *)model;

@end

NS_ASSUME_NONNULL_END
