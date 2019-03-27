//
//  SnapscreenKitDelegate.h
//  SnapscreenKit
//
//  Created by Martin Reichart on 28.11.18.
//  Copyright © 2018 Snapscreen Application GmbH. All rights reserved.
//

#ifndef SnapscreenKitDelegate_h
#define SnapscreenKitDelegate_h


#endif /* SnapscreenKitDelegate_h */

/**
 
 Delegate for important callbacks of SnapscreenKit. Implement this to listen for any issues that might make SnapscreenKit unavailable in your application.
 
 */
@protocol SnapscreenKitDelegate<NSObject>
/**
 
 Initializing SnapscreenKit failed and Snapscreen functionality is not available to your application.
 
 @param error An error object containing an error with a `SnapscreenErrorCode`. See `SnapscreenErrorCode` for a list of possible error codes.
 
 */
- (void) snapscreenKitDidFailWithError: (NSError* _Nonnull) error;
@end
