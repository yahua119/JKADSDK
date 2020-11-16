//
//  JKADShowCacheView.h
//  JiKeAdSDK
//
//  Created by yahua on 2020/4/3.
//  Copyright © 2020 AaronTang. All rights reserved.
//  显示已缓存的广告view

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class JKADCommonView;


typedef NS_ENUM(NSUInteger, JKADViewSkipType) {
    JKADViewSkipType_None,
    JKADViewSkipType_Skip,  //跳过
    JKADViewSkipType_Close, //关闭
};

typedef NS_ENUM(NSUInteger, JKADViewOpenType) {
    JKADViewOpenType_None,
    JKADViewOpenType_App,  //app浏览器打开
    JKADViewOpenType_Safari, //Safari打开
};

typedef NS_ENUM(NSUInteger, JKADViewEndDisplayType) {
    JKADViewEndDisplayType_Done,   //广告展示完成
    JKADViewEndDisplayType_Background,  //点击背景导致广告展示完成
    JKADViewEndDisplayType_Skip, //点击跳过或者关闭导致广告展示完成
};


@protocol JKADCommonViewDelegate <NSObject>

@optional
#pragma mark Ad Request Lifecycle Notifications

/// 广告显示完成
- (void)adViewDidEndDisplay:(JKADCommonView *)adView reason:(JKADViewEndDisplayType)reason;

/// 当前显示的广告回调
/// @param adView 广告view
/// @param adUrl 素材url
- (void)adViewDisplay:(JKADCommonView *)adView adUrl:(NSString *)adUrl;

#pragma mark Click-Time Lifecycle Notifications

/// 点击了ad view
/// @param adView 广告view
/// @param redirectUrl 跳转url
/// @param adUrl 素材url
- (void)adViewDidClicked:(JKADCommonView *)adView redirectUrl:(NSString *)redirectUrl adUrl:(NSString *)adUrl;

@end

/// 广告view
@interface JKADCommonView : UIView

@property (nonatomic, weak) id<JKADCommonViewDelegate> delegate;

/// 广告展示完成是否自动关闭  Default：NO
@property (nonatomic, assign) BOOL autoDismiss;

/// 跳过的样式  defaule JKADViewSkipType_None
@property (nonatomic, assign) JKADViewSkipType skipType;

/// 设置是否循环连播 0和负数：不循环；正数：循环因子  default:0
@property (nonatomic, assign) NSInteger loopAhead;

/// 是否显示底下多页的小圆点  只有一个广告的是时候不显示    default:YES
@property (nonatomic, assign) BOOL showPagePoint;

/// 是否显示倒计时  default: NO
@property (nonatomic, assign) BOOL showCountDown;

/// 主动设置广告倒计时时间, 注意：大于素材累计时间时，使用素材累计的时间显示
@property (nonatomic, assign) NSInteger forceCloseTime;

/// 广告填充类型   default:UIViewContentModeScaleAspectFit
@property (nonatomic, assign) UIViewContentMode adContentModel;

/// 点击广告 跳转类型 default: JKADViewOpenType_None
@property (nonatomic, assign) JKADViewOpenType openType;

/// 背景遮罩颜色  default：[[UIColor blackColor] colorWithAlphaComponent:0.7]
@property (nonatomic, strong) UIColor *maskColor;

/// 跳过按钮的背景色  default：[[UIColor blackColor] colorWithAlphaComponent:0.3]
@property (nonatomic, strong) UIColor *skipBackgroundColor;

/// 广告圆角  default：0
@property (nonatomic, assign) CGFloat adCornerRadius;

/// 初始化函数
/// @param frame 广告view的frame
/// @param adShowFrame 显示广告的frame
- (instancetype)initWithFrame:(CGRect)frame adShowFrame:(CGRect)adShowFrame;

/// 显示对应的广告
/// @param position 广告位id
- (void)showAdWithPosition:(NSString *)position;

/// 显示对应的广告 (有动画)
/// @param position 广告位id
/// @param animationCenter 动画位置
- (void)showAdAnimationWithPosition:(NSString *)position animationCenter:(CGPoint)animationCenter;

/// 关闭广告
- (void)closeAd;

@end

NS_ASSUME_NONNULL_END
