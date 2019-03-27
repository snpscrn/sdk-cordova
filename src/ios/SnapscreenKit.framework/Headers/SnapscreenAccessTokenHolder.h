//
//  SnapscreenAccessTokenHolder.h
//  SnapscreenKit
//
//  Created by Martin Reichart on 20/08/16.
//  Copyright © 2016 Snapscreen Application GmbH. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SnapscreenAccessToken.h"

/**
 
 Holds the current Access Token for communicating with the Snapscreen API.
 
 Note: This class is only intended for internal use and should not be used by SDK consumers!
 
 */
@interface SnapscreenAccessTokenHolder : NSObject

/**
 The current access token or nil if no access token was retrieved yet
 */
@property (nullable, strong, nonatomic) SnapscreenAccessToken* accessToken;

@end
