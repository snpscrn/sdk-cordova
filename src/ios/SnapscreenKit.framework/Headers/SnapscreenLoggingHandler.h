//
//  SnapscreenKitLoggingHandler.h
//  SnapscreenKit
//
//  Created by Martin Reichart on 16/09/16.
//  Copyright © 2016 Snapscreen Application GmbH. All rights reserved.
//

/**
 
 SnapscreenLoggingHandler offers an interface to receive log messages from SnapscreenKit in your application and connect logging to a custom logging framework of your choice.
 
 */
@protocol SnapscreenLoggingHandler

/** Log a message with level FATAL
 
 @param message The fully formatted log message
 
 */
- (void) logFatal: (NSString* _Nonnull) message;

/** Log a message with level ERROR
 
 @param message The fully formatted log message
 
 */
- (void) logError: (NSString* _Nonnull) message;

/** Log a message with level WARN
 
 @param message The fully formatted log message
 
 */
- (void) logWarn: (NSString* _Nonnull) message;

/** Log a message with level INFO
 
 @param message The fully formatted log message
 
 */
- (void) logInfo: (NSString* _Nonnull) message;

/** Log a message with level DEBUG
 
 @param message The fully formatted log message
 
 */
- (void) logDebug: (NSString* _Nonnull) message;

/** Log a message with level VERBOSE
 
 @param message The fully formatted log message
 
 */
- (void) logVerbose: (NSString* _Nonnull) message;

@end
