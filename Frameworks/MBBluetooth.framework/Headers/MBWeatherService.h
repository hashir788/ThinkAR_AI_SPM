//
//  MBWeatherService.h
//  MBBluetooth
//
//  Created by chenxiuwu on 2024/4/23.
//

#import "MBDeviceFrameService.h"

NS_ASSUME_NONNULL_BEGIN

@interface MBWeather : NSObject

/**风向
     *     0x00--无风向
     *     0x01--东北
     *     0x02--东
     *     0x03--东南
     *     0x04--南
     *     0x05--西南
     *     0x06--西
     *     0x07--西北
     *     0x08--北
     *     0xFF--旋转不定
     */
@property (nonatomic, assign) UInt8 winddirection;

/// 风力
@property (nonatomic, assign) UInt8 windpower;

/// 温度
@property (nonatomic, assign) UInt8 humidity;

/// 温度
@property (nonatomic, assign) UInt16 temperature;

/// 最低温度
@property (nonatomic, assign) UInt16 minTemperature;

/// 最高温度
@property (nonatomic, assign) UInt16 maxTemperature;

/// 空气质量
@property (nonatomic, assign) UInt16 airQuality;

/// 天气信息
@property (nonatomic, assign) UInt8 weather;

/// 天气类型：晴/雨/
@property (nonatomic, copy) NSString *location;

- (instancetype)initWithHumidity:(UInt8)humidity
                   winddirection:(UInt8)winddirection
                       windpower:(UInt8)windpower
                     temperature:(UInt16)temperature
                  minTemperature:(UInt16)minTemperature
                  maxTemperature:(UInt16)maxTemperature
                      airQuality:(UInt16)airQuality
                         weather:(UInt8)weather
                        location:(NSString *)location;

@end

@interface MBWeatherService : MBDeviceFrameService

/// 【天气使能--同步天气开关状态】
+ (void)syncWeatherEnable:(BOOL)isEnable completion:(nullable void(^)(BOOL))completion;

/// 【天气设置--天气信息】
+ (void)syncWeatherData:(NSData *)data completion:(nullable void(^)(BOOL))completion;

+ (void)sendWeather:(MBWeather *)weather completion:(nullable void(^)(BOOL))completion;

@end

NS_ASSUME_NONNULL_END
