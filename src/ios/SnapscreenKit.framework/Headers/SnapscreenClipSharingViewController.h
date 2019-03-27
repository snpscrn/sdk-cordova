//
//  SnapscreenClipSharingViewController.h
//  SnapscreenKit
//
//  Created by Martin Reichart on 26.11.18.
//  Copyright © 2018 Snapscreen Application GmbH. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class SnapscreenClipSharingViewController, SnapscreenClipSharingConfiguration, SnapscreenClipShareInformation;

/**
 
 Delegate for callbacks during the clip sharing process.
 
 */
@protocol SnapscreenClipSharingDelegate<NSObject>
/**
 
 The user cancelled the sharing process. This callback will only be received if the sharing view is presented modally and the navigation item to dismiss was not modified.
 
 @param sharingViewController the view controller
 
 */
- (void) clipSharingViewControllerDidCancel: (SnapscreenClipSharingViewController*) sharingViewController;

/**
 
 The user completed the sharing process and selected a clip to share.
 
 @param sharingViewController the view controller
 @param shareInformation the share information containing necessary information about the shared clip
 
 */
- (void) clipSharingViewController: (SnapscreenClipSharingViewController*) sharingViewController didShareVideoSnippet: (SnapscreenClipShareInformation*) shareInformation;
@end

/**
 
 ViewController to present clip sharing. Automatically presents the tutorial if necessary, guides the user through snapping and presents a clip sharing UI at the end.
 
 Pass the appropriate styling information and tutorial content via the configuration and implement the delegate to receive callbacks during the sharing process.
 
 */
@interface SnapscreenClipSharingViewController : UIViewController

/**
 Initialize the view controller with a sharing configuration and a delegate that receives the callbacks at the end of the sharing process.
 
 @param configuration the sharing configuration
 @param delegate the delegate to receive callbacks
 
 */
- (instancetype) initWithConfiguration: (SnapscreenClipSharingConfiguration*) configuration delegate: (id<SnapscreenClipSharingDelegate>) delegate;

@end

NS_ASSUME_NONNULL_END
