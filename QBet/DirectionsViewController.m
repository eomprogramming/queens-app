//
//  DirectionsViewController.m
//  QBet
//
//  Created by Earl of March Computer Club on 12-06-02.
//  Copyright (c) 2012 OCDSB. All rights reserved.
//

#import "DirectionsViewController.h"
#import "QBet/EventInfoViewController.h"

NSString* location;
struct event* ev;

@interface DirectionsViewController ()

@end

@implementation DirectionsViewController

-(IBAction)getDestination{
    
}

-(id) init:(NSString*) loc backTo: (struct event*) e
{
    location = loc;
    ev = e;
    return self;
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
    location = [location stringByReplacingOccurrencesOfString:@" " withString:@"%20"];
    [map loadRequest:[NSURLRequest requestWithURL:[NSURL URLWithString:[@"http://maps.google.ca/maps?saddr=My%20Location&daddr=" stringByAppendingString:[location stringByAppendingString:@",%20Kingston,%20ON"]]]]];
    // Do any additional setup after loading the view from its nib.
}

- (void)viewDidUnload
{
    [super viewDidUnload];
    destinationPicker.frame = CGRectMake(destinationPicker.frame.origin.x,destinationPicker.frame.origin.y*-1,destinationPicker.frame.size.width,destinationPicker.frame.size.height);
    // Release any retained subviews of the main view.
    // e.g. self.myOutlet = nil;
}

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation
{
    return (interfaceOrientation == UIInterfaceOrientationPortrait);
}

- (void)tabBar:(UITabBar *)tabBar didSelectItem:(UITabBarItem *)item {
    
}

-(IBAction)goBack{
    EventInfoViewController* blah = [[EventInfoViewController alloc] initWithEvent: ev];
    [self presentModalViewController:blah animated:NO];
    [blah release];
}

@end
