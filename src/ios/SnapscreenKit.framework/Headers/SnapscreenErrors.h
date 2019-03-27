//
//  SnapscreenErrors.h
//  SnapscreenKit
//
//  Created by Martin Reichart on 20/08/16.
//  Copyright © 2016 Snapscreen Application GmbH. All rights reserved.
//

#import <Foundation/Foundation.h>

#define SnapscreenErrorDomain @"SnapscreenKitErrorDomain"

/**
 A list of possible error codes that are returned by SnapscreenKit. The error domain for errors from `SnapscreenKit` is usually `SnapscreenKitErrorDomain` unless some underlying error is the cause.
 */
typedef NS_ENUM(NSInteger, SnapscreenErrorCode) {
    /// Authentication credentials (clientID and clientSecret) are missing
    SnapscreenClientCredentialsMissing,
    /// The provided authentication credentials (clientID and clientSecret) are invalid
    SnapscreenClientCredentialsInvalid,
    /// The resource bundle (SnapscreenKit.bundle) is missing from the application bundle
    SnapscreenResourceBundleMissing,
    /// An error occured while loading webresources
    SnapscreenWebSearchError,
    /// Web search resulted in no results
    SnapscreenWebSearchNoResults,
    /// No access token could be fetched
    SnapscreenAccessTokenMissing
};
