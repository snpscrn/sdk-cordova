//
//  SnapscreenARSnapViewController.h
//  SnapscreenKit
//
//  Created by Martin on 09/11/2017.
//  Copyright © 2017 Snapscreen Application GmbH. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "SnapscreenSnapViewController.h"

@class SnapscreenARSnapViewController;

/**
 
 Provides callbacks from the SnapscreenARSnapViewController during the snapping process
 
 */
@protocol SnapscreenARSnapViewControllerDelegate<NSObject>

/**
 
 The view controller perform initial setup and provides the given view for you to draw into
 
 @param snapViewController The view controller for snapping
 @param drawingView The view you can use to draw into. Covers the whole screen.
 
 */
- (void) snapscreenARViewController: (SnapscreenARSnapViewController* _Nonnull) snapViewController didPrepareDrawingView: (UIView* _Nonnull) drawingView;

/**
 
 Autosnapping did occur and found the given result (which may include more than one result entry. The result also contains the quadrangle that marks the area in view coordinates where the result was detected. Note that you will receive the same logical result multiple times in sequence if e.g. the user keeps the camera pointed at a TV. The quadrangle is continuously updated to reflect any changes in camera position.
 
 @param snapViewController The view controller for snapping
 @param result The result that autosnapping has found
 
 */
- (void) snapscreenARViewController: (SnapscreenARSnapViewController* _Nonnull) snapViewController didFindResult: (SnapscreenSearchResult* _Nonnull)result;

/**
 
 Autosnapping lost a given result.
 
 @param snapViewController The view controller for snapping
 
 */
- (void) snapscreenARViewControllerDidLoseResult: (SnapscreenARSnapViewController* _Nonnull) snapViewController;

/**
 
 The user did cancel snapping. You should dismiss the SnapscreenARSnapViewController.
 
 @param snapViewController The view controller for snapping
 
 */
- (void) snapscreenARSnapViewControllerDidCancel: (SnapscreenARSnapViewController* _Nonnull) snapViewController;

@optional

@end

/**
 
 A list of possible view finder modes
 
 */

typedef NS_ENUM(NSInteger, SnapscreenARViewFinderMode) {
    /// The default mode for AR - a square that fills the entire width in portrait and entire height in landscape.
    SnapscreenARViewFinderModeDefaultSquare = 1,
    /// The standard mode from the non-AR snap - a rectangular view finder
    SnapscreenARViewFinderModeStandardMode
};

/**
 
 SnapscreenARSnapViewController offers the snapping logic from Snapscreen to your application and enrich it via AR-like features. Instantiate via `SnapscreenKit` and then display it in your application. The recommended way to present the view controller is to present it as a modal view that covers the whole screen.
 
 Use the AR delegate callbacks to get information about the snapping process. In any case you are responsible to dismiss the view controller again.
 
 To customize the appearance of the viewfinder and zoom level indicator set the tintColor accordingly. To customize the color of the navigation bar and it's
 bar items use the default UIAppearance API calls.
 
 The snap button is automatically hidden in this view controller since AR only makes use of autosnapping.
 
 Please note that the standard SnapscreenSnapViewControllerDelegate (which is accessible via the view controller's delegate property) is not used in this case, but all relevant callbacks occur via the arDelegate.
 
 */
@interface SnapscreenARSnapViewController : SnapscreenSnapViewController

/** The AR delegate of the view controller. Never should be nil, because the delegate is responsible for dismissing the view. */
@property (weak, nullable) id<SnapscreenARSnapViewControllerDelegate> arDelegate;

/** A view covering the entire screen that can be used for drawing custom content */
@property (nonatomic, readonly, nonnull) UIView* arDrawingView;

/** The view finder mode - defaults to SnapscreenARViewfinderModeDefaultSquare */
@property (nonatomic, readonly) SnapscreenARViewFinderMode viewFinderMode;

@end

