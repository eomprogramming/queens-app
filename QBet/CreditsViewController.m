//
//  CreditsViewController.m
//  QBet
//
//  Created by David Huynh on 12-06-08.
//  Copyright (c) 2012 EOM. All rights reserved.
//

#import "CreditsViewController.h"
#import "ViewController.h"
@interface CreditsViewController ()

@end

@implementation CreditsViewController

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
    // Do any additional setup after loading the view from its nib.
}

- (void)viewDidUnload
{
    [backButton release];
    backButton = nil;
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
    [super dealloc];
}
@end
