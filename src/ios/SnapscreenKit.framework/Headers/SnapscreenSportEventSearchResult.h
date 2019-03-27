//
//  SnapscreenSportEventSearchResult.h
//  SnapscreenKit
//
//  Created by Martin Reichart on 28/02/2017.
//  Copyright © 2017 Snapscreen Application GmbH. All rights reserved.
//

#import <Foundation/Foundation.h>

@class SnapscreenSportEventSearchResultEntry;

/**
 
 Represents the result from a sports event search.
 
 */
@interface SnapscreenSportEventSearchResult : NSObject

/** The individual entries for this search result. In most cases 1 result, but may contain multiple results that are ordered descending by their score, so that the first entry is the most likely event */
@property (nonnull, nonatomic, readonly) NSArray<SnapscreenSportEventSearchResultEntry*>* results;

@end
