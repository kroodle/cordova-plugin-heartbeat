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
#import "Beat.h"
@protocol HeartBeatDelegate <NSObject>

@required
- (void)onHRVReady:(HRV *)hrv;
- (void)onError:(HeartBeatError)error;
- (void)onWarning:(HeartBeatWarning)error;
- (void)onStatusChange:(HeartBeatStatus)status;
- (void)onHeartBeat:(int) bpm;
@optional
- (void)onHeartBeatHR:(HR *)hr;
- (void)onGraphUpdated:(UIView *)view;
- (void)onGraphArrayUpdated:(NSArray *)array;
- (void)onPercentageCompleted:(int)percentage;

@end

@interface HeartbeatLib : NSObject<CameraDelegate>

@property (nonatomic, retain) Camera * camera;
@property (nonatomic, retain) id<HeartBeatDelegate> delegate;
@property (nonatomic, readwrite) double measureTime;
@property (nonatomic, readwrite) int pointsForGraph;
@property (nonatomic, retain) NSMutableArray * total;
@property (nonatomic, retain) NSMutableArray * beats;
@property (nonatomic, retain) NSMutableArray * fftPoints;
@property (nonatomic, retain) NSMutableArray * rawPoints;
@property (nonatomic, assign) HRSettingsType hrSettingsType;

- (void)start;
- (void)stop;
- (AVCaptureVideoPreviewLayer *) preview:(CGRect)frame;
- (Graph *)enableGraph:(GraphConfig *)config;
- (Beat *)getHeartbeatAfter:(int)seconds since:(NSDate*)date;
@end
