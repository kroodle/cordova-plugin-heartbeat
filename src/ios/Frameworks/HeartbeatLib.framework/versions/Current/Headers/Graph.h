//
//  Graph.h
//  HeartbeatLib
//
//  Created by Leon Boon on 18/04/16.
//  Copyright © 2016 Happitech. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "GraphConfig.h"

@interface Graph : UIView

@property (nonatomic, readwrite) GraphConfig * config;

- (void)pointsUpdated:(NSArray *)array;

@end
