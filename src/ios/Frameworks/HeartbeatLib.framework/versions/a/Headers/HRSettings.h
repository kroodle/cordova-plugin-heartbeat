//
//  HRSettings.h
//  HeartbeatLib
//
//  Created by Nico Liu on 22/09/2016.
//  Copyright © 2016 Clockwork. All rights reserved.
//

#import <Foundation/Foundation.h>

#define PASSES 9

typedef enum NSInteger {
    HRSettingsTypeLow,
    HRSettingsTypeMedium,
    HRSettingsTypeHigh
} HRSettingsType;

@interface HRSettings : NSObject

@property(nonatomic, readwrite) int sampleBPM;
@property(nonatomic, readwrite) double numPulseBeforePeak;
@property(nonatomic, readwrite) int timeBlockBeats;
@property(nonatomic, readwrite) double minBPM;
@property(nonatomic, readwrite) double maxBPM;
@property(nonatomic, readwrite) double correlationThreshold;
@property(nonatomic, readwrite) double sampleRate;
@property(nonatomic, readwrite) int minBeats;
@property(nonatomic, readwrite) double defaultTimeSlotBPM;
@property(nonatomic, readwrite) double timeslotBPMDiffPercentage;
@property(nonatomic, readwrite) HRSettingsType settingsType;
@property(nonatomic, retain) NSMutableArray * filter;
@property(nonatomic, retain) NSMutableArray<NSNumber *> * a;
@property(nonatomic, retain) NSMutableArray<NSNumber *> * b;

+ (HRSettings *)sharedSettings;

@end
