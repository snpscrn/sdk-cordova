//
//  SnapscreenTvChannel.h
//  SnapscreenKit
//
//  Created by Martin Reichart on 20/08/16.
//  Copyright © 2016 Snapscreen Application GmbH. All rights reserved.
//

#import <Foundation/Foundation.h>

@class SnapscreenEpgUnit, SnapscreenSportEvent;

/**
 
 Represents a TV channel with the internal Snapscreen representation
 
 */
@interface SnapscreenTvChannel : NSObject

/** An internal channel identifier */
@property (readonly, nonatomic) long long channelId;

/** The Snapscreen-specific channel code for this TV channel. This is used to specify a channel in many other calls in the SDK. */
@property (readonly, nonatomic, nonnull) NSString* channelCode;

/** The ISO country code where this channel is aired */
@property (readonly, nonatomic, nonnull) NSString* countryCode;

/** Human-readable name for this TV channel */
@property (readonly, nonatomic, nullable) NSString* name;

/** An optional link to the homepage of this TV channel */
@property (readonly, nonatomic, nullable) NSString* homepage;

/** An optional link to a channel logo */
@property (readonly, nonatomic, nullable) NSString* logoImageUrl;

/** An optional link to a channel poster image */
@property (readonly, nonatomic, nullable) NSString* posterImageUrl;

/** Optional resolved EPG unit that is currently playing on this channel */
@property (readonly, nonatomic, nullable) SnapscreenEpgUnit* epgUnit;

/** Optional resolved sport event that is currently live on this channel */
@property (readonly, nonatomic, nullable) SnapscreenSportEvent* sportEvent;

/** Optional URL for a live image of the currently epg unit on this channel */
@property (readonly, nonatomic, nullable) NSString* liveImageUrl;

/** Determines whether an access token is necessary when fetching the liveImageURL */
@property (readonly, nonatomic) Boolean liveImageUrlSecured;


/**
 
 Initiailzer
 
 */
- (_Nonnull instancetype) initWithChannelId: (long long) channelId channelCode: (NSString* _Nonnull) channelCode countryCode: (NSString* _Nonnull) countryCode name: (NSString* _Nullable) name homepage: (NSString* _Nullable) homepage logoImageUrl: (NSString* _Nullable) logoImageUrl posterImageUrl: (NSString* _Nullable) posterImageUrl liveImageUrl: (NSString* _Nullable) liveImageUrl liveImageUrlSecured: (BOOL) liveImageUrlSecured;

@end
