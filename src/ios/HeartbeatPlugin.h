#import <Cordova/CDV.h>

@interface HeartbeatPlugin : CDVPlugin

- (void)start:(CDVInvokedUrlCommand *)command;
- (void)stop:(CDVInvokedUrlCommand *)command;
- (void)setPointsForGraph:(CDVInvokedUrlCommand *)command;
- (void)setMeasureTime:(CDVInvokedUrlCommand *)command;
- (void)getBatteryLevel:(CDVInvokedUrlCommand *)command;

@end
