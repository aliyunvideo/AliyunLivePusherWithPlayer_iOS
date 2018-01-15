//
//  AlivcLivePusher.h
//  AlivcLiveCaptureLib
//
//  Created by TripleL on 17/7/13.
//  Copyright © 2017年 Alibaba. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "AlivcLivePushConfig.h"
#import "AlivcLivePushStatsInfo.h"
#import "AlivcLivePushError.h"


/**
 错误回调, 网络回调, 状态回调
 */
@protocol AlivcLivePusherErrorDelegate, AlivcLivePusherNetworkDelegate, AlivcLivePusherInfoDelegate, AlivcLivePusherBGMDelegate;



/**
 推流类
 */
@interface AlivcLivePusher : NSObject



/**
 显示调试悬浮窗
 * 注意 ：Debug悬浮窗会占用一定的系统资源，只可用于APP研发的Debug阶段，Release版本请勿调用此接口
 */
+ (void)showDebugView;



/**
 隐藏调试悬浮窗
 */
+ (void)hideDebugView;


/**
 init

 @param config 推流配置
 @return self:success  nil:failure
 */
- (instancetype)initWithConfig:(AlivcLivePushConfig *)config;


/**
 设置推流错误监听回调

 @param delegate AlivcLivePusherErrorDelegate
 */
- (void)setErrorDelegate:(id<AlivcLivePusherErrorDelegate>)delegate;


/**
 设置推流状态监听回调

 @param delegate AlivcLivePusherInfoDelegate
 */
- (void)setInfoDelegate:(id<AlivcLivePusherInfoDelegate>)delegate;


/**
 设置推流网络监听回调

 @param delegate AlivcLivePusherNetworkDelegate
 */
- (void)setNetworkDelegate:(id<AlivcLivePusherNetworkDelegate>)delegate;


/**
 设置背景音乐监听回调

 @param delegate AlivcLivePusherBGMDelegate
 */
- (void)setBGMDelegate:(id<AlivcLivePusherBGMDelegate>)delegate;


/**
 开始预览 同步接口

 @param previewView 预览view
 @return 0:success  非0:failure
 */
- (int)startPreview:(UIView *)previewView;


/**
 停止预览

 @return 0:success  非0:failure
 */
- (int)stopPreview;


/**
 开始推流 同步接口

 @param pushURL 推流URL
 @return 0:success  非0:failure
 */
- (int)startPushWithURL:(NSString *)pushURL;


/**
 停止推流
 
 @return 0:success  非0:failure
 */
- (int)stopPush;


/**
 重新推流 同步接口

 @return 0:success  非0:failure
 */
- (int)restartPush;


/**
 暂停推流
 
 @return 0:success  非0:failure
 */
- (int)pause;



/**
 恢复推流 同步接口

 @return 0:success  非0:failure
 */
- (int)resume;


/**
 重连 异步接口

 @return 0:success  非0:failure
 */
- (int)reconnectPushAsync;


/**
 销毁推流
 */
- (void)destory;



/* ***********************异步接口*********************** */
/**
 开始预览 异步接口
 
 @param preview 预览view
 @return 0:success  非0:failure
 */
- (int)startPreviewAsync:(UIView *)preview;


/**
 开始推流 异步接口
 
 @param pushURL 推流URL
 @return 0:success  非0:failure
 */
- (int)startPushWithURLAsync:(NSString *)pushURL;


/**
 重新推流 异步接口
 
 @return 0:success  非0:failure
 */
- (int)restartPushAsync;


/**
 恢复推流 异步接口
 
 @return 0:success  非0:failure
 */
- (int)resumeAsync;

/* ****************************************************** */



/**
 旋转摄像头
 
 @return 0:success  非0:failure
 */
- (int)switchCamera;


/**
 设置自动对焦
 
 @param autoFocus true:自动对焦 false:手动对焦
 @return 0:success  非0:failure
 */
- (int)setAutoFocus:(bool)autoFocus;


/**
 对焦
 
 @param point 对焦的点
 @param autoFocus 是否自动对焦
 @return 0:success  非0:failure
 */
- (int)focusCameraAtAdjustedPoint:(CGPoint)point autoFocus:(bool)autoFocus;


/**
 缩放
 
 @param zoom 缩放值[0:MaxZoom]
 @return 0:success  非0:failure
 */
- (int)setZoom:(float)zoom;


/**
 获取支持的最大变焦值
 
 @return 最大变焦值
 */
- (float)getMaxZoom;


/**
 获取当前变焦值
 
 @return 当前变焦值
 */
- (int)getCurrentZoom;


/**
 闪光灯开关
 
 @param flash true:打开闪光灯 false:关闭闪光灯
 @return 0:success  非0:failure
 */
- (int)setFlash:(bool)flash;


/**
 设置曝光度
 
 @param value 曝光度
 @return 0:success  非0:failure
 */
