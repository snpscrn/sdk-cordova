#import "Snapscreen.h"
#import <SnapscreenKit/SnapscreenKit.h>
#import <Cordova/CDVViewController.h>

@interface Snapscreen()<SnapscreenClipSharingDelegate>
@property (nonatomic, copy, nullable) NSString* callbackId;
@end

@implementation Snapscreen

- (void)pluginInitialize {
    NSString* clientID = [[[self commandDelegate] settings] objectForKey: @"snapscreen-client-id"];
    NSString* secret = [[[self commandDelegate] settings] objectForKey: @"snapscreen-secret"];
    BOOL connectToTestEnvironment = [[[[self commandDelegate] settings] objectForKey: @"snapscreen-test-environment"] boolValue];
    [SnapscreenKit sharedSnapscreenKitWithClientID: clientID clientSecret: secret testEnvironment: connectToTestEnvironment loggingHandler: nil locationProvider: nil delegate: nil];
}

- (void)startClipSharing:(CDVInvokedUrlCommand*)command {
    if ([command.arguments count] > 0) {
        NSString* configurationData = [command argumentAtIndex: 0];
        NSData* data = [configurationData dataUsingEncoding:NSUTF8StringEncoding];
        NSDictionary* configurationDictionary = [NSJSONSerialization JSONObjectWithData: data options:NSJSONReadingAllowFragments error: nil];
        if (configurationDictionary) {
            
            
            self.callbackId = command.callbackId;
            
            SnapscreenClipSharingConfiguration* configuration = [SnapscreenClipSharingConfiguration new];
            
            SnapscreenClipSharingNavigationController* sharingNavigationController = [[SnapscreenClipSharingNavigationController alloc] initWithConfiguration: configuration delegate: self];
            [self.viewController presentViewController: sharingNavigationController animated: YES completion: nil];
            
            CDVPluginResult* pluginResult = [CDVPluginResult resultWithStatus: CDVCommandStatus_OK];
            [pluginResult setKeepCallback: [NSNumber numberWithBool: YES]];
            [self.commandDelegate sendPluginResult:pluginResult callbackId: command.callbackId];
            
            return;
        }
    }
    
    CDVPluginResult* pluginResult = [CDVPluginResult resultWithStatus: CDVCommandStatus_ERROR];
    [self.commandDelegate sendPluginResult:pluginResult callbackId: command.callbackId];
}

- (void)clipSharingViewControllerDidCancel:(SnapscreenClipSharingViewController *)sharingViewController {
    if (self.callbackId != nil) {
        CDVPluginResult* pluginResult = [CDVPluginResult resultWithStatus: CDVCommandStatus_NO_RESULT messageAsDictionary:@{@"result":@"cancel"}];
        [self.commandDelegate sendPluginResult:pluginResult callbackId:self.callbackId];
        self.callbackId = nil;
    }
    [sharingViewController dismissViewControllerAnimated: YES completion: nil];
}

- (void)clipSharingViewController:(SnapscreenClipSharingViewController *)sharingViewController didShareVideoSnippet:(SnapscreenClipShareInformation *)shareInformation {
    if (self.callbackId != nil) {
        CDVPluginResult* pluginResult = [CDVPluginResult resultWithStatus: CDVCommandStatus_OK messageAsDictionary:@{@"result":@"share", @"videoPlayerURL" : shareInformation.videoPlayerURL.absoluteString, @"thumbnailURL" : shareInformation.thumbnailURL.absoluteString}];
        [self.commandDelegate sendPluginResult:pluginResult callbackId:self.callbackId];
        self.callbackId = nil;
    }
    [sharingViewController dismissViewControllerAnimated: YES completion: nil];
}

@end
