//
//  SnapscreenClipShareInformation.h
//  SnapscreenKit
//
//  Created by Martin Reichart on 27.11.18.
//  Copyright © 2018 Snapscreen Application GmbH. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 
 Information about a shared clip.
 
 */
@interface SnapscreenClipShareInformation : NSObject

/** The URL to the Web Video Player for playing the shared clip */
@property (nonatomic, readonly) NSURL* videoPlayerURL;

/** The URL for a thumbnail of the shared clip */
@property (nonatomic, readonly) NSURL* thumbnailURL;

@end

NS_ASSUME_NONNULL_END
