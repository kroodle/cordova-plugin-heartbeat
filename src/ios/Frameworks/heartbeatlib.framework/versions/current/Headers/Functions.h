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

@interface Functions : NSObject


@property (nonatomic, readwrite) int i;
@property (nonatomic, readwrite) int k;
@property (nonatomic, readwrite) int change;
@property (nonatomic, readwrite) double corrected;

- (HSV *) RGBtoHSV:(RGB *)rgb;
- (RGB *) bufferToRGB:(CMSampleBufferRef)buffer;
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
@end
