//
//  SnapscreenAdvertisementSearchResultEntry.h
//  SnapscreenKit
//
//  Created by Martin Reichart on 08/02/2017.
//  Copyright © 2017 Snapscreen Application GmbH. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SnapscreenSearchResultEntry.h"

@class SnapscreenAdvertisement;

/** 
 
 A single result entry from an advertisement search. This represent an individual advertisement at a certain point in time
 
 */
@interface SnapscreenAdvertisementSearchResultEntry : SnapscreenSearchResultEntry

/** The advertisement this result is associated to */
@property (readonly, nonatomic, nonnull) SnapscreenAdvertisement* advertisement;

/** The relative offset from the start of the ad in milliseconds for the recognized frame */
@property (readonly, nonatomic) long long offset;

/** The relative offset from the start of the ad in seconds for the recognized frame */
@property (readonly, nonatomic, nullable) NSNumber* offsetInSeconds;

@end
