//
//  SnapscreenSearchType.h
//  SnapscreenKit
//
//  Created by Martin Reichart on 08/02/2017.
//  Copyright © 2017 Snapscreen Application GmbH. All rights reserved.
//


/// A list of possible search types that can be used for snapping
typedef NS_OPTIONS(NSInteger, SnapscreenSearchType) {
    /// Placeholder for none
    SnapscreenSearchTypeNone = 1 << 0,
    /// Search for tv results
    SnapscreenSearchTypeTv = 1 << 1,
    /// Search for advertisements
    SnapscreenSearchTypeAdvertisement = 1 << 2,
    /// Search for sport events
    SnapscreenSearchTypeSportEvents = 1 << 3
};
