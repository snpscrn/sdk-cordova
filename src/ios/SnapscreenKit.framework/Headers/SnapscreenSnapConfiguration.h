//
//  SnapscreenSnapConfiguration.h
//  SnapscreenKit
//
//  Created by Martin Reichart on 10/02/2017.
//  Copyright © 2017 Snapscreen Application GmbH. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 
 Configuration object to be passed when snapping. Allows you to specifiy what result types you are interested in and additional behaviour of the snapping process.
 
 */
@interface SnapscreenSnapConfiguration : NSObject

/** Search for TV results of type `SnapscreenTvSearchResult` */
@property (nonatomic, assign) BOOL searchForTvResults;

/** Search for advertisements of type `SnapscreenAdvertisementSearchResult` */
@property (nonatomic, assign) BOOL searchForAdvertisements;

/** Search for sport event results of type `SnapscreenSportEventSearchResult` */
@property (nonatomic, assign) BOOL searchForSportEvents;

/** Perform automatic snapping (provided that the specified result types support autosnapping */
@property (nonatomic, assign) BOOL automaticSnap;

@end
