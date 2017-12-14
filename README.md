# Cordova Heartbeat Plugin

Although this Cordova plugin is public and open-source. You'll need a license for the [Happitech SDK](http://www.happitech.com/) in order to use it.
If you have a license you'll need to clone this repository and replace the library/framework files with the ones you received from Happitech.
Their SDK checks if the bundle identifier is valid, the SDK in this repository only works for `nl.aegon.fitkroodle` and `com.aegonlife.aegonfit`.

## Installation

To install the plugin to your Cordova project use the Cordova CLI Tool:

```
#!bash
$ cordova plugin add cordova-plugin-heartbeat
```

## Basic Usage

### Initialization

An instance of the plugin is accessible in JavaScript as `Heartbeat`.
To start measuring use `Heartbeat.start();` and to stop measuring use `Heartbeat.stop();`

#### Full example

```javascript
onDeviceReady: function() {
	// Realtime heartrate
  Heartbeat.on('hr', function(hr) {
    console.log('Correlation of heartbeat is:', hr.correlation);
    console.log('Timestamp of heartbeat is:', hr.timestamp);
    console.log('Heartbeat is:', hr.bpm);
  });
  // Realtime bpm
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

#### Available methods
```javascript
	// Start measuring, camera and flash will go on
	Heartbeat.start();
	// Force stop of measurement
	Heartbeat.stop();
	// Duration in seconds of the measurement, minimum of 20-30 seconds is required for trusthworthy measurement
	// Default is 30
	Heartbeat.setMeasureTime(integer);
	// IOS ONLY: set amount of points for graph
	// Default is 500
	Heartbeat.setPointsForGraph(integer);
	// ANDROID ONLY: get battery level, because you can't use camera in Android if battery level is low
	// so you could use this method to check up front
	Heartbeat.getBatteryLevel();
```

#### Angular/Ionic implementation

Please visit the [Ionic Native plugin](https://github.com/kroodle/ionic-native-heartbeat).
