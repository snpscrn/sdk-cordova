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
import android.text.SpannableString;
import android.util.Log;

import com.snapscreen.sdk.SnapscreenKit;
import com.snapscreen.sdk.SnapscreenKitListener;
import com.snapscreen.sdk.model.sharing.SnapscreenClipShareInformation;
import com.snapscreen.sdk.ui.ClipSharingActivity;
import com.snapscreen.sdk.ui.SnapscreenClipSharingConfiguration;
import com.snapscreen.sdk.ui.SnapscreenClipSharingTutorialContent;

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
			if (args.length() >= 3) {
                String clientID = args.optString(0);
                String secret = args.optString(1);
                boolean connectToTestEnvironment = args.optBoolean(2, false);

                String backendURL = null;
                String clipsharingBackendURL = null;
                String countryCode = null;

                if (args.length() == 4) {
                    String configurationData = args.optString(3);
                    try {
                        JSONObject configurationObject = new JSONObject(configurationData);

                        backendURL = configurationObject.optString("backendURL", null);
                        clipsharingBackendURL = configurationObject.optString("clipsharingBackendURL", null);
                        countryCode = configurationObject.optString("countryCode", null);
                    } catch (Exception ignored) {
                    }
                }

                SnapscreenKit.init(cordova.getContext(), clientID, secret, connectToTestEnvironment, backendURL, clipsharingBackendURL, new SnapscreenKitListener() {
                    @Override
                    public void snapscreenKitDidReceiveInvalidClientIdAndSecret() {
                        Log.e("Snapscreen", "SnapscreenKit initialization did fail");
                    }
                });

                if (countryCode != null) {
                    SnapscreenKit.getInstance().setCountryCode(countryCode);
                }

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

                    String sharingIntroductionHint = configurationObject.optString("sharingIntroductionHint", null);
                    if (sharingIntroductionHint != null) {
                        configuration.setSharingIntroductionHint(SpannableString.valueOf(sharingIntroductionHint));
                    }
                    int maximumTutorialLogoImageDpHeight = configurationObject.optInt("maximumTutorialLogoImageDpHeight", -1);
                    if (maximumTutorialLogoImageDpHeight != -1) {
                        configuration.setMaximumTutorialLogoImageDpHeight(maximumTutorialLogoImageDpHeight);
                    }
                    int maximumLargeSponsorImageDpHeight = configurationObject.optInt("maximumLargeSponsorImageDpHeight", -1);
                    if (maximumLargeSponsorImageDpHeight != -1) {
                        configuration.setMaximumLargeSponsorImageDpHeight(maximumLargeSponsorImageDpHeight);
                    }
                    int maximumSmallSponsorImageDpHeight = configurationObject.optInt("maximumSmallSponsorImageDpHeight", -1);
                    if (maximumSmallSponsorImageDpHeight != -1) {
                        configuration.setMaximumSmallSponsorImageDpHeight(maximumSmallSponsorImageDpHeight);
                    }

                    String largeSponsorImageResourceIdName = configurationObject.optString("largeSponsorImageResourceIdName", null);
                    if (largeSponsorImageResourceIdName != null) {
                        int largeSponsorImageResourceId = cordova.getActivity().getResources().getIdentifier(largeSponsorImageResourceIdName,"drawable", cordova.getActivity().getPackageName());
                        if (largeSponsorImageResourceId != 0) {
                            configuration.setLargeSponsorImageResourceId(largeSponsorImageResourceId);
                        }
                    }

                    String smallSponsorImageResourceIdName = configurationObject.optString("smallSponsorImageResourceIdName", null);
                    if (smallSponsorImageResourceIdName != null) {
                        int smallSponsorImageResourceId = cordova.getActivity().getResources().getIdentifier(smallSponsorImageResourceIdName,"drawable", cordova.getActivity().getPackageName());
                        if (smallSponsorImageResourceId != 0) {
                            configuration.setSmallSponsorImageResourceId(smallSponsorImageResourceId);
                        }
                    }

                    String tutorialLogoImageResourceIdName = configurationObject.optString("tutorialLogoImageResourceIdName", null);
                    if (tutorialLogoImageResourceIdName != null) {
                        int tutorialLogoImageResourceId = cordova.getActivity().getResources().getIdentifier(tutorialLogoImageResourceIdName,"drawable", cordova.getActivity().getPackageName());
                        if (tutorialLogoImageResourceId != 0) {
                            configuration.setTutorialLogoImageResourceId(tutorialLogoImageResourceId);
                        }
                    }

                    String sharingIntroductionHintImageResourceIdName = configurationObject.optString("sharingIntroductionHintImageResourceIdName", null);
                    if (sharingIntroductionHintImageResourceIdName != null) {
                        int sharingIntroductionHintImageResourceId = cordova.getActivity().getResources().getIdentifier(sharingIntroductionHintImageResourceIdName,"drawable", cordova.getActivity().getPackageName());
                        if (sharingIntroductionHintImageResourceId != 0) {
                            configuration.setSharingIntroductionHintImageResourceId(sharingIntroductionHintImageResourceId);
                        }
                    }

                    String tutorialBackgroundImageResourceIdName = configurationObject.optString("tutorialBackgroundImageResourceIdName", null);
                    if (tutorialBackgroundImageResourceIdName != null) {
                        int tutorialBackgroundImageResourceId = cordova.getActivity().getResources().getIdentifier(tutorialBackgroundImageResourceIdName,"drawable", cordova.getActivity().getPackageName());
                        if (tutorialBackgroundImageResourceId != 0) {
                            configuration.setTutorialBackgroundImageResourceId(tutorialBackgroundImageResourceId);
                        }
                    }

                    JSONArray tutorialContent = configurationObject.optJSONArray("tutorialContent");
                    if (tutorialContent != null) {
                        for (int i = 0; i < tutorialContent.length(); i++) {
                            JSONObject tutorialObject = tutorialContent.optJSONObject(i);

                            if (tutorialObject != null) {
                                String text = tutorialObject.optString("text", "");
                                String imageResourceIdName = tutorialObject.optString("imageResourceId", null);
                                if (imageResourceIdName != null) {
                                    int imageResourceId = cordova.getActivity().getResources().getIdentifier(imageResourceIdName,"drawable", cordova.getActivity().getPackageName());
                                    if (imageResourceId != 0) {
                                        configuration.getTutorialContent().add(new SnapscreenClipSharingTutorialContent(imageResourceId, text));
                                    }
                                }
                            }
                        }
                    }
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
