#import <Foundation/Foundation.h>
#import <Cordova/CDVPlugin.h>
#import <SnapscreenKit/SnapscreenKit.h>

@interface Snapscreen : CDVPlugin {
}

- (void) startClipSharing:(CDVInvokedUrlCommand*)command;
- (void) initialize:(CDVInvokedUrlCommand*)command;

@end
