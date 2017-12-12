//
//  FPRange.h
//  HeartbeatLib
//
//  Created by Leon Boon on 19-04-16.
//  Copyright © 2016 Happitech. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface FPRange : NSObject


@property (nonatomic, readwrite) double start;
@property (nonatomic, readwrite) double end;
@property (nonatomic, readwrite) BOOL move;
@end
