//
//  SnapscreenEpgUnitPerson.h
//  SnapscreenKit
//
//  Created by Martin Reichart on 19/05/2017.
//  Copyright © 2017 Snapscreen Application GmbH. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 
 Represents information about a person that is part of an EPG Unit in some form
 
 */
@interface SnapscreenEpgUnitPerson : NSObject

/** The name of the person, e.g. an actor's name */
@property (nonatomic, readonly, nullable) NSString* name;

/** The role of the person, e.g. the character's name */
@property (nonatomic, readonly, nullable) NSString* role;

@end
