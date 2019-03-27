//
//  SnapscreenClipSharingTutorialContent.h
//  SnapscreenKit
//
//  Created by Martin Reichart on 26.11.18.
//  Copyright © 2018 Snapscreen Application GmbH. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/**
 
 Configuration object of a single page in the tutorial
 
 */
@interface SnapscreenClipSharingTutorialContent : NSObject

/** The image for the tutorial page */
@property (nonatomic, readonly) UIImage* image;

/** The text for the tutorial page shown below the image */
@property (nonatomic, readonly, nullable) NSString* text;

/** The attributed text for the tutorial page shown the image */
@property (nonatomic, readonly, nullable) NSAttributedString* attributedText;

/**
 
 Initializer for tutorial page with an image and attributed text
 
 @param image the image
 @param text the text
 @return content object for that page
 
 */
+ (SnapscreenClipSharingTutorialContent*) contentWithImage: (UIImage*) image text: (NSString*) text;

/**
 
 Initializer for tutorial page with an image and attributed text
 
 @param image the image
 @param attributedText the attributed text
 @return content object for that page
 
 */
+ (SnapscreenClipSharingTutorialContent*) contentWithImage: (UIImage*) image attributedText: (NSAttributedString*) attributedText;

@end

NS_ASSUME_NONNULL_END
