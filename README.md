# Cordova Heartbeat Plugin

For now it's only iOS and private. Based on [Happitech SDK](http://www.happitech.com/).

## Installation

To install the plugin to your Cordova project use the Cordova CLI Tool:

  $ cordova plugin add git+ssh://git@bitbucket.org/kroodle/cordova-plugin-heartbeat.git

## Requirements

* `iOS`
  * iOS 6+.

## Basic Usage

### Initialization

An instance of the plugin is accessible in JavaScript as `Heartbeat`.
To start measuring use `Heartbeat.start();` and to stop measuring use `Heartbeat.stop();`

#### Full example

```javascript
onDeviceReady: function() {
  // Realtime heartbeat
  Heartbeat.on('bpm', function(bpm) {
    console.log('Realtime heartbeat is: ', bpm);
  });
  // Progress of measurement
  Heartbeat.on('percentage', function(percentage) {
    console.log('Your measurement is on: ' + percentage + '%');
  });
  // Raw values to plot a graph
  Heartbeat.on('graph', function(graph) {
    console.log('Raw graph values: ', graph);
  });
  // Status of the measurement
  Heartbeat.on('status', function(status) {
    console.log('Status: ', status);
  });
  // Measurement gives a warning
  Heartbeat.on('warning', function(warning) {
    console.log('Warning: ', warning);
  });
  // Measurement gives an error
  Heartbeat.on('error', function(error) {
    console.log('Error: ', error);
  });
  // Measurement is able to give back reliable heartbeat and hrv
  Heartbeat.on('hrv', function(hrv) {
    console.log('AVNN: ', hrv.AVNN);
    console.log('Average heartbeat: ', hrv.bpm);
  });
  // Start measurement, the measurement will stop automatically on the end.
  // No need to call `stop` unless you want to stop before the measurement is finished.
  Heartbeat.start();
});
```

#### Angular/Ionic implementation

Coming soon
