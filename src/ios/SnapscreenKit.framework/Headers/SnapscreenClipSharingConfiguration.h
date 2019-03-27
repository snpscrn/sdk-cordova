//
//  SnapscreenClipSharingConfiguration.h
//  SnapscreenKit
//
//  Created by Martin Reichart on 26.11.18.
//  Copyright © 2018 Snapscreen Application GmbH. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class SnapscreenClipSharingTutorialContent;

/**
 
 Configuration object for customizing the appearance of the clip sharing UI.
 
 */
@interface SnapscreenClipSharingConfiguration : NSObject

/** Content to be displayed in the tutorial */
@property (nonatomic, strong) NSArray<SnapscreenClipSharingTutorialContent*>* tutorialContent;

/** Optional logo that is displayed above the tutorial content (and does not scroll with the tutorial content) */
@property (nonatomic, strong, nullable) UIImage* tutorialLogoImage;

/** Maximum Height constraint that is applied to the tutorial logo image on the tutorial page - defaults to -1 which means that the full image height is used */
@property (nonatomic, assign) CGFloat maximumTutorialLogoImageHeight;

/** Large sponsor image that is displayed */
@property (nonatomic, strong, nullable) UIImage* largeSponsorImage;

/** Small sponsor image that is displayed in the trimming UI */
@property (nonatomic, strong, nullable) UIImage* smallSponsorImage;

/** Image that is displayed as the background in the tutorial - if nil a white screen is shown */
@property (nonatomic, strong, nullable) UIImage* tutorialBackgroundImage;

/** Background Color of the main actions - defaults to rgb(0,37,68)  */
@property (nonatomic, strong) UIColor* mainButtonColor;

/** Tint color of the viewfinder - defaults to rgb(61,118,197)  */
@property (nonatomic, strong) UIColor* snapViewFinderTintColor;

/** Font of the main actions - defaults to system font 14  */
@property (nonatomic, strong) UIFont* mainButtonFont;

/** Image to be used for the manual snap button (only the centered icon - the button background color will be mainButtonColor) - defaults to the snap_icon provided with the SDK */
@property (nonatomic, strong) UIImage* snapButtonImage;

/** Title to be used for the manual snap button (show below the snapButtonImage) - defaults to localize key Snapscreen_Snap_Button_Title */
@property (nonatomic, strong, nullable) NSString* snapButtonTitle;

/** Font to be used for the title of the manual snap button (show below the snapButtonImage) - defaults to system font 14 */
@property (nonatomic, strong) UIFont* snapButtonTitleFont;

/** Text color of the main action buttons - defaults to white */
@property (nonatomic, strong) UIColor* mainButtonTextColor;

/** Text color for the tutorial text - defaults to black */
@property (nonatomic, strong) UIColor* tutorialTextColor;

/** Font for the tutorial text - defaults to system font 14 */
@property (nonatomic, strong) UIFont* tutorialFont;

/** AttributedString for the sharing introduction hint - displayed briefly on the trimming UI before switching to large sponsor image */
@property (nonatomic, strong, nullable) NSAttributedString* sharingIntroductionHint;

/** Image for the sharing introduction hint - displayed briefly on the trimming UI before switching to large sponsor image */
@property (nonatomic, strong, nullable) UIImage* sharingIntroductionHintImage;

/** Maximum Height constraint that is applied to the sponsor image - defaults to -1 which means that the full image height is used */
@property (nonatomic, assign) CGFloat maximumSponsorImageHeight;

/** Maximum Height constraint that is applied to the small sponsor image on the trimming page - defaults to -1 which means that the full image height is used */
@property (nonatomic, assign) CGFloat maximumSmallSponsorImageHeight;

@end

NS_ASSUME_NONNULL_END
