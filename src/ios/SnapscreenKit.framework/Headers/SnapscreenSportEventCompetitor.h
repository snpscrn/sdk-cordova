//
//  SnapscreenSportEventCompetitor.h
//  SnapscreenKit
//
//  Created by Martin Reichart on 28/02/2017.
//  Copyright © 2017 Snapscreen Application GmbH. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 
 Represents a competitor in a sport event
 
 */
@interface SnapscreenSportEventCompetitor : NSObject

/** The name of the competitor */
@property (nonatomic, readonly, nonnull) NSString* name;

@end
