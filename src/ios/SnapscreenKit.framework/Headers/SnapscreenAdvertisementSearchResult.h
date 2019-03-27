//
//  SnapscreenAdvertisementSearchResult.h
//  SnapscreenKit
//
//  Created by Martin Reichart on 10/02/2017.
//  Copyright © 2017 Snapscreen Application GmbH. All rights reserved.
//

#import <Foundation/Foundation.h>

@class SnapscreenAdvertisementSearchResultEntry;

/**
 
 Represents the result from an advertisement search.
 
 */
@interface SnapscreenAdvertisementSearchResult : NSObject

/** The individual entries for this search result. In most cases 1 result, but may contain multiple results that are ordered descending by their score, so that the first entry is the most likely match */
@property (nonnull, nonatomic, readonly) NSArray<SnapscreenAdvertisementSearchResultEntry*>* results;

@end
