//
//  SnapscreenTvSearchResult.h
//  SnapscreenKit
//
//  Created by Martin Reichart on 10/02/2017.
//  Copyright © 2017 Snapscreen Application GmbH. All rights reserved.
//

#import <Foundation/Foundation.h>

@class SnapscreenTvSearchResultEntry;

/**
 
 Represent the result from a TV search.
 
 */
@interface SnapscreenTvSearchResult : NSObject

/** The individual entries for this search result. In most cases 1 result, but may contain multiple results that are ordered descending by their score, so that the first entry is the most likely match. */
@property (nonnull, nonatomic, readonly) NSArray<SnapscreenTvSearchResultEntry*>* results;

@end
