//
//  SnapscreenSnapViewController.h
//  SnapscreenKit
//
//  Created by Martin Reichart on 20/08/16.
//  Copyright © 2016 Snapscreen Application GmbH. All rights reserved.
//

#import <UIKit/UIKit.h>

@class SnapscreenSnapViewController, SnapscreenSearchResult, SnapscreenSearchResultEntry;

/**

 Provides callback from the SnapscreenSnapViewController during the snapping process.
 
 */
@protocol SnapscreenSnapViewControllerDelegate<NSObject>

/**
 
 Snapping did occur and did find at least one result. You should dismiss the UI in this case and continue in your application's flow that uses the snap result. 

 @param snapResult The result of the snap. Contains at least one result entry.
 @param selectedResultEntry The selected entry of the snap.
 
 */
- (void) snapscreenDidSnapResult: (SnapscreenSearchResult* _Nonnull) snapResult selectedResultEntry: (SnapscreenSearchResultEntry* _Nonnull) selectedResultEntry;

/**
 
 Snapping did occur but did not yield any results. The SnapscreenSnapViewController presents an inline error in the UI in that case and you may decide to keep on snapping or dismiss the view controller.
 
 @param snapViewController The view controller for snapping
 
 */
- (void) snapscreenSnapViewControllerDidSnapNoResults: (SnapscreenSnapViewController* _Nonnull) snapViewController;

/**
 
 Snapping did fail with an error and is most likely to not succeed subsequently as well. You should dismiss the SnapscreenSnapViewController and present an error to the user.
 
 @param snapViewController The view controller for snapping
 @param error The error that occured. Might be null or not contain relevant information.
 
 */
- (void) snapscreenSnapViewController: (SnapscreenSnapViewController* _Nonnull) snapViewController didFailWithError: (NSError* _Nullable) error;

/**
 
 The user did cancel snapping. You should dismiss the SnapscreenSnapViewController.
 
 @param snapViewController The view controller for snapping
 
 */
- (void) snapscreenSnapViewControllerDidCancel: (SnapscreenSnapViewController* _Nonnull) snapViewController;

@end

/**
 
 SnapscreenSnapViewController offers the snapping logic from Snapscreen to your application. Instantiate via `SnapscreenKit` and then display it in your application. The recommended way to present the view controller is to present it as a modal view that covers the whole screen.
 
 Use the delegate callbacks to get information about the snapping process. In any case you are responsible to dismiss the view controller again.
 
 To customize the appearance of the viewfinder, zoom level indicator and snap button, set the tintColor or the snapButtonImage accordingly. To customize the color of the navigation bar and it's
 bar items use the default UIAppearance API calls.   
 
 */
@interface SnapscreenSnapViewController : UIViewController

/** The delegate of the view controller. Never should be nil, because the delegate is responsible for dismissing the view. */
@property (weak, nullable) id<SnapscreenSnapViewControllerDelegate> delegate;

/** The tint color to apply to the view finder and zoom level indicator. Defauts to the snapscreen corporate blue. **/
@property (nonatomic, nullable, strong) UIColor* tintColor;

/** The image to use as the snap button. Defaults to a standard camera icon in snapscreen corporate blue. **/
@property (nonatomic, nullable, strong) UIImage* snapButtonImage;

@end
