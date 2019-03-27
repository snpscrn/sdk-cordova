//
//  SnapscreenTvSearchResultEntry.h
//  SnapscreenKit
//
//  Created by Martin Reichart on 20/08/16.
//  Copyright © 2016 Snapscreen Application GmbH. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SnapscreenSearchResultEntry.h"

@class SnapscreenTvChannel, SnapscreenEpgUnit;

/**
 
 A single result entry from a tv search. This represents an individual program on a single channel at a certain point in time.
 
 */
@interface SnapscreenTvSearchResultEntry : SnapscreenSearchResultEntry

/** The TV channel this result is associated to */
@property (readonly, nonatomic, nonnull) SnapscreenTvChannel* channel;

/** Optional resolved EPG unit that is currently playing on this channel */
@property (readonly, nonatomic, nonnull) SnapscreenEpgUnit* epgUnit;

/** The unix timestamp (milliseconds since 1.1.1970) that represents the recognized frame */
@property (readonly, nonatomic) long long timestamp;

/** A relative delta to the current snapscreen timestamp - use this for very exact syncing with the backend by adding to ```[SnapscreenKit currentSnapscreenTimestamp]``` */
@property (readonly, nonatomic) long long snapscreenTimestampDelta;

@end
