package nl.aegon.kroodle;

import android.util.Log;
import android.graphics.Bitmap;

import org.apache.cordova.CallbackContext;
import org.apache.cordova.CordovaInterface;
import org.apache.cordova.CordovaPlugin;
import org.apache.cordova.CordovaWebView;

import org.json.JSONArray;
import org.json.JSONException;

import happitech.nl.heartbeatandroid.Interface.HeartBeatListener;
import happitech.nl.heartbeatandroid.Monitor;
import happitech.nl.heartbeatandroid.models.HRV;
import happitech.nl.heartbeatandroid.models.Pulse;

public class HeartbeatPlugin extends CordovaPlugin implements HeartBeatListener {

  private final String TAG = "HeartbeatPlugin";

  private Monitor monitor;

  @Override
  public void initialize(CordovaInterface cordova, CordovaWebView webView) {
    super.initialize(cordova, webView);
    this.monitor = new Monitor(cordova.getActivity(), this, 30);
    Log.i(TAG, "initialize HeartbeatPlugin");
    this.monitor.startMeasuring();
    Log.i(TAG, "startMeasuring");
  }

  @Override
  public boolean execute(String action, final JSONArray args, final CallbackContext callbackContext) throws JSONException {
    if (action.equals("start")) {
      Log.i(TAG, "start method called");
      callbackContext.success("start method called");
      return true;
    } else {
      Log.i(TAG, "unknown method called");
      return false;
    }
  }

  // HeartbeatListener methods
  @Override
  public void onHRVReady(HRV result) {
    Log.i(TAG, String.valueOf(result));
  }

  @Override
  public void onHeartBeat(int b) {
    Log.i(TAG, String.valueOf(b));
  }

  @Override
  public void onFPSChange(long fps) {
    Log.i(TAG, String.valueOf(fps));
  }

  @Override
  public void onError(Monitor.ERROR error) {
    Log.e(TAG, String.valueOf(error));
  }

  @Override
  public void onStatusChange(Monitor.STATUS s) {
    Log.i(TAG, String.valueOf(s));
  }

  @Override
  public void onBeatSignalStrength(double signal) {
    Log.i(TAG, String.valueOf(signal));
  }

  @Override
  public void onPPGCanvasUpdate(Bitmap bitmap){

  }

  @Override
  public void onPPGDataUpdate(double[] ppgData) {
    Log.i(TAG, String.valueOf(ppgData));
  }

}
