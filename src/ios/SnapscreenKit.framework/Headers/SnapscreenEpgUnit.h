//
//  SnapscreenEpgUnit.h
//  SnapscreenKit
//
//  Created by Martin Reichart on 19/05/2017.
//  Copyright © 2017 Snapscreen Application GmbH. All rights reserved.
//

#import <Foundation/Foundation.h>

@class SnapscreenEpgUnitCredits;

/**
 
 Represents a programme of the electronic programme guide (EPG) of a TV channel
 
 */
@interface SnapscreenEpgUnit : NSObject

/** Unique internal identifier for this EPG unit */
@property (readonly, nonatomic) long long programmId;

/** Snapscreen-internal identifier of the TV channel this EPG unit is on */
@property (readonly, nonatomic) long long channelId;

/** Current start timestamp of this EPG unit */
@property (readonly, nonatomic, nullable) NSDate* startTime;

/** End time for this epg unit */
@property (readonly, nonatomic, nullable) NSDate* endTime;

/** Title of the EPG unit */
@property (readonly, nonatomic, nullable) NSString* title;

/** Subtitle of the EPG unit */
@property (readonly, nonatomic, nullable) NSString* subtitle;

/** Full description of this EPG unit */
@property (readonly, nonatomic, nullable) NSString* programmDescription;

/** Date when the EPG unit was first aired */
@property (readonly, nonatomic, nullable) NSDate* productionDate;

/** The credits for this epg unit */
@property (readonly, nonatomic, nonnull) SnapscreenEpgUnitCredits* credits;

/** A List of genres that match this EPG unit */
@property (readonly, nonatomic, nonnull) NSArray<NSString*>* genres;

/** Keywords for this EPG unit */
@property (readonly, nonatomic, nonnull) NSArray<NSString*>* keywords;

/** the banner URL of this EPG unit. */
@property (readonly, nonatomic, nullable) NSString* bannerUrl;

/** Optional poster URL for this EPG unit */
@property (readonly, nonatomic, nullable) NSString* posterUrl;

@end
