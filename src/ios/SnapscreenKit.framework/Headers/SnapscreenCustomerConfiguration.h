//
//  SnapscreenCustomerConfiguration.h
//  SnapscreenKit
//
//  Created by Martin Reichart on 06/03/2017.
//  Copyright © 2017 Snapscreen Application GmbH. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 
 Customer configuration with specific snapscreen settings for this customer
 
 */
@interface SnapscreenCustomerConfiguration : NSObject

/**
 
 Gets a configuration bool with a key or the given default value if no such key is found in the configuration
 
 */
- (BOOL) boolForKey: (NSString*) key default: (BOOL) defaultValue;

@end
