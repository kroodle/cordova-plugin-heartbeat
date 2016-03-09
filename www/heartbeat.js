var exec = require('cordova/exec');

function Heartbeat(){}

Heartbeat.prototype.start = function(success, fail){
  exec(success, fail, 'Heartbeat', 'start', []);
};

Heartbeat.prototype.stop = function(){
  exec(success, fail, 'Heartbeat', 'stop', []);
};

module.exports = new Heartbeat();
