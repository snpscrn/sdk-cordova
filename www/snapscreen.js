var exec = require('cordova/exec');

var snapscreen = {
    startClipSharing: function (success, failure, configurationData) {
      exec(success, failure, "Snapscreen", "startClipSharing", [JSON.stringify(configurationData)]);
    }
};

module.exports = snapscreen;
