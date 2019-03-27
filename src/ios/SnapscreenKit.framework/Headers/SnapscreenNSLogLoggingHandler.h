//
//  SnapscreenNSLogLoggingHandler.h
//  SnapscreenKit
//
//  Created by Martin Reichart on 23/08/16.
//  Copyright © 2016 Snapscreen Application GmbH. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SnapscreenLoggingHandler.h"

/**
 
 Default SnapscreenLoggingHandler implementation that logs all messages to NSLog. Use only in test builds or while debugging and *NOT* in Release builds.
 
 */
@interface SnapscreenNSLogLoggingHandler : NSObject<SnapscreenLoggingHandler>

@end
