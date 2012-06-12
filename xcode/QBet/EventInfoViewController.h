//
//  EventInfoViewController.h
//  QBet
//
//  Created by Earl of March Computer Club on 12-06-02.
//  Copyright (c) 2012 OCDSB. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface EventInfoViewController : UIViewController<UITabBarDelegate>{
    IBOutlet UITabBarItem *day1;
    IBOutlet UITabBarItem *day2;
    IBOutlet UITabBarItem *day3;
    IBOutlet UITabBarItem *day4;
    IBOutlet UITabBarItem *day5;
    IBOutlet UIBarButtonItem *eventLabel;
    IBOutlet UIButton *dirButton;
}
-(IBAction)getDir;
@end
