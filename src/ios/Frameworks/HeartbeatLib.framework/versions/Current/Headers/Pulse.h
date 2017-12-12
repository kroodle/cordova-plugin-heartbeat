//
//  Pulse.h
//  Heartbeat
//
//  Created by Leon, Remi & Yosef on 14-07-15.
//  Copyright (c) 2015 Happitech. All rights reserved.
//

#import <Foundation/Foundation.h>
@interface Pulse : NSObject<NSCopying>

/*! @brief Filtered red value (could also be hue */
@property (nonatomic, readwrite) double value;


#pragma mark - HSV values
/*! @brief Hue (HSV) */
@property (nonatomic, readwrite) float h;
/*! @brief Saturation (HSV) */
@property (nonatomic, readwrite) float s;
/*! @brief Value (HSV) */
@property (nonatomic, readwrite) float v;
#pragma mark - RGB values
/*! @brief Red (HSV) */
@property (nonatomic, readwrite) float r;
/*! @brief Green (HSV) */
@property (nonatomic, readwrite) float g;
/*! @brief Blue (HSV) */
@property (nonatomic, readwrite) float b;
#pragma mark -

/*! @brief Beats per minute */
@property (nonatomic, readwrite) float bpm;
/*! @brief Beats per minute */
@property (nonatomic, readwrite) CFTimeInterval time;
/*! @brief Beats per minute */
@property (nonatomic, retain) NSDate* date;
/*! @brief Beats per minute */
@property (nonatomic, readwrite) BOOL isBeat;
/*! @brief Beats per minute */
@property (nonatomic, readwrite) BOOL processed;
/*! @brief Beats per minute */
@property (nonatomic, readwrite) BOOL isInvalid;
/*! @brief Beats per minute */
@property (nonatomic, readwrite) float drawScale;
/*! @brief Beats per minute */
@property (nonatomic, readwrite) double RR;
/*! @brief Beats per minute */
@property (nonatomic, readwrite) double x;
/*! @brief Beats per minute */
@property (nonatomic, readwrite) double y;
/*! @brief Beats per minute */
@property (nonatomic, readwrite) double z;
/*! @brief Beats per minute */
@property (nonatomic, readwrite) int index;
/*! @brief Beats per minute */
@property (nonatomic, readwrite) int originalIndex;
/*! @brief Beats per minute */
@property (nonatomic, readwrite) int change;
/*! @brief Beats per minute */
@property (nonatomic, readwrite) int shake;
/*! @brief Beats per minute */
@property (nonatomic, readwrite) BOOL drawLineStart;
/*! @brief Beats per minute */
@property (nonatomic, readwrite) BOOL drawLineEnd;
/*! @brief Beats per minute */
@property (nonatomic, readwrite) double correlation;

- (instancetype)initWithPulse:(float)number andDate:(NSDate *)date;

@end
