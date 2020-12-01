//
//  JKAdManager.h
//  AdSDKTest
//
//  Created by 唐佳鹏 on 2019/9/14.
//  Copyright © 2019 damianshou. All rights reserved.
//

#import <sys/utsname.h>
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface JKAdManager : NSObject

+ (instancetype)sharedInstance;

/**
 初始化方法

 @param scheduleURL 所有广告url
 @param showPositionURL 展示广告url
 @param media  媒体代码  记刻给出的
 @param channel  渠道标识  
 @param adList 广告列表 传空为缓存所有排期广告 多个广告用逗号分开 如:@[@"code001", @"code002"]
 */
- (void)initConfigWithScheduleURL:(NSString *)scheduleURL
                  showPositionURL:(NSString *)showPositionURL
                            media:(NSString *)media
                          channel:(NSString *)channel
                           adList:(NSArray <NSString *>*)adList;
/// 设置广告userId
/// @param userId 广告userId, 用于请求广告参数
- (void)jk_setUserId:(NSString *)userId;

/// 是否打开log，
/// @param open yes：打开  no：关闭
- (void)jk_openLog:(BOOL)open;
/// 实时反馈sdk的log
/// @param listener log回调
- (void)jk_setLogListener:(void (^)(NSString *msg))listener;

/// 设置预缓存广告素材定时下载的时间间隔, 默认不开启定时下载
/// @param time 轮询的时间间隔 (单位分钟) 大于0才有效
- (void)jk_setTime:(NSInteger)time;

/// 是否开启广告的定位功能
/// @param gps 默认NO  如果设置为YES， 项目需要配置NSLocationWhenInUseUsageDescription的权限
- (void)jk_setGPS:(BOOL)gps;
/// 设置定位信息  说明：该函数设置完，定位信息以传入的为准
/// @param latitude 纬度 无法获取可传0
/// @param longitude 经度 无法获取可传0
/// @param altitude 海拔  无法获取可传0
- (void)jk_setLatitude:(CGFloat)latitude longitude:(CGFloat)longitude altitude:(CGFloat)altitude;

/// 设置请求的超时时间
/// @param timeout  默认2s
- (void)jk_setRequestTimeout:(NSTimeInterval)timeout;

/// 加载广告  初始化完相关参数必须调用该方法
- (void)jk_initAds;

/**
 缓存设备广告位,  用户想要更新广告数据，可调用该方法
 @param spaces 想要获取对应广告的数组 注:spaces传空为缓存所有排期广告 多个广告用逗号分开 如:@[@"code001", @"code002"]
 */
- (void)jk_saveSpacesWithArray:(NSArray <NSString *>*)spaces;

/// 获取对应广告位的广告
/// @param position 广告位id
/// @param complete 获取结果的回调函数
- (void)jk_checkAdWithPosition:(NSString *)position complete:(void(^)(NSArray <NSString *> *adsFilePath))complete;

/**
 清除本地缓存
 */
+ (void)jk_cleanAdCache;

@end

NS_ASSUME_NONNULL_END
