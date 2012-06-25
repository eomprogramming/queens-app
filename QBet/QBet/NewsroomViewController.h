//
//  NewsroomViewController.h
//  QBet
//
//  Created by David Huynh on 12-06-09.
//  Copyright (c) 2012 EOM. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface NewsroomViewController : UIViewController{
    
    IBOutlet UIBarButtonItem *backButton;
    IBOutlet UIWebView *webview;
}
-(IBAction)goBack;
@end
