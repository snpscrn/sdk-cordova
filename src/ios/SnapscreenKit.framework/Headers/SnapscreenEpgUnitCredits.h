//
//  SnapscreenEpgUnitCredits.h
//  SnapscreenKit
//
//  Created by Martin Reichart on 19/05/2017.
//  Copyright © 2017 Snapscreen Application GmbH. All rights reserved.
//

#import <Foundation/Foundation.h>

@class SnapscreenEpgUnitPerson;

/**
 Represents information about credits of an epg unit
 */
@interface SnapscreenEpgUnitCredits : NSObject

/** The actors in the EPG Unit */
@property (readonly, nonatomic, nonnull) NSArray<SnapscreenEpgUnitPerson*>* actors;

/** The adapters in the EPG Unit */
@property (readonly, nonatomic, nonnull) NSArray<SnapscreenEpgUnitPerson*>* adapters;

/** The commentators in the EPG Unit */
@property (readonly, nonatomic, nonnull) NSArray<SnapscreenEpgUnitPerson*>* commentators;

/** The composers in the EPG Unit */
@property (readonly, nonatomic, nonnull) NSArray<SnapscreenEpgUnitPerson*>* composers;

/** The directors in the EPG Unit */
@property (readonly, nonatomic, nonnull) NSArray<SnapscreenEpgUnitPerson*>* directors;

/** The editors in the EPG Unit */
@property (readonly, nonatomic, nonnull) NSArray<SnapscreenEpgUnitPerson*>* editors;

/** The guests in the EPG Unit */
@property (readonly, nonatomic, nonnull) NSArray<SnapscreenEpgUnitPerson*>* guests;

/** The presenters in the EPG Unit */
@property (readonly, nonatomic, nonnull) NSArray<SnapscreenEpgUnitPerson*>* presenters;

/** The producers in the EPG Unit */
@property (readonly, nonatomic, nonnull) NSArray<SnapscreenEpgUnitPerson*>* producers;

/** The writers in the EPG Unit */
@property (readonly, nonatomic, nonnull) NSArray<SnapscreenEpgUnitPerson*>* writers;

@end
