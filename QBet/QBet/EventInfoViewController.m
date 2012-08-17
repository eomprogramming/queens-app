//
//  EventInfoViewController.m
//  QBet
//
//  Created by Earl of March Computer Club on 12-06-02.
//  Copyright (c) 2012 OCDSB. All rights reserved.
//

#import "EventInfoViewController.h"
#import "DirectionsViewController.h"
#import "ViewController.h"
#import "ItineraryViewController.h"
#import "EventDataGetter.h"
#include <time.h>
@interface EventInfoViewController ()

@end

@implementation EventInfoViewController
struct event* e;

-(IBAction)getDir{
    DirectionsViewController *dvc = [[DirectionsViewController alloc]init:nstringof(ev_loc(e)) backTo:e ];
    [self presentModalViewController:dvc animated:NO];
    [dvc release];
}

-(IBAction)goBack{
    ItineraryViewController *main = [[ItineraryViewController alloc]init];
    [self presentModalViewController:main animated:NO];
    [main release];
}

-(void)setPrevDate:(NSString*)day AndEventName:(NSString *)nameOfEvent{
    date = day;
    //Figure out exactly which day it is!!!
}

- (id)initWithEvent:(struct event*) event
{
    [super init];
    e = event;

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
    [eventLabel setTitle:nstringof(ev_title(e))];
    [speakerLabel setText:[[speakerLabel text] stringByAppendingString:nstringof(ev_speaker(e))]];
    //[sponsorLabel setText:[[sponsorLabel text] stringByAppendingString:nstringof(ev_)];
    [dirButton setTitle:nstringof(ev_loc(e)) forState:UIControlStateNormal];
    [descLabel setText:nstringof(ev_desc(e))];
    
    
    NSMutableString *ms = [[NSMutableString alloc] init];
    BOOL first = YES;
    for (char **sponsor = ev_sponsors(e); *sponsor != NULL; sponsor++) {
        if (!first)
            [ms appendString:@", "];
        else
            first = NO;
        [ms appendString:nstringof(*sponsor)];

    }
    [sponsorLabel setText:[[sponsorLabel text] stringByAppendingString:ms]];
    
    char *timestr = malloc(sizeof(char) * 50);
    strftime(timestr, 49, "%I:%M %p", ev_date(e));
    [timeLabel setText:[[timeLabel text] stringByAppendingString:nstringof(timestr)]];
    
    image.image = [EventDataGetter imageByName:nstringof(ev_image_loc(e))];
    //[eventLabel setText:@"Tell me if you see this displayed in the event info GUI"];
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

- (void)dealloc {
    [super dealloc];
}
@end
