//
//  HRV.h
//  HeartbeatLib
//
//  Created by Leon, Remi & Yosef on 21/07/15.
//  Copyright (c) 2015 Happitech. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface HRV : NSObject

@property (nonatomic, readwrite) double sd;
@property (nonatomic, readwrite) double rMSSD;
@property (nonatomic, readwrite) double pNN50;
@property (nonatomic, readwrite) double AVNN;
@property (nonatomic, readwrite) int bpm;

@end
