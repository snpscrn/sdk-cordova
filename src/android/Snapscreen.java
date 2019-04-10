package com.snapscreen.cordova;

import org.apache.cordova.CallbackContext;
import org.apache.cordova.CordovaPlugin;
import org.apache.cordova.PluginResult;
import org.apache.cordova.PluginResult.Status;
import org.json.JSONArray;
import org.json.JSONObject;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.util.Log;

import com.snapscreen.sdk.SnapscreenKit;
import com.snapscreen.sdk.SnapscreenKitListener;
import com.snapscreen.sdk.model.sharing.SnapscreenClipShareInformation;
import com.snapscreen.sdk.ui.ClipSharingActivity;
import com.snapscreen.sdk.ui.SnapscreenClipSharingConfiguration;

public class Snapscreen extends CordovaPlugin {

    private static final int SNAPSCREEN_CLIPSHARING_REQUEST_CODE = 919;

    private CallbackContext currentCallbackContext;

    @Override
    public void onRestoreStateForActivityResult(Bundle state, CallbackContext callbackContext) {
        super.onRestoreStateForActivityResult(state, callbackContext);
    }

    @Override
    public void onActivityResult(int requestCode, int resultCode, Intent intent) {
        super.onActivityResult(requestCode, resultCode, intent);

        if (requestCode == SNAPSCREEN_CLIPSHARING_REQUEST_CODE) {
            if (resultCode == Activity.RESULT_OK) {
                if (this.currentCallbackContext != null) {
                    JSONObject obj = new JSONObject();

                    SnapscreenClipShareInformation shareInformation = intent.getParcelableExtra(ClipSharingActivity.SHAREINFORMATION_RESULT_KEY);

                    try {
                        obj.put("result", "share");
                        if (shareInformation != null) {
                            obj.put("videoPlayerURL", shareInformation.getVideoPlayerURL());
                            obj.put("thumbnailURL", shareInformation.getThumbnailURL());
                        }
                    } catch (Exception ignored) {
                    }

                    PluginResult pluginResult = new PluginResult(Status.OK);
                    this.currentCallbackContext.sendPluginResult(pluginResult);

                    this.currentCallbackContext = null;
                }
            } else {
                if (this.currentCallbackContext != null) {
                    JSONObject obj = new JSONObject();

                    try {
                        obj.put("result", "cancel");
                    } catch (Exception ignored) {
                    }

                    PluginResult pluginResult = new PluginResult(Status.OK);
                    this.currentCallbackContext.sendPluginResult(pluginResult);

                    this.currentCallbackContext = null;
                }
            }
        }
    }

    @Override
    public boolean execute(String action, JSONArray args, CallbackContext callbackContext) {
		if (action.equals("initialize")) {
			if (args.length() == 3) {
                String clientID = args.optString(0);
                String secret = args.optString(1);
                boolean connectToTestEnvironment = args.optBoolean(2, false);

                SnapscreenKit.init(cordova.getContext(), clientID, secret, connectToTestEnvironment, new SnapscreenKitListener() {
                    @Override
                    public void snapscreenKitDidReceiveInvalidClientIdAndSecret() {
                        Log.e("Snapscreen", "SnapscreenKit initialization did fail");
                    }
                });

                PluginResult pluginResult = new PluginResult(Status.OK);
                callbackContext.sendPluginResult(pluginResult);
            } else {
                PluginResult pluginResult = new PluginResult(Status.ERROR, "Missing initialization parameters");
                callbackContext.sendPluginResult(pluginResult);
            }

            return true;
		} else if (action.equals("startClipSharing")) {
		    if (args.length() > 0) {
                this.currentCallbackContext = callbackContext;

                SnapscreenClipSharingConfiguration configuration = new SnapscreenClipSharingConfiguration();

                String configurationData = args.optString(0);
                try {
                    JSONObject configurationObject = new JSONObject(configurationData);
                    
                } catch (Exception ignored){}

                Intent intent = new Intent(cordova.getActivity(), ClipSharingActivity.class);
                intent.putExtra(ClipSharingActivity.CONFIGURATION_EXTRA_KEY, configuration);
                cordova.startActivityForResult(this, intent, SNAPSCREEN_CLIPSHARING_REQUEST_CODE);

                PluginResult pluginResult = new PluginResult(Status.OK);
                pluginResult.setKeepCallback(true);
                callbackContext.sendPluginResult(pluginResult);
            } else {
                PluginResult pluginResult = new PluginResult(Status.ERROR);
                callbackContext.sendPluginResult(pluginResult);
            }

            return true;
		}

        // Unrecognized command
        return false;
    }
}
