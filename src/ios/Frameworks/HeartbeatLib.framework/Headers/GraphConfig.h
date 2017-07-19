//
//  GraphConfig.h
//  HeartbeatLib
//
//  Created by Leon Boon on 18/04/16.
//  Copyright © 2016 Happitech. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
@interface GraphConfig : NSObject


@property (nonatomic, readwrite) CGRect frame;
@property (nonatomic, readwrite) UIColor * backgroundColor;
@property (nonatomic, readwrite) UIColor * lineColor;
@property (nonatomic, readwrite) CGFloat lineWidth;

@end
