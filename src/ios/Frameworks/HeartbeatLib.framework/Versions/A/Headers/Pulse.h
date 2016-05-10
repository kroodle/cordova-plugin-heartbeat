//
//  Pulse.h
//  Heartbeat
//
//  Created by Leon, Remi & Yosef on 14-07-15.
//  Copyright (c) 2015 Happitech. All rights reserved.
//

#import <Foundation/Foundation.h>
@interface Pulse : NSObject<NSCopying>

@property (nonatomic, readwrite) double value;
@property (nonatomic, readwrite) double avg;
@property (nonatomic, readwrite) double original;
@property (nonatomic, readwrite) float h;
@property (nonatomic, readwrite) float s;
@property (nonatomic, readwrite) float v;
@property (nonatomic, readwrite) float r;
@property (nonatomic, readwrite) float g;
@property (nonatomic, readwrite) float b;
@property (nonatomic, readwrite) float bpm;
@property (nonatomic, readwrite) CFTimeInterval time;
@property (nonatomic, retain) NSDate* date;
@property (nonatomic, readwrite) BOOL isBeat;
@property (nonatomic, readwrite) BOOL processed;
@property (nonatomic, readwrite) BOOL isInvalid;
@property (nonatomic, readwrite) float drawScale;
@property (nonatomic, readwrite) double RR;
@property (nonatomic, readwrite) double x;
@property (nonatomic, readwrite) double y;
@property (nonatomic, readwrite) double z;
@property (nonatomic, readwrite) int index;
@property (nonatomic, readwrite) int originalIndex;
@property (nonatomic, readwrite) int change;
@property (nonatomic, readwrite) int shake;
@property (nonatomic, readwrite) BOOL drawLineStart;
@property (nonatomic, readwrite) BOOL drawLineEnd;
@property (nonatomic, readwrite) double correlation;
- (instancetype)initWithPulse:(float)number andDate:(NSDate *)date;

@end
