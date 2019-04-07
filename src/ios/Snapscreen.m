#import "Snapscreen.h"
#import <SnapscreenKit/SnapscreenKit.h>
#import <Cordova/CDVViewController.h>

@interface Snapscreen()<SnapscreenClipSharingDelegate, SnapscreenKitDelegate>
@property (nonatomic, copy, nullable) NSString* callbackId;
@end

@implementation Snapscreen

- (void) initialize:(CDVInvokedUrlCommand*)command {
    if ([command.arguments count] == 3) {
        NSString* clientID = [command argumentAtIndex: 0];
        NSString* secret = [command argumentAtIndex: 1];
        BOOL connectToTestEnvironment = [[command argumentAtIndex: 2] boolValue];
        
        id<SnapscreenLoggingHandler> loggingHandler = nil;
        #ifdef DEBUG
        loggingHandler = [SnapscreenNSLogLoggingHandler new];
        #endif
        [SnapscreenKit sharedSnapscreenKitWithClientID: clientID clientSecret: secret testEnvironment: connectToTestEnvironment loggingHandler: loggingHandler locationProvider: nil delegate: self];
        
        CDVPluginResult* pluginResult = [CDVPluginResult resultWithStatus: CDVCommandStatus_OK];
        [self.commandDelegate sendPluginResult:pluginResult callbackId: command.callbackId];
    } else {
        CDVPluginResult* pluginResult = [CDVPluginResult resultWithStatus: CDVCommandStatus_ERROR messageAsString: @"Missing initialization parameters"];
        [self.commandDelegate sendPluginResult:pluginResult callbackId: command.callbackId];
    }
}

- (void)snapscreenKitDidFailWithError:(NSError *)error {
    NSLog(@"SnapscreenKit initialization did fail with error %@", error);
}

-  (UIColor *) snapscreenColorFromHexString:(NSString *)hex {
    if (hex == nil) {
        return nil;
    }
    
    NSScanner *scanner = [NSScanner scannerWithString:hex];
    unsigned int tempInt;
    [scanner scanHexInt:&tempInt];
    
    return [UIColor colorWithRed:((tempInt>>16)&0xFF)/255.0 green:((tempInt>>8)&0xFF)/255.0    blue:(tempInt&0xFF)/255.0    alpha:1.0];
}

- (void)startClipSharing:(CDVInvokedUrlCommand*)command {
    if ([command.arguments count] > 0) {
        NSString* configurationData = [command argumentAtIndex: 0];
        NSData* data = [configurationData dataUsingEncoding:NSUTF8StringEncoding];
        NSDictionary* configurationDictionary = [NSJSONSerialization JSONObjectWithData: data options:NSJSONReadingAllowFragments error: nil];
        if (configurationDictionary) {
            self.callbackId = command.callbackId;
            
            SnapscreenClipSharingConfiguration* configuration = [SnapscreenClipSharingConfiguration new];
            
            NSString* tutorialLogoImageName = [configurationDictionary objectForKey: @"tutorialLogoImage"];
            if (tutorialLogoImageName) {
                configuration.tutorialLogoImage = [UIImage imageNamed: tutorialLogoImageName];
            }
            NSNumber* maximumTutorialLogoImageHeight = [configurationDictionary objectForKey: @"maximumTutorialLogoImageHeight"];
            if (maximumTutorialLogoImageHeight) {
                configuration.maximumTutorialLogoImageHeight = [maximumTutorialLogoImageHeight floatValue];
            }
            NSString* largeSponsorImageName = [configurationDictionary objectForKey: @"largeSponsorImage"];
            if (largeSponsorImageName) {
                configuration.largeSponsorImage = [UIImage imageNamed: largeSponsorImageName];
            }
            NSString* smallSponsorImageName = [configurationDictionary objectForKey: @"smallSponsorImage"];
            if (smallSponsorImageName) {
                configuration.smallSponsorImage = [UIImage imageNamed: smallSponsorImageName];
            }
            NSString* tutorialBackgroundImageName = [configurationDictionary objectForKey: @"tutorialBackgroundImage"];
            if (tutorialBackgroundImageName) {
                configuration.tutorialBackgroundImage = [UIImage imageNamed: tutorialBackgroundImageName];
            }
            NSString* snapButtonImageName = [configurationDictionary objectForKey: @"snapButtonImage"];
            if (snapButtonImageName) {
                configuration.snapButtonImage = [UIImage imageNamed: snapButtonImageName];
            }
            NSString* snapButtonTitle = [configurationDictionary objectForKey: @"snapButtonTitle"];
            if (snapButtonTitle) {
                configuration.snapButtonTitle = snapButtonTitle;
            }
            NSString* sharingIntroductionHintImageName = [configurationDictionary objectForKey: @"sharingIntroductionHintImage"];
            if (sharingIntroductionHintImageName) {
                configuration.sharingIntroductionHintImage = [UIImage imageNamed: sharingIntroductionHintImageName];
            }
            NSNumber* maximumSponsorImageHeight = [configurationDictionary objectForKey: @"maximumSponsorImageHeight"];
            if (maximumSponsorImageHeight) {
                configuration.maximumSponsorImageHeight = [maximumSponsorImageHeight floatValue];
            }
            NSNumber* maximumSmallSponsorImageHeight = [configurationDictionary objectForKey: @"maximumSmallSponsorImageHeight"];
            if (maximumSmallSponsorImageHeight) {
                configuration.maximumSmallSponsorImageHeight = [maximumSmallSponsorImageHeight floatValue];
            }
            
            NSArray* tutorialContent = [configurationDictionary objectForKey: @"tutorialContent"];
            if (tutorialContent) {
                NSMutableArray* tutorialContentArray = [NSMutableArray new];
                for (NSObject* content in tutorialContent) {
                    if ([content isKindOfClass: [NSDictionary class]]) {
                        NSDictionary* contentDictionary = (NSDictionary*) content;
                        NSString* imageName = [contentDictionary objectForKey: @"image"];
                        NSString* text = [contentDictionary objectForKey: @"text"];
                        if (imageName) {
                            UIImage* tutorialImage = [UIImage imageNamed: imageName];
                            if (tutorialImage && text) {
                                [tutorialContentArray addObject: [SnapscreenClipSharingTutorialContent contentWithImage: tutorialImage text: text]];
                            }
                        }
                    }
                }
            }
            
            NSString* mainButtonColorHex = [configurationDictionary objectForKey: @"mainButtonColor"];
            if (mainButtonColorHex) {
                configuration.mainButtonColor = [self snapscreenColorFromHexString: mainButtonColorHex];
            }
            
            NSString* snapViewFinderTintColorHex = [configurationDictionary objectForKey: @"snapViewFinderTintColor"];
            if (snapViewFinderTintColorHex) {
                configuration.snapViewFinderTintColor = [self snapscreenColorFromHexString: snapViewFinderTintColorHex];
            }
            
            NSString* mainButtonTextColorHex = [configurationDictionary objectForKey: @"mainButtonTextColor"];
            if (mainButtonTextColorHex) {
                configuration.mainButtonTextColor = [self snapscreenColorFromHexString: mainButtonTextColorHex];
            }
            
            NSString* tutorialTextColorHex = [configurationDictionary objectForKey: @"tutorialTextColor"];
            if (tutorialTextColorHex) {
                configuration.tutorialTextColor = [self snapscreenColorFromHexString: tutorialTextColorHex];
            }
            
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
        CDVPluginResult* pluginResult = [CDVPluginResult resultWithStatus: CDVCommandStatus_OK messageAsDictionary:@{@"result":@"cancel"}];
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
