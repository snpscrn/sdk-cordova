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

## Support

In case of any questions or problems please contact us at [support@snapscreen.com](mailto:support@snapscreen.com).
