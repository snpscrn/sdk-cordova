## Installing the cordova plugin

cordova plugin add https://github.com/snpscrn/sdk-cordova.git

## Configuring & initalizing the plugin

We suggest that you initialize the SDK as soon as your application starts and you get the deviceReady callbacks from Cordova. Perform the following call in your javascript code to initialize the SDK:

```
	snapscreen.initialize(null, null, "client-id", "secret", <true/false - connect to test environment>);
```

## Sharing Clips

To start clip sharing, perform the following call in your Javascript code:

```
	snapscreen.startClipSharing(successCallback, failureCallback, {});
```

When the user cancels clip sharing the successCallback will receive an object as parameter that contains the key **result** with value *cancel*.

When the user selects a clip for sharing the successCallback will receive an object as parameter that contains the key **result** with value *share* and the keys **videoPlayerURL** and **thumbnailURL**.

A sample code for handling the callbacks looks like this:

```
	let clipsharingSuccessCallback = function(data) {
		if (data['result'] === 'cancel') {
			alert('Cancelled');
		} else if (data['result'] === 'share') {
			alert('Sharing');
		}
	}

	let clipsharingFailureCallback = function(error) {
		console.log(error);
	}
	
	snapscreen.startClipSharing(clipsharingSuccessCallback, clipsharingFailureCallback, {mainButtonColor: 'ff0000'});
```

### Passing configuration parameters

To pass configuration parameters, use the third parameter of the startClipSharing method to pass in a map with the following possible parameters:

* *tutorialLogoImage*: Asset name for a tutorial logo image - will be loaded with [UIImage imageNamed: tutorialLogoImage];
* *maximumTutorialLogoImageHeight*: Number with maximum tutorial logo image height in points
* *largeSponsorImage*: Asset name for a large sponsor image image - will be loaded with [UIImage imageNamed: tutorialLogoImage];
* *smallSponsorImage*: Asset name for a small sponsor image - will be loaded with [UIImage imageNamed: tutorialLogoImage];
* *tutorialBackgroundImage*: Asset name for a tutorial background image - will be loaded with [UIImage imageNamed: tutorialLogoImage];
* *snapButtonImage*: Asset name for a snap button image - will be loaded with [UIImage imageNamed: tutorialLogoImage];
* *snapButtonTitle*: Title for the snap button
* *sharingIntroductionHintImage*: Asset name for a sharing introduction hint image - will be loaded with [UIImage imageNamed: tutorialLogoImage];
* *maximumSponsorImageHeight*: Number with maximum sponsor image image height in points
* *maximumSmallSponsorImageHeight*: Number with maximum small sponsor image height in points
* *tutorialContent*: An array of tutorial content entries with each being a map that contains *image* (asset name for an image for that tutorial page) and *text*
* *mainButtonColor*: Main Button color in hex (without the leading #)
* *snapViewFinderTintColor*: Snap View Finder color in hex (without the leading #)
* *mainButtonTextColor*: Main Button Text Color in Hex (without the leading #)
* *tutorialTextColor*: Tutorial text color in Hex (without the leading #)


### Logging

When run in debug mode - the SDK will log various detailed log statements on iOS via NSLog or on Android via the Log API.

## Support

In case of any questions or problems please contact us at [support@snapscreen.com](mailto:support@snapscreen.com).
