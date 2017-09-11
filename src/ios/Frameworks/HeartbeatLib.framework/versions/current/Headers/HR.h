//
//  HR.h
//  HeartbeatLib
//
//  Created by Leon Boon on 06/10/16.
//  Copyright © 2016 Clockwork. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface HR : NSObject

@property (nonatomic, readwrite) int BPM;
@property (nonatomic, readwrite) double timestamp;
@property (nonatomic, readwrite) double correlation;
@property (nonatomic, readwrite) double FFT;

@end
