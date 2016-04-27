//
//  Filters.h
//  HeartbeatLib
//
//  Created by Leon, Remi & Yosef on 29-07-15.
//  Copyright (c) 2015 Happitech. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SAMCubicSpline.h"

#define NZEROS 8
#define NPOLES 8

@interface Filters : NSObject {
    float xv[NZEROS+1], yv[NPOLES+1];
}

//- (NSArray *) processArray:(NSArray *)inputData;
- (float) processValue:(float) value;

@end
