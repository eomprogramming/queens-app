//
//  ItineraryViewController.h
//  QBet
//
//  Created by David Huynh on 12-06-08.
//  Copyright (c) 2012 EOM. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface ItineraryViewController : UIViewController<UITableViewDelegate,UITableViewDataSource,UITabBarDelegate>{
    
    IBOutlet UIBarButtonItem *backButton;
    IBOutlet UITableView *eventTable;
    IBOutlet UITabBarItem *day1;
    IBOutlet UITabBarItem *day2;
    IBOutlet UITabBarItem *day3;
    IBOutlet UIBarButtonItem *dateLabel;
    IBOutlet UITabBar *bar;
    NSMutableArray *eventData;
}
-(IBAction)goBack;
-(void)changeDates:(NSString *)date;
- (void)tabBar:(UITabBar *)tabBar didSelectItem:(UITabBarItem *)item;

@end
