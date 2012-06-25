//
//  ViewController.h
//  QBet
//
//  Created by Earl of March Computer Club on 12-06-02.
//  Copyright (c) 2012 OCDSB. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface ViewController : UIViewController<UITableViewDelegate,UITableViewDataSource>{
    IBOutlet UITableView *mainTable;
    NSArray *textOnMenu;
}

@end
