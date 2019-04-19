var exec = require('cordova/exec');

var snapscreen = {
    startClipSharing: function (success, failure, configurationData) {
      exec(success, failure, "Snapscreen", "startClipSharing", [JSON.stringify(configurationData)]);
    },
    initialize: function (success, failure, clientID, secret, connectToTestEnvironment, additionalConfigurationData) {
      exec(success, failure, "Snapscreen", "initialize", [clientID, secret, connectToTestEnvironment, JSON.stringify(additionalConfigurationData)]);
    }
};

module.exports = snapscreen;
