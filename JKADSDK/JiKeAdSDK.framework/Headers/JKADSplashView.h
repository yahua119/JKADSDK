//
//  JKADSplashView.h
//  BlueToothTools
//
//  Created by yahua on 2020/4/13.
//  Copyright © 2020 Landi. All rights reserved.
//  开屏广告

#import "JKADCommonView.h"

NS_ASSUME_NONNULL_BEGIN

@interface JKADSplashView : JKADCommonView

//desc:默认显示倒计时和跳过UI

/// 开屏广告底部logo
@property (nonatomic, strong) UIImage *logoImage;


/// logo底部背景色  default：whiteColor
@property (nonatomic, strong) UIColor *logoBackgroundColor;


@end

NS_ASSUME_NONNULL_END
