#import <HeartbeatLib/HeartbeatLib.h>
#import "HeartbeatLib/Pulse.h"
#import "HeartbeatPlugin.h"

@interface HeartbeatPlugin()<HeartBeatDelegate>

@property (copy, nonatomic) NSString *mainCallbackId;
@property (strong, nonatomic) NSMutableArray *resultQueue;
@property (strong, nonatomic) HeartbeatLib *lib;
@property (nonatomic, assign) HeartBeatStatus currentStatus;

@end

@implementation HeartbeatPlugin

#define kPluginVersion @"1.0.0"

- (void)pluginInitialize {

  [self setResultQueue:[[NSMutableArray alloc] init]];
  [self setLib:[[HeartbeatLib alloc] init]];
  [[self lib] setDelegate:self];
}

- (void)start:(CDVInvokedUrlCommand*)command {

  [[self lib] start];

  [self setMainCallbackId:[command callbackId]];
  CDVPluginResult* pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK];
  [pluginResult setKeepCallback:[NSNumber numberWithBool:YES]];
  [[self commandDelegate] sendPluginResult:pluginResult callbackId:[command callbackId]];
}

- (void)stop:(CDVInvokedUrlCommand*)command {

  [[self lib] stop];

  CDVPluginResult* pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK];
  [[self commandDelegate] sendPluginResult:pluginResult callbackId:[command callbackId]];
}

#pragma callback methods

- (void)sendResultQueue {

  for (CDVPluginResult *pluginResult in _resultQueue) {
    [[self commandDelegate] sendPluginResult:pluginResult callbackId:_mainCallbackId];
  }
  [_resultQueue removeAllObjects];
}

- (void)sendErrorResultWithType:(NSString *)type andMessage:(NSString *)message {
  if (message != nil) {
    CDVPluginResult *pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:message];
    [pluginResult setKeepCallback:[NSNumber numberWithBool:YES]];
    if (_mainCallbackId != nil) {
      [[self commandDelegate] sendPluginResult:pluginResult callbackId:_mainCallbackId];
    } else {
      [_resultQueue addObject:pluginResult];
    }
  }
}

- (void)sendSuccessResult:(NSDictionary *)payload {
  if (payload != nil) {
    CDVPluginResult *pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsDictionary:payload];
    [pluginResult setKeepCallback:[NSNumber numberWithBool:YES]];
    if (_mainCallbackId != nil) {
      [[self commandDelegate] sendPluginResult:pluginResult callbackId:_mainCallbackId];
    } else {
      [_resultQueue addObject:pluginResult];
    }
  }
}

- (void)sendSuccessResultWithType:(NSString *)type andDictionary:(NSDictionary *)data {
  if (type != nil && data != nil) {
    NSDictionary *payload = @{@"type": type, @"data": data};
    [self sendSuccessResult:payload];
  }
}

- (void)sendSuccessResultWithType:(NSString *)type andArray:(NSArray *)data {
  if (type != nil && data != nil) {
    NSDictionary *payload = @{@"type": type, @"data": data};
    [self sendSuccessResult:payload];
  }
}

- (void)sendSuccessResultWithType:(NSString *)type andString:(NSString *)data {
  if (type != nil && data != nil) {
    NSDictionary *payload = @{@"type": type, @"data": data};
    [self sendSuccessResult:payload];
  }
}

- (void)sendSuccessResultWithType:(NSString *)type andNumber:(NSNumber *)data {
  if (type != nil && data != nil) {
    NSDictionary *payload = @{@"type": type, @"data": data};
    [self sendSuccessResult:payload];
  }
}

#pragma HeartbeatLibDelegate

- (void)onPercentageCompleted:(int)percentage {
  dispatch_async(dispatch_get_main_queue(), ^{
    [self sendSuccessResultWithType:@"percentage" andNumber:[NSNumber numberWithInt:percentage]];
  });
}

- (void)onStatusChange:(HeartBeatStatus)status {
  dispatch_async(dispatch_get_main_queue(), ^{
    NSString *statusString = @"";
    switch (status) {
      case STARTED:
        statusString = @"STARTED";
        break;
      case NO_FINGER:
        statusString = @"NO_FINGER";
        break;
      case FINGER_DETECTED:
        statusString = @"FINGER_DETECTED";
        break;
      case CALIBRATING:
        statusString = @"CALIBRATING";
        break;
      case MEASURING:
        statusString = @"MEASURING";
        break;
      case COMPLETED:
        statusString = @"COMPLETED";
        break;
      default:
        statusString = @"ERROR";
        break;
    }
    self.currentStatus = status;
    [self sendSuccessResultWithType:@"status" andString:statusString];
  });
}

- (void)onWarning:(HeartBeatWarning)warning {
  dispatch_async(dispatch_get_main_queue(), ^{
    NSString * warningString = @"";
    switch(warning) {
      case SHAKING:
        warningString = @"SHAKING";
      break;
      case LOW_QUALITY:
        warningString = @"LOW_QUALITY";
      break;
      default:
      break;
    }
    if ([warningString length] > 0) {
      [self sendSuccessResultWithType:@"warning" andString:warningString];
    }
  });
}

- (void)onHeartBeat:(int)bpm {
  dispatch_async(dispatch_get_main_queue(), ^{
    [self sendSuccessResultWithType:@"bpm" andNumber:[NSNumber numberWithInt:bpm]];
  });
}

- (void)onError:(HeartBeatError)error {
  dispatch_async(dispatch_get_main_queue(), ^{
    NSString * errorString = @"";
    switch (error) {
      case NO_FINGER_DETECTED:
        errorString = @"NO_FINGER_DETECTED";
        break;
      case CAMERA_HAS_NO_PERMISSION:
        errorString = @"CAMERA_HAS_NO_PERMISSION";
        break;
      case FINGER_PRESSURE:
        errorString = @"FINGER_PRESSURE";
        break;
      case BAD_FINGER_POSITION:
        errorString = @"BAD_FINGER_POSITION";
        break;
      case TO_MUCH_MOVEMENT:
        errorString = @"TOO_MUCH_MOVEMENT";
        break;
      default:
        break;
    }
    if ([errorString length] > 0) {
      [self sendErrorResultWithType:@"error" andMessage:errorString];
    }
  });
}

- (void)onGraphArrayUpdated:(NSArray *)points {
  dispatch_async(dispatch_get_main_queue(), ^{
    NSMutableArray *array = [[NSMutableArray alloc] init];
    for(float i = 0; i < points.count;i++) {
      Pulse *pulse = (Pulse *)[points objectAtIndex:i];
      [array addObject:@(pulse.value)];
    }
    [self sendSuccessResultWithType:@"graph" andArray:[NSArray arrayWithArray:array]];
  });
}

- (void)onHRVReady:(HRV *)hrv {
  dispatch_async(dispatch_get_main_queue(), ^{
    [self sendSuccessResultWithType:@"hrv" andDictionary:@{@"avnn": @(hrv.AVNN), @"bpm": [NSNumber numberWithInt:hrv.bpm]}];
  });
}

@end
