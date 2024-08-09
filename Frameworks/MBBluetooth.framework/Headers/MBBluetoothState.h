//
//  MBBluetoothState.h
//  MBTimeWheel
//
//  Created by chenxiuwu on 2023/6/21.
//

#ifndef MBBluetoothState_h
#define MBBluetoothState_h

typedef NS_ENUM(NSUInteger, MBBluetoothState) {
    MBBluetoothStateUnsupport,
    MBBluetoothStateUnauthorized,
    MBBluetoothStatePoweredOff,
    MBBluetoothStateBusy,
    MBBluetoothStateReady,
};

//连接状态
typedef NS_ENUM(NSUInteger, MBConnectState) {
    MBConnectStateDisconnected = 0,
    MBConnectStateConnecting,
    MBConnectStateConnected,
    MBConnectStateDisconnecting,
};

typedef NS_ENUM(NSUInteger, MBTaskState) {
    MBTaskStateWaiting = 0,
    MBTaskStateExecuting,
    MBTaskStateFinished,
    MBTaskStateFailed
};

typedef NS_ENUM(NSInteger, MBTaskErrorCode) {
    /// Unkown error
    MBTaskErrorCodeUnkown,
    /// Bluetooth is currently powered off.
    MBTaskErrorCodePoweredOff,
    /// The user is not authorized to use Bluetooth
    MBTaskErrorCodeBluetoothNotReady,
    /// The task are timeout
    MBTaskErrorCodeTimeout,
    /// The task are canceled
    MBTaskErrorCodeCanceled,
    /// The current Bluetooth device is not supported
    MBTaskErrorCodeUnkownDevice,
    /// Has another connect task
    MBTaskErrorCodeConnecting,
    /// The device don’t connected
    MBTaskErrorCodeDisconnected,
    /// User verification failure
    MBTaskErrorCodeAuthenticationFailed,
    /// The device are bound by others
    MBTaskErrorCodeBoundByOther,
    /// User not logged in
    MBTaskErrorCodeLogout,
};

typedef NS_ENUM(NSUInteger, MBBluetoothLogLevel) {
    MBBluetoothLogLevelInfo = 0,
    MBBluetoothLogLevelDebug,
    MBBluetoothLogLevelWarning,
    MBBluetoothLogLevelFatal
};

#endif /* MBBluetoothState_h */