- (int)setExposureValue:(float)value;


/**
 推流镜像开关
 
 @param mirror true:打开推流镜像 false:关闭推流镜像
 */
- (void)setPushMirror:(bool)mirror;


/**
 预览镜像开关
 
 @param mirror true:打开预览镜像 false:关闭预览镜像
 */
- (void)setPreviewMirror:(bool)mirror;


/**
 静音推流
 
 @param mute true:静音推流 false:正常推流
 */
- (void)setMute:(bool)mute;


/**
 设置美颜开关

 @param beautyOn true:打开美颜 false:关闭美颜
 */
- (void)setBeautyOn:(bool)beautyOn;


/**
 设置美颜 美白度

 @param value 美白度 范围0~100
 @return 0:success  非0:failure
 */
- (int)setBeautyWhite:(int)value;


/**
 设置美颜 磨皮度

 @param value 磨皮度 范围0~100
 @return 0:success  非0:failure
 */
- (int)setBeautyBuffing:(int)value;


/**
 设置美颜 红润度
 
 @param value 红润度 范围0~100
 @return 0:success  非0:failure
 */
- (int)setBeautyRuddy:(int)value;


/**
 设置美颜 瘦脸程度

 @param value 瘦脸度 范围 0~100
 @return 0:success  非0:failure
 */
- (int)setBeautyCheekPink:(int)value;


/**
 设置美颜 收下巴程度
 
 @param value 腮红度 范围 0~100
 @return 0:success  非0:failure
 */
- (int)setBeautyThinFace:(int)value;


/**
 设置美颜 大眼程度
 
 @param value 腮红度 范围 0~100
 @return 0:success  非0:failure
 */
- (int)setBeautyShortenFace:(int)value;


/**
 设置美颜 腮红度
 
 @param value 腮红度 范围 0~100
 @return 0:success  非0:failure
 */
- (int)setBeautyBigEye:(int)value;


/**
 设置推流模式

 @param qualityMode 推流模式 : 选择 ResolutionFirst 模式时，SDK内部会优先保障推流视频的清晰度; 选择 FluencyFirst 模式时，SDK内部会优先保障推流视频的流畅度，此接口只支持这两种模式。设置后码率设置失效。
 @return 0:success  非0:failure
 */
- (int)setQualityMode:(AlivcLivePushQualityMode)qualityMode;


/**
 设置目标码率

 @param targetBitrate 目标码率 [100  5000](Kbps)
 @return 0:success  非0:failure
 */
- (int)setTargetVideoBitrate:(int)targetBitrate;


/**
 设置最小码率

 @param minBitrate 最小码率 [100  5000](Kbps)
 @return 0:success  非0:failure
 */
- (int)setMinVideoBitrate:(int)minBitrate;



/* ***********************背景音乐*********************** */

/**
 播放背景音乐

 @param path 背景音乐路径
 @return 0:success  非0:failure
 */
- (int)startBGMWithMusicPathAsync:(NSString *)path;


/**
 停止播放背景音乐

 @return 0:success  非0:failure
 */
- (int)stopBGMAsync;


/**
 暂停播放背景音乐

 @return 0:success  非0:failure
 */
- (int)pauseBGM;


/**
 恢复播放背景音乐

 @return 0:success  非0:failure
 */
- (int)resumeBGM;


/**
 设置背景音乐是否循环播放

 @param isLoop 是否循环  true:循环 false:不循环
 @return 0:success  非0:failure
 */
- (int)setBGMLoop:(bool)isLoop;


/**
 设置背景音乐耳返开关

 @param isOpen 是否打开耳返  true:开启耳返 false:关闭耳返
 @return 0:success  非0:failure
 */
- (int)setBGMEarsBack:(bool)isOpen;


/**
 设置降噪开关
 
 @param isOpen 是否打开降噪 true:开启 false:关闭 默认:false
 @return 0:success  非0:failure
 */
- (int)setAudioDenoise:(bool)isOpen;


/**
 设置背景音乐混音 音乐音量

 @param volume 音乐音量大小 范围:[0 ~ 100] 默认:50
 @return 0:success  非0:failure
 */
- (int)setBGMVolume:(int)volume;


/**
 设置背景音乐混音 人声音量

 @param volume 人声音量大小 范围:[0 ~ 100] 默认:50
 @return 0:success  非0:failure
 */
- (int)setCaptureVolume:(int)volume;

/* ****************************************************** */


/**
 获取是否正在推流

 @return YES:正在推流 NO:未推流
 */
- (BOOL)isPushing;


/**
 获取当前推流URL

 @return 推流URL
 */
- (NSString *)getPushURL;


/**
 获取推流数据统计

 @return 推流数据
 */
- (AlivcLivePushStatsInfo *)getLivePushStatusInfo;


