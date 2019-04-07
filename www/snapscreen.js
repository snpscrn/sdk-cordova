var exec = require('cordova/exec');

var snapscreen = {
    startClipSharing: function (success, failure, configurationData) {
      exec(success, failure, "Snapscreen", "startClipSharing", [JSON.stringify(configurationData)]);
    },
    initialize: function (success, failure, clientID, secret, connectToTestEnvironment) {
      exec(success, failure, "Snapscreen", "initialize", [clientID, secret, connectToTestEnvironment]);
    }
};

module.exports = snapscreen;
