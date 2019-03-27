//
//  SnapscreenClipSharingNavigationController.h
//  SnapscreenKit
//
//  Created by Martin Reichart on 28.11.18.
//  Copyright © 2018 Snapscreen Application GmbH. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class SnapscreenClipSharingConfiguration;
@protocol SnapscreenClipSharingDelegate;

/**
 
 Navigation Controller that contains a SnapscreenClipSharingViewController if you want to present the UI with a NavigationBar.
 
 You can customize the NavigationBar and the NavigationItem of the rootViewController as preferred - by default the SnapscreenClipSharingViewController adds a Cancel item if presented modally.
 
 */
@interface SnapscreenClipSharingNavigationController : UINavigationController

/**
 Initialize the view controller with a sharing configuration and a delegate that receives the callbacks at the end of the sharing process.
 
 @param configuration the sharing configuration
 @param delegate the delegate to receive callbacks
 
 */
- (instancetype) initWithConfiguration: (SnapscreenClipSharingConfiguration*) configuration delegate: (id<SnapscreenClipSharingDelegate>) delegate;

@end

NS_ASSUME_NONNULL_END
