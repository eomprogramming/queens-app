//
//  EventInfoViewController.h
//  QBet
//
//  Created by Earl of March Computer Club on 12-06-02.
//  Copyright (c) 2012 OCDSB. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface EventInfoViewController : UIViewController<UITabBarDelegate>{
    IBOutlet UIBarButtonItem *eventLabel;
    IBOutlet UIButton *dirButton;
    IBOutlet UILabel *speakerLabel;
    IBOutlet UILabel *sponsorLabel;
    IBOutlet UITextView *descLabel;
    IBOutlet UILabel *timeLabel;
    IBOutlet UIImageView *image;
    
    NSString* date;
}
-(IBAction)getDir;
-(IBAction)goBack;
- (id)initWithEvent:(struct event*) e;
@end
