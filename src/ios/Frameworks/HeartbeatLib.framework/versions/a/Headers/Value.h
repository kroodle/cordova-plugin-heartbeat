//
//  Value.h
//  HeartbeatLib
//
//  Created by Nico Liu on 30/09/2016.
//  Copyright © 2016 Clockwork. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface Value : NSObject

@property (nonatomic, readwrite) double time;
@property (nonatomic, readwrite) int fftHRLow;
@property (nonatomic, readwrite) int fftHRHigh;
@property (nonatomic, readwrite) int bpmHR;
@property (nonatomic, readwrite) double correlationLow;
@property (nonatomic, readwrite) double correlationHigh;
@property (nonatomic, readwrite) double magnitudeLow;
@property (nonatomic, readwrite) double magnitudeHigh;
@property (nonatomic, readwrite) int step;
@property (nonatomic, readwrite) int bpmRaw;
@property (nonatomic, readwrite) double timeSlotBPM;
@end
