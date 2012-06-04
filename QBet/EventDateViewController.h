//
//  EventDateViewController.h
//  QBet
//
//  Created by Earl of March Computer Club on 12-06-02.
//  Copyright (c) 2012 OCDSB. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface EventDateViewController : UIViewController<UITableViewDelegate,UITableViewDataSource,UITabBarDelegate>{
    IBOutlet UITabBarItem *day1;
    IBOutlet UITabBarItem *day2;
    IBOutlet UITabBarItem *day3;
    IBOutlet UITabBarItem *day4;
    IBOutlet UITabBarItem *day5;
    IBOutlet UIBarButtonItem *dateLabel;
}
-(void)setDate:(int)date;
@end
