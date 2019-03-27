//
//  SnapscreenLocationProvider.h
//  SnapscreenKit
//
//  Created by Martin Reichart on 24/08/16.
//  Copyright © 2016 Snapscreen Application GmbH. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

/**
 
 Protocol for providing location to `SnapscreenKit`. Pass an implementation of this protocol to SnapscreenKit
 if your application already tracks user location in order to improve result quality.
 
 This is usually only necessary for SDK uses in apps that are supported in multiple countries.
 
 */
@protocol SnapscreenLocationProvider

/**
 
 Return the currently determined user location.
 
 @returns The user location or null if not determined
 
 */
- (CLLocation*) currentUserLocation;

/** Called by `SnapscreenKit` if an updated user location is preferred. */
- (void) updateCurrentUserLocation;

@end
