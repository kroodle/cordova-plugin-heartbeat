#import <Cordova/CDV.h>

@interface HeartbeatPlugin : CDVPlugin <UIApplicationDelegate>

- (void)start:(CDVInvokedUrlCommand *)command;
- (void)stop:(CDVInvokedUrlCommand *)command;

@end
