# Cordova Heartbeat Plugin

Although this Cordova plugin is public and open-source. You'll need a license in order to use the [Happitech SDK](http://www.happitech.com/). If you have a license you'll need to clone this repository and replace the library/framework files with the ones you'd receive from Happitech.

## Installation

To install the plugin to your Cordova project use the Cordova CLI Tool:

```
#!bash
$ cordova plugin add git+ssh://git@bitbucket.org/kroodle/cordova-plugin-heartbeat.git
```

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
  Heartbeat.on('progress', function(percentage) {
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

Please visit the [Ionic Native plugin](https://bitbucket.org/kroodle/ionic-native-heartbeat).
