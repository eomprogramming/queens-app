//
//  ViewController.m
//  QBet
//
//  Created by Earl of March Computer Club on 12-06-02.
//  Copyright (c) 2012 OCDSB. All rights reserved.
//

#import "ViewController.h"
#import "EventDateViewController.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    NSArray *tabItems = [[NSArray alloc]initWithObjects:day1,day2, day3, day4, day5, nil];
    for(int i=0; i<[tabItems count]; i++){
        ((UITabBarItem*)[tabItems objectAtIndex:i]).tag = i;
        ((UITabBarItem*)[tabItems objectAtIndex:i]).image = [UIImage imageNamed:@"QBET LOGO.png"];
    }
	// Do any additional setup after loading the view, typically from a nib.
}

- (void)viewDidUnload
{
    [super viewDidUnload];
    // Release any retained subviews of the main view.
}

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation
{
    return (interfaceOrientation != UIInterfaceOrientationPortraitUpsideDown);
}

- (void)tabBar:(UITabBar *)tabBar didSelectItem:(UITabBarItem *)item {
    EventDateViewController *edvc = [[EventDateViewController alloc]init];
    [self presentModalViewController:edvc animated:NO];
    [edvc setDate:(item.tag+1)];
    [edvc release];
}

@end
