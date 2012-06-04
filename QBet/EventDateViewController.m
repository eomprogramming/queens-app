//
//  EventDateViewController.m
//  QBet
//
//  Created by Earl of March Computer Club on 12-06-02.
//  Copyright (c) 2012 OCDSB. All rights reserved.
//

#import "EventDateViewController.h"
#import "EventInfoViewController.h"
@interface EventDateViewController ()

@end

@implementation EventDateViewController


-(void)setDate:(int)date{
    dateLabel.title = [NSString stringWithFormat:@"November %i, 2012",date];
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
    
    NSArray *tabItems = [[NSArray alloc]initWithObjects:day1,day2, day3, day4, day5, nil];
    for(int i=0; i<[tabItems count]; i++)
        ((UITabBarItem*)[tabItems objectAtIndex:i]).tag = i;
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

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView
{
    return 1;
}

- (NSString *)tableView:(UITableView *)tableView titleForHeaderInSection:(NSInteger)section
{
    return [@"" autorelease];
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    return 5;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@""];
    if (cell == nil) {
        cell = [[[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:@""] autorelease];
    }
    
    // Configure the cell...
    
    cell.textLabel.text = @"EVENT NAME";
    cell.textLabel.textColor = [UIColor whiteColor];
    cell.accessoryType = UITableViewCellAccessoryDisclosureIndicator;
    
    
    return cell;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    EventInfoViewController *eivc = [[EventInfoViewController alloc]init];
    [self presentModalViewController:eivc animated:NO];
    [eivc release];
    
    [tableView deselectRowAtIndexPath:indexPath animated:YES];
}

- (void)tabBar:(UITabBar *)tabBar didSelectItem:(UITabBarItem *)item {
    EventDateViewController *edvc = [[EventDateViewController alloc]init];
    [self presentModalViewController:edvc animated:NO];
    [edvc release];
}


@end
