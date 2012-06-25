//
//  DirectionsViewController.m
//  QBet
//
//  Created by Earl of March Computer Club on 12-06-02.
//  Copyright (c) 2012 OCDSB. All rights reserved.
//

#import "DirectionsViewController.h"

@interface DirectionsViewController ()

@end

@implementation DirectionsViewController

-(IBAction)getDestination{
    
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
    
    [map loadRequest:[NSURLRequest requestWithURL:[NSURL URLWithString:@"http://maps.google.ca/maps?saddr=My%20Location&daddr=Victoria%20Hall,%20Queen%27s%20University,%20Kingston,%20ON"]]];
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

@end
