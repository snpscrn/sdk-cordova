## Installing the cordova plugin

cordova plugin add https://github.com/snpscrn/sdk-cordova.git

## Configuring the plugin

Make sure that the config.xml in your platform has the following block with the appropriate configuration for your client id and secret.

```
<feature name="Snapscreen">
	<param name="ios-package" value="Snapscreen" />
	<param name="onload" value="true" />
	<preference name="snapscreen-client-id" value="client id" />
	<preference name="snapscreen-secret" value="secret" />
	<preference name="snapscreen-test-environment" value="false" />
</feature>
```

## Sharing Clips

To start clip sharing, perform the following call in your Javascript code:

```
	snapscreen.startClipSharing(successCallback, failureCallback, {});
```

When the user cancels clip sharing the successCallback will receive an object as parameter that contains the key **result** with value *cancel*.

When the user selects a clip for sharing the successCallback will receive an object as parameter that contains the key **result** with value *share* and the keys **videoPlayerURL** and **thumbnailURL**.


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


## Support

In case of any questions or problems please contact us at [support@snapscreen.com](mailto:support@snapscreen.com).
