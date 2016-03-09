#import "HeartbeatPlugin.h"

// @interface HeartbeatPlugin()<HeartBeatDelegate>
//
// @end

@implementation HeartbeatPlugin

- (void)pluginInitialize {
  NSLog(@"Initializing HeartbeatPlugin");
  // [[HeartbeatLib shared] new];
  // [[HeartbeatLib shared] setDelegate:self];

  dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(5.0 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
    [self onHeartBeat:75];
  });
}

- (void)start:(CDVInvokedUrlCommand*)command {
  NSLog(@"Heartbeat start");
  // [[HeartbeatLib shared] start]];
  CDVPluginResult* pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK];
  [[self commandDelegate] sendPluginResult:pluginResult callbackId:[command callbackId]];
}

- (void)stop:(CDVInvokedUrlCommand*)command {
  NSLog(@"Heartbeat stop");
  // [[HeartbeatLib shared] stop]];
  CDVPluginResult* pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK];
  [[self commandDelegate] sendPluginResult:pluginResult callbackId:[command callbackId]];
}

- (void)onHeartBeat:(int)bpm {
  NSLog(@"Heartbeat onHeartBeat");
  CDVPluginResult *pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsInt:bpm];
  // [pluginResult setKeepCallbackAsBool:YES];
  [[self commandDelegate] sendPluginResult:pluginResult callbackId:[command callbackId]];
}


@end
