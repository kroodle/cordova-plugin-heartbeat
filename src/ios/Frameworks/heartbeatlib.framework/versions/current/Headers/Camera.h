//
//  Camera.h
//  HeartbeatLib
//
//  Created by Leon, Remi & Yosef on 29-07-15.
//  Copyright (c) 2015 Happitech. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <QuartzCore/QuartzCore.h>
#import <AVFoundation/AVFoundation.h>
#import <CoreMotion/CoreMotion.h>
#include <stdlib.h>
#import "Functions.h"
#import "Interpolation.h"
#import "GraphConfig.h"
typedef NS_ENUM(NSInteger, HeartBeatError) {
    NO_FINGER_DETECTED,
    CAMERA_HAS_NO_PERMISSION,
    FINGER_PRESSURE,
    BAD_FINGER_POSITION,
    TO_MUCH_MOVEMENT
};

typedef NS_ENUM(NSInteger, HeartBeatStatus) {
    STARTED,
    FINGER_DETECTED,
    CALIBRATING,
    MEASURING,
    COMPLETED,
    ERROR,
    NO_FINGER,
    INACCURATE_MEASUREMENT
};

typedef NS_ENUM(NSInteger, HeartBeatWarning) {
    NO_WARNING,
    SHAKING,
    LOW_QUALITY,
    LOW_BATTERY
};



@protocol CameraDelegate
- (void)statusChanged:(HeartBeatStatus)status;
- (void)warningOccured:(HeartBeatWarning)error;
- (void)errorOccured:(HeartBeatError)error;
- (void)percentageUpdated:(int)percentage;
- (void)graphUpdated:(NSArray *)array;
- (void)returnBPM:(NSInteger)bpm;
@end

@interface Camera : NSObject<AVCaptureVideoDataOutputSampleBufferDelegate>

@property (nonatomic, retain) Interpolation * interpolation;
@property (nonatomic, retain) id<CameraDelegate> delegate;
@property (nonatomic, readwrite) double measureTime;
@property (nonatomic, retain) NSString * resultString;

- (void)startMeasuring;
- (void)stopMeasure;
- (AVCaptureVideoPreviewLayer *)preview:(CGRect)frame;

@end
