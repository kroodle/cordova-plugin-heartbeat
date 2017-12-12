//
//  Functions.h
//  HeartbeatLib
//
//  Created by Leon, Remi & Yosef on 29-07-15.
//  Copyright (c) 2015 Happitech. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreMedia/CoreMedia.h>

#import "FPRange.h"
#import "HSV.h"
#import "RGB.h"
#include <stdlib.h>

@class Pulse;
@class FFT;
@class Value;
@class LeastSquare;

@interface Functions : NSObject
@property (nonatomic, readwrite) int i;
@property (nonatomic, readwrite) int k;
@property (nonatomic, readwrite) int change;
@property (nonatomic, readwrite) double corrected;

- (NSMutableArray <RGB *> *) splitBufferInPartsToRGB:(CMSampleBufferRef)buffer numOfParts:(int)parts;
- (NSArray<HSV *> *) RGBtoHSV:(NSArray<RGB *> *)rgbs;
- (double) getAverage:(int)index forBeats:(NSArray *)list;
- (double)calculateHRV:(double)currentPulse andNextPulse:(double)next;
- (NSMutableArray *) newAfterFilter:(NSMutableArray *)input atStartIndex:(int)startIndex;
- (NSMutableArray *) afterFilter:(NSMutableArray *)RR atStartIndex:(int)startIndex;
- (NSMutableArray *) finalFilter:(NSArray *)input atStartIndex:(int)startIndex;
- (void) resetAfterFilter;
- (void) resetValues;
- (FPRange *)checkMovement:(NSMutableArray *)RR;
- (int)moveCount:(NSMutableArray *)values;
- (double)getBatteryPercentage;

- (double)meanRmssd:(NSMutableArray *)RR;
- (BOOL) getIrregularity:(NSMutableArray *)RR;

- (FFT *)checkFFTForPulses:(NSArray <Pulse *> *)pulses;
- (LeastSquare *)leastSquare:(NSMutableArray<Value *> *)values forTime:(double)time andAVNN:(double)avnn;
@end
