//
//  SnapQuadrangle.h
//  SnapscreenKit
//
//  Created by Martin on 09/11/2017.
//  Copyright © 2017 Snapscreen Application GmbH. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CGGeometry.h>
#import <UIKit/UIKit.h>

/**
 
 Represents a quadrangle on the screen that contains a search result.
 
 */
@interface SnapscreenResultQuadrangle : NSObject

/** A closed Bezierpath connecting the 4 corners of the quadrangle - might not be perfectly rectangular due to perspective distortions (e.g. looking at the TV at an angle */
@property (nonatomic, readonly) UIBezierPath* quadranglePath;

/** A rectangle enclosing all 4 corners of the quadrangle */
@property (nonatomic, readonly) CGRect quadrangleEnclosingRect;

@end
