//
//  SnapscreenSnapResultsViewController.h
//  SnapscreenKit
//
//  Created by Martin Reichart on 19/05/2017.
//  Copyright © 2017 Snapscreen Application GmbH. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "SnapscreenSnapViewController.h"

@class SnapscreenSearchResult, SnapscreenSearchResultEntry, SnapscreenSnapResultsViewController;

/**
 
 Provides callback from the SnapscreenSnapResultsViewController during the result selection process.
 
 */
@protocol SnapscreenSnapResultsViewControllerDelegate<NSObject>

@optional

/**
 
 Provides the ability to set a custom color for the result table view
 
 */
- (UIColor* _Nullable) snapscreenSnapResultsViewControllerBackgroundColorForResultTableView: (SnapscreenSnapResultsViewController* _Nonnull) snapResultsViewController;

/**
 
 Provides the ability to register custom cell and header classes for UI customization. Do not implement if no customization should be used.
 
 */
- (void) snapscreenSnapResultsViewController: (SnapscreenSnapResultsViewController* _Nonnull) snapResultsViewController registerCustomContentClassesForTableView: (UITableView* _Nonnull) tableView;

/** 
 
 Provides the ability to return a custom UITableViewCell to use for display the given searchResultEntry. The entry can be of one of the following types: `SnapscreenTvSearchResultEntry`, `SnapscreenSportEventSearchResultEntry` or `SnapscreenAdvertisementSearchResultEntry`. Return nil or do not implement if the standard cells should be used.
 
 */
- (UITableViewCell* _Nullable) snapscreenSnapResultsViewController: (SnapscreenSnapResultsViewController* _Nonnull) snapResultsViewController tableView: (UITableView* _Nonnull)tableView cellForRowAtIndexPath: (NSIndexPath* _Nonnull)indexPath withSearchResultEntry: (SnapscreenSearchResultEntry* _Nonnull) searchResultEntry;

/**
 
 When using a custom UITableViewCell for displaying a given searchResultEntry, should return the height for it or UITableViewAutomaticDimension. Return 0 or do not implement if the standard cells should be used.
 
 */
- (CGFloat) snapscreenSnapResultsViewController: (SnapscreenSnapResultsViewController* _Nonnull) snapResultsViewController tableView: (UITableView* _Nonnull)tableView heightForRowAtIndexPath: (NSIndexPath* _Nonnull)indexPath withSearchResultEntry: (SnapscreenSearchResultEntry* _Nonnull) searchResultEntry;

/**
 
 When using a custom section header for the list of search results, should return the height for the custom section header. Return 0 or do not implement if the default header should be used.
 
 */
- (CGFloat) snapscreenSnapResultsViewController: (SnapscreenSnapResultsViewController* _Nonnull) snapResultsViewController tableView: (UITableView* _Nonnull)tableView heightForHeaderInSection:(NSInteger)section;

/**
 
 Provides the ability to return a custom Section Header to use for the list of search results. Return nil or do not implement if the default header should be shown.
 
 */
- (UIView* _Nullable) snapscreenSnapResultsViewController: (SnapscreenSnapResultsViewController* _Nonnull) snapResultsViewController tableView: (UITableView* _Nonnull)tableView viewForHeaderInSection:(NSInteger)section;

/**
 
 Provides the ability to return a custom placeholder image to use when loading the main image for a search result entry. Is only applied when not providing custom cells.
 
 */
- (UIImage* _Nullable) snapscreenSnapResultsViewController: (SnapscreenSnapResultsViewController* _Nonnull) snapResultsViewController placeholderImageForResultEntry: (SnapscreenSearchResultEntry* _Nonnull) searchResultEntry;

@end

/** View Controller for presenting recognized snap results when result is not unique and returns multiple possible matches */
@interface SnapscreenSnapResultsViewController : UIViewController

@end