/**
 设置Log级别

 @param level Log级别 default:AlivcLivePushLogLevelError
 @return 0:success  非0:failure
 */
- (int)setLogLevel:(AlivcLivePushLogLevel)level;


/**
 获取SDK版本号

 @return 版本号
 */
- (NSString *)getSDKVersion;

@end



@protocol AlivcLivePusherErrorDelegate <NSObject>

@required

/**
 系统错误回调

 @param pusher 推流AlivcLivePusher
 @param error error
 */
- (void)onSystemError:(AlivcLivePusher *)pusher error:(AlivcLivePushError *)error;


/**
 SDK错误回调

 @param pusher 推流AlivcLivePusher
 @param error error
 */
- (void)onSDKError:(AlivcLivePusher *)pusher error:(AlivcLivePushError *)error;

@end



@protocol AlivcLivePusherNetworkDelegate <NSObject>

@required

/**
 网络差回调

 @param pusher 推流AlivcLivePusher
 */
- (void)onNetworkPoor:(AlivcLivePusher *)pusher;


/**
 推流链接失败

 @param pusher 推流AlivcLivePusher
 @param error error
 */
- (void)onConnectFail:(AlivcLivePusher *)pusher error:(AlivcLivePushError *)error;


/**
 网络恢复

 @param pusher 推流AlivcLivePusher
 */
- (void)onConnectRecovery:(AlivcLivePusher *)pusher;


/**
 重连开始回调
 
 @param pusher 推流AlivcLivePusher
 */
- (void)onReconnectStart:(AlivcLivePusher *)pusher;


/**
 重连成功回调
 
 @param pusher 推流AlivcLivePusher
 */
- (void)onReconnectSuccess:(AlivcLivePusher *)pusher;


/**
 重连失败回调

 @param pusher 推流AlivcLivePusher
 @param error error
 */
- (void)onReconnectError:(AlivcLivePusher *)pusher error:(AlivcLivePushError *)error;


/**
 发送数据超时
 
 @param pusher 推流AlivcLivePusher
 */
- (void)onSendDataTimeout:(AlivcLivePusher *)pusher;

@end




@protocol AlivcLivePusherInfoDelegate <NSObject>

@optional


- (void)onPreviewStarted:(AlivcLivePusher *)pusher;



/**
 停止预览回调

 @param pusher 推流AlivcLivePusher
 */
- (void)onPreviewStoped:(AlivcLivePusher *)pusher;


/**
 渲染第一帧回调

 @param pusher 推流AlivcLivePusher
 */
- (void)onFirstFramePreviewed:(AlivcLivePusher *)pusher;


/**
 推流开始回调
 
 @param pusher 推流AlivcLivePusher
 */
- (void)onPushStarted:(AlivcLivePusher *)pusher;


/**
 推流暂停回调
 
 @param pusher 推流AlivcLivePusher
 */
- (void)onPushPauesed:(AlivcLivePusher *)pusher;


/**
 推流恢复回调
 
 @param pusher 推流AlivcLivePusher
 */
- (void)onPushResumed:(AlivcLivePusher *)pusher;


/**
 重新推流回调

 @param pusher 推流AlivcLivePusher
 */
- (void)onPushRestart:(AlivcLivePusher *)pusher;


/**
 推流停止回调
 
 @param pusher 推流AlivcLivePusher
 */
- (void)onPushStoped:(AlivcLivePusher *)pusher;

@end


@protocol AlivcLivePusherBGMDelegate <NSObject>

@required

/**
 背景音乐开始播放

 @param pusher 推流AlivcLivePusher
 */
- (void)onStarted:(AlivcLivePusher *)pusher;


/**
 背景音乐停止播放

 @param pusher 推流AlivcLivePusher
 */
- (void)onStoped:(AlivcLivePusher *)pusher;


/**
 背景音乐暂停播放

 @param pusher 推流AlivcLivePusher
 */
- (void)onPaused:(AlivcLivePusher *)pusher;


/**
 背景音乐恢复播放

 @param pusher 推流AlivcLivePusher
 */
- (void)onResumed:(AlivcLivePusher *)pusher;


/**
 背景音乐当前播放进度

 @param pusher 推流AlivcLivePusher
 @param progress 播放时长
 @param duration 总时长
 */
- (void)onProgress:(AlivcLivePusher *)pusher progress:(long)progress duration:(long)duration;


/**
 背景音乐播放完毕

 @param pusher 推流AlivcLivePusher
 */
- (void)onCompleted:(AlivcLivePusher *)pusher;


/**
 背景音乐开启失败

 @param pusher 推流AlivcLivePusher
 */
- (void)onOpenFailed:(AlivcLivePusher *)pusher;


/**
 背景音乐下载播放超时

 @param pusher 推流AlivcLivePusher
 */
- (void)onDownloadTimeout:(AlivcLivePusher *)pusher;


@end
