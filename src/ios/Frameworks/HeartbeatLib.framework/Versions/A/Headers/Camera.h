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
    FINGER_ERROR,
    CAMERA_HAS_NO_PERMISSION,
    BAD_FINGER_POSITION,
    TOO_MUCH_MOVEMENT
};

typedef NS_ENUM(NSInteger, HeartBeatStatus) {
    STARTED,
    FINGER_DETECTED,
    CALIBRATING,
    MEASURING,
    COMPLETED,
    ERROR,
    NO_FINGER,
    INACCURATE_MEASUREMENT,
    FINGER_PLACEMENT
};

typedef NS_ENUM(NSInteger, HeartBeatWarning) {
    NO_WARNING,
    SHAKING,
    LOW_QUALITY,
    LOW_BATTERY
};

@class Value;

@protocol CameraDelegate
- (void)statusChanged:(HeartBeatStatus)status;
- (void)warningOccured:(HeartBeatWarning)error;
- (void)errorOccured:(HeartBeatError)error;
- (void)percentageUpdated:(int)percentage;
- (void)graphUpdated:(NSArray *)array;
- (void)returnBPM:(HR *)bpm;
@end

@interface Camera : NSObject<AVCaptureVideoDataOutputSampleBufferDelegate>

@property (nonatomic, retain) Interpolation * interpolation;
@property (nonatomic, retain) id<CameraDelegate> delegate;
@property (nonatomic, readwrite) double measureTime;
@property (nonatomic, readwrite) NSInteger validBeats;
@property (nonatomic, retain) NSDate * measureInitialTime;
@property (nonatomic, readwrite) int confidenceLevel;
@property (nonatomic, retain) NSString * resultString;
@property (nonatomic, retain) NSMutableArray <Value *> * values;

- (void)startMeasuring;
- (void)stopMeasure;
- (AVCaptureVideoPreviewLayer *)preview:(CGRect)frame;

@end
