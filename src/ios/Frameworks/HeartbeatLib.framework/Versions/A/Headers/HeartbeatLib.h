//
//  HeartbeatLib.h
//  HeartbeatLib
//  Created by Leon, Remi & Yosef on 21/07/15.
//  Copyright (c) 2015 Happitech. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "HRV.h"
#import "Camera.h"
#import "Graph.h"
@protocol HeartBeatDelegate <NSObject>

@required
- (void)onHRVReady:(HRV *)hrv;
- (void)onError:(HeartBeatError)error;
- (void)onWarning:(HeartBeatWarning)error;
- (void)onStatusChange:(HeartBeatStatus)status;
- (void)onHeartBeat:(int) bpm;
@optional
- (void)onGraphUpdated:(UIView *)view;
- (void)onGraphArrayUpdated:(NSArray *)array;
- (void)onPercentageCompleted:(int)percentage;

@end

@interface HeartbeatLib : NSObject<CameraDelegate>

@property (nonatomic, retain) Camera * camera;
@property (nonatomic, retain) id<HeartBeatDelegate> delegate;
@property (nonatomic, readwrite) double measureTime;

- (void)start;
- (void)stop;
- (AVCaptureVideoPreviewLayer *) preview:(CGRect)frame;
- (Graph *)enableGraph:(GraphConfig *)config;
@end
