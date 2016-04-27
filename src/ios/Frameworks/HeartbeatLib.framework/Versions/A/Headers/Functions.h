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

- (HSV *) RGBtoHSV:(RGB *)rgb;
- (RGB *) bufferToRGB:(CMSampleBufferRef)buffer;
- (double) getAverage:(int)index forBeats:(NSArray *)list;
- (double)calculateHRV:(double)currentPulse andNextPulse:(double)next;
- (double) getReverseAverage:(int)index forBeats:(NSArray *)list;
- (void) afterFilter:(NSMutableArray *)RR atStartIndex:(int)startIndex;
- (void) finalFilter:(NSArray *)RR;
- (void) resetAfterFilter;
- (void) resetValues;
- (FPRange *)checkMovement:(NSMutableArray *)RR;
- (int)moveCount:(NSMutableArray *)values;
@end
