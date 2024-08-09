//
//  MBGlassOTAService.h
//  MBBluetooth
//
//  Created by chenxiuwu on 2023/10/9.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

// Error codes that may occur during OTA upgrade
typedef NS_ENUM(NSInteger, MBGlassesFileErrorCode) {
    MBGlassesFileErrorCodeSuccess,
    MBGlassesFileErrorCodeFileNotExist,
    MBGlassesFileErrorCodeFileInvalid,
    MBGlassesFileErrorCodeGetVersions,
    //No upgrade required
    MBGlassesFileErrorCodeNoUpgrade,
    MBGlassesFileErrorCodeStartUpdate,
    MBGlassesFileErrorCodeOTASetModel,
    MBGlassesFileErrorCodeMetaVersion,
    MBGlassesFileErrorCodeCrcError,
    MBGlassesFileErrorCodeFileSend,
};

@interface MBGlassesOTAService : NSObject

+ (void)requestFirewareVersion:(nullable void(^)(NSString *_Nullable))completion;

+ (void)requestDeviceType:(nullable void(^)(NSInteger))completion;

- (instancetype)initWithPath:(NSString *)path;

- (void)startWithProgress:(void(^)(CGFloat progress))progress
               completion:(void(^)(BOOL, NSError * _Nullable))completion;

- (void)stop;

@end

NS_ASSUME_NONNULL_END
