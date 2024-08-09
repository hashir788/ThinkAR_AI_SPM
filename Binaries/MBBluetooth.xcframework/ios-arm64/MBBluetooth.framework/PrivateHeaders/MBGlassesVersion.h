//
//  MBGlassesVersion.h
//  MBBluetooth
//
//  Created by chenxiuwu on 2023/10/9.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface MBGlassesVersion : NSObject

@property (nonatomic, assign, readonly) UInt16 major;

@property (nonatomic, assign, readonly) UInt16 minor;

@property (nonatomic, assign, readonly) UInt16 revision;

@property (nonatomic, assign, readonly) UInt16 reserve;

@property (nonatomic, strong, readonly) NSData *data;

@property (nonatomic, copy  , readonly) NSString *version;

- (instancetype)initWithData:(NSData *)data;

- (instancetype)initWithMajor:(NSInteger)major minor:(NSInteger)minor revision:(NSInteger)revision reserve:(NSInteger)reserve;

- (NSComparisonResult)compare:(MBGlassesVersion *)version;

- (NSComparisonResult)compareWithValue:(NSInteger)value;

@end

NS_ASSUME_NONNULL_END
