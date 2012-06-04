//
//  DirectionsViewController.h
//  QBet
//
//  Created by Earl of March Computer Club on 12-06-02.
//  Copyright (c) 2012 OCDSB. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface DirectionsViewController : UIViewController<UIPickerViewDelegate>{
    IBOutlet UIWebView *map;
    IBOutlet UIButton *directionButton;
    IBOutlet UIPickerView *destinationPicker;
}
-(IBAction)getDestination;
@end
