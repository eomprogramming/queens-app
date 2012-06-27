//
//  EventInfoViewController.m
//  QBet
//
//  Created by Earl of March Computer Club on 12-06-02.
//  Copyright (c) 2012 OCDSB. All rights reserved.
//

#import "EventInfoViewController.h"
#import "DirectionsViewController.h"
@interface EventInfoViewController ()

@end

@implementation EventInfoViewController

-(IBAction)getDir{
    DirectionsViewController *dvc = [[DirectionsViewController alloc]init];
    [self presentModalViewController:dvc animated:NO];
    [dvc release];
}

-(IBAction)goBack{
    
}

-(void)setPrevDate:(NSString*)day AndEventName:(NSString *)nameOfEvent{
    date = day;
    //Figure out exactly which day it is!!!
}

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        // Custom initialization
    }
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    [eventData setText:@"Tell me if you see this displayed in the event info GUI"];
    // Do any additional setup after loading the view from its nib.
}

- (void)viewDidUnload
{
    [super viewDidUnload];
    // Release any retained subviews of the main view.
    // e.g. self.myOutlet = nil;
}

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation
{
    return (interfaceOrientation == UIInterfaceOrientationPortrait);
}

- (void)tabBar:(UITabBar *)tabBar didSelectItem:(UITabBarItem *)item {
   
}

@end
