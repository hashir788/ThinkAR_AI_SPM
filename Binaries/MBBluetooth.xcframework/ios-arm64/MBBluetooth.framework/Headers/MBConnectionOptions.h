//
//  MBConnectionOptions.h
//  MBTimeWheel
//
//  Created by chenxiuwu on 2023/6/19.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface MBConnectionOptions : NSObject

/// A Boolean value that specifies whether the system should display an alert when connecting a peripheral in the background.
@property (nonatomic, assign) BOOL notifyOnConnection;

/// A Boolean value that specifies whether the system should display an alert when disconnecting a peripheral in the background.
@property (nonatomic, assign) BOOL notifyOnDisconnection;

/// A Boolean value that specifies whether the system should display an alert for any notification sent by a peripheral.
@property (nonatomic, assign) BOOL notifyOnNotification;

/// An option to bridge classic Bluetooth technology profiles, if already connected over Bluetooth Low Energy.
@property (nonatomic, assign) BOOL enableTransportBridingKey;

/// An option to require Apple Notification Center Service (ANCS) when connecting a device.
@property (nonatomic, assign) BOOL requiresANCS;

/// An option that indicates a delay before the system makes a connection
@property (nonatomic, assign) NSTimeInterval startDelay;

- (NSDictionary<NSString *, id> *)options;

@end

NS_ASSUME_NONNULL_END
