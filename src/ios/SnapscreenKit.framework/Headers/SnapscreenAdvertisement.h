//
//  SnapscreenAdvertisement.h
//  SnapscreenKit
//
//  Created by Martin Reichart on 08/02/2017.
//  Copyright © 2017 Snapscreen Application GmbH. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 
 Represents an advertisement

 */
@interface SnapscreenAdvertisement : NSObject

/** The unique ID of this advertisement - intended for internal purposes only */
@property (readonly, nonatomic) long long advertisementId;

/** The title of the advertisement */
@property (readonly, nullable) NSString* advertisementTitle;

/** The description of the advertisement */
@property (readonly, nullable) NSString* advertisementDescription;

/** The landing page URL this advertisements points to */
@property (readonly, nullable) NSURL* landingPageURL;

/** The duration of the advertisement in seconds or nil if not available */
@property (readonly, nullable) NSNumber* duration;

@end
