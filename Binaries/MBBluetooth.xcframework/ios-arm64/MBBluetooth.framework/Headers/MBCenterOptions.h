//
//  MBCreationOptions.h
//  MBTimeWheel
//
//  Created by chenxiuwu on 2023/6/19.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>

NS_ASSUME_NONNULL_BEGIN
@class MBAdvertisementData;
@interface MBCreationOptions : NSObject

/// If true, display a warning dialog to the user when the `CentralManager` is instantiated if Bluetooth is powered off
@property (nonatomic, assign) BOOL showPowerAlert;

/// A unique identifier for the Central Manager that's being instantiated. This identifier is used by the system to
/// identify a specific  CBCentralManager  instance for restoration and, therefore, must remain the same for
/// subsequent application executions in order for the manager to be restored.
///
/// -Note: If no `.` Character is included, the Bundle Identifer is automatically added
@property (nonatomic, copy  ) NSString *restoreIdentifier;

- (NSDictionary<NSString *, id> *)options;

@end

@interface MBScanOptions : NSObject

@property (nonatomic, assign) BOOL isRemoveTasks;

/// Whether or not the scan should filter duplicate peripheral discoveries
@property (nonatomic, assign) BOOL allowDuplicates;

/// The array is an instance of NSArray, and uses CBUUID objects to represent the UUIDs to scan for.
//@property (nonatomic, copy  ) NSArray<CBUUID *> *solicitedServiceUUIDs;

- (NSDictionary<NSString *, id> *)options;

@end

@interface MBScanFilter : NSObject

/// 过滤名称为空的情况
@property (nonatomic, assign) BOOL emptyName;

/// A Boolean value that indicates whether the advertising event type is connectable.
@property (nonatomic, assign) BOOL isConnectable;

/// 最小rssi（蓝牙信号强度）
@property (nonatomic, assign) NSInteger minRSSI;

/// 扫描超时时间
@property (nonatomic, assign) NSInteger timeout;

/// 匹配外设名称的正则表达式
@property (nonatomic, copy  ) NSString *regexForName;

@property (nonatomic, copy  ) NSArray<CBUUID *> *serviceUUIDs;

/// 自定义过滤条件
@property (nonatomic, copy  ) BOOL(^filter)(MBAdvertisementData *);

@end

NS_ASSUME_NONNULL_END
