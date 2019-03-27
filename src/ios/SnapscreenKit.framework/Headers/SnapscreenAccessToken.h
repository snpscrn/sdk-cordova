//
//  SnapscreenAccessToken.h
//  SnapscreenKit
//
//  Created by Martin Reichart on 20/08/16.
//  Copyright © 2016 Snapscreen Application GmbH. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 
 Represents an access token for accessing the Snapscreen API.
 
 Note: This class is only intended for internal use and should not be used by SDK consumers!
 
 */
@interface SnapscreenAccessToken : NSObject

/** The actual access token */
@property (readonly, nonatomic, nonnull, strong) NSString* accessToken;

/** The token type */
@property (readonly, nonatomic, nonnull, strong) NSString* tokenType;

/** Expiration date of this token */
@property (readonly, nonatomic, nonnull, strong) NSDate* expirationDate;

/** Refresh token used for obtaining a new refresh token */
@property (readonly, nonatomic, nonnull, strong) NSString* refreshToken;

/** Initializer */
- (instancetype _Nonnull) initWithAccessToken: (NSString* _Nonnull) accessToken tokenType: (NSString* _Nonnull) tokenType refreshToken: (NSString* _Nonnull) refreshToken scope: (NSString* _Nullable) scope expiresIn: (NSNumber* _Nonnull) expiresIn;

@end
