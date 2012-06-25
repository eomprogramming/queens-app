//
//  NewsroomViewController.m
//  QBet
//
//  Created by David Huynh on 12-06-09.
//  Copyright (c) 2012 EOM. All rights reserved.
//

#import "NewsroomViewController.h"
#import "ViewController.h"
@interface NewsroomViewController ()

@end

@implementation NewsroomViewController

-(IBAction)goBack{
    ViewController *main = [[ViewController alloc]init];
    [self presentModalViewController:main animated:NO];
    [main release];
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
    [webview loadRequest:[NSURLRequest requestWithURL:[NSURL URLWithString:@"http://qbet.ca/?page_id=269"]]];
    // Do any additional setup after loading the view from its nib.
}

- (void)viewDidUnload
{
    [backButton release];
    backButton = nil;
    [webview release];
    webview = nil;
    [super viewDidUnload];
    // Release any retained subviews of the main view.
    // e.g. self.myOutlet = nil;
}

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation
{
    return (interfaceOrientation == UIInterfaceOrientationPortrait);
}

- (void)dealloc {
    [backButton release];
    [webview release];
    [super dealloc];
}
@end
