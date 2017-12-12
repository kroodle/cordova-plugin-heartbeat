//
//  FFT.h
//  HeartbeatLib
//
//  Created by Leon Boon on 05/10/16.
//  Copyright © 2016 Clockwork. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface FFT : NSObject

@property (nonatomic, readwrite) int lowBPM;
@property (nonatomic, readwrite) double lowMag;
@property (nonatomic, readwrite) int lowIndex;
@property (nonatomic, readwrite) double lowCor;

@property (nonatomic, readwrite) int higBPM;
@property (nonatomic, readwrite) double higMag;
@property (nonatomic, readwrite) int higIndex;
@property (nonatomic, readwrite) double higCor;

@property (nonatomic, readwrite) double BPM;
@property (nonatomic, readwrite) double magnitude;
@property (nonatomic, readwrite) double correlation;
@property (nonatomic, readwrite) int index;

@property (nonatomic, readwrite) int NFFT;


@end
