//
//  Interpolation.h
//  Heartbeat
//
//  Created by Leon, Remi & Yosef on 29-07-15.
//  Copyright (c) 2015 Happitech. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "Filters.h"
#import "Functions.h"


@interface Interpolation : NSObject

@property (nonatomic, readwrite) int sampleBPM;
@property (nonatomic, readwrite) int minBeats;
@property (nonatomic, readwrite) float calibrationTime;
@property (nonatomic, readwrite) double prevAvgCorrelation;
@property (nonatomic, readwrite) double avgCorrelation;
@property (nonatomic, readwrite) double badSignalQualityIdentifier;
@property (nonatomic, retain) Filters * filter;
@property (nonatomic, retain) Functions * functions;
@property (nonatomic, retain) NSMutableArray * total;
@property (nonatomic, retain) NSMutableArray * beats;
@property (nonatomic, retain) NSMutableArray * rr;
@property (nonatomic, retain) NSMutableArray * rawPoints;
@property (nonatomic, readwrite) float hrv;
@property (nonatomic, readwrite) int bpm;

-(double) interpolate:(NSMutableArray *)input;
-(double)getAverageHRV;
-(double)getRMSSD;
-(NSInteger) calculateResult;
-(double)getPNN50;
-(double)getSD;
-(void)resetBeats;
- (void)addShake:(FPRange*)range;
@end
