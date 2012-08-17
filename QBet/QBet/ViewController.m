//
//  ViewController.m
//  QBet
//
//  Created by Earl of March Computer Club on 12-06-02.
//  Copyright (c) 2012 OCDSB. All rights reserved.
//

#import "ViewController.h"
#import "CreditsViewController.h"
#import "NewsroomViewController.h"
#import "ItineraryViewController.h"
#import "InformationViewController.h"
#import "EventInfoViewController.h"
#include <syslog.h>

#define kBgQueue dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0) //1
#define day1URL [NSURL URLWithString:@"http://QBET.ca/QBETAPPEVENTS/day1"] //2
#define day2URL [NSURL URLWithString:@"http://QBET.ca/QBETAPPEVENTS/day2"] //2
#define day3URL [NSURL URLWithString:@"http://QBET.ca/QBETAPPEVENTS/day3"] //2

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    openlog("QBet App", LOG_PID, LOG_USER);
    textOnMenu = [[NSArray alloc]initWithObjects:@"Information",@"Itinerary",@"Newsroom",@"Virtual Business Card",@"Credits", nil];
    [mainTable setDataSource:self];
    [mainTable setDelegate:self];
    [mainTable reloadData];
    
	// Do any additional setup after loading the view, typically from a nib.
}

-(BOOL) update
{
    __block NSData* data;
    dispatch_async(kBgQueue, ^{
        data = [NSData dataWithContentsOfURL:day1URL];
        [self performSelectorOnMainThread:@selector(fetchedData:) 
                               withObject:data waitUntilDone:YES];
    });
    
    NSString *s = [[NSString alloc] initWithData: data encoding:NSASCIIStringEncoding];
    
    NSArray *paths = NSSearchPathForDirectoriesInDomains
    (NSDocumentDirectory, NSUserDomainMask, YES);
    NSString *documentsDirectory = [paths objectAtIndex:0];
    
    //make a file name to write the data to using the
    //documents directory:
    NSString *fullFileName = [NSString stringWithFormat:@"%@/test", documentsDirectory];

    //this statement is what actually writes out the array
    //to the file system:
    [s writeToFile:fullFileName atomically:NO];
    NSLog(@"HARRO ASSHOLE, %@",fullFileName);
    
    
    dispatch_async(kBgQueue, ^{
        NSData* data = [NSData dataWithContentsOfURL: 
                        day2URL];
        [self performSelectorOnMainThread:@selector(fetchedData:) 
                               withObject:data waitUntilDone:YES];
    });
    
    dispatch_async(kBgQueue, ^{
        NSData* data = [NSData dataWithContentsOfURL: 
                        day3URL];
        [self performSelectorOnMainThread:@selector(fetchedData:) 
                               withObject:data waitUntilDone:YES];
    });
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

- (NSInteger*)numberOfSectionsInTableView:(UITableView *)tableView
{
    return 1;
}

- (NSString *)tableView:(UITableView *)tableView titleForHeaderInSection:(NSInteger)section
{
    return [@"" autorelease];
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    return [textOnMenu count];
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@""];
    if (cell == nil) {
        cell = [[[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:@""] autorelease];
    }
    
    // Configure the cell...
    
    cell.textLabel.text = [textOnMenu objectAtIndex:indexPath.row];
    cell.textLabel.textColor = [UIColor blackColor];
    cell.accessoryType = UITableViewCellAccessoryDisclosureIndicator;
    
    
    return cell;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    NSString *text = [[tableView cellForRowAtIndexPath:indexPath].textLabel.text autorelease];
    if([text isEqualToString:@"Information"]){
        InformationViewController *newsroom = [[InformationViewController alloc]init];
        [self presentModalViewController:newsroom animated:NO];
        [newsroom release];
    }
    else if([text isEqualToString:@"Itinerary"]){
        ItineraryViewController *newsroom = [[ItineraryViewController alloc]initWithNibName:nil bundle:nil];
        [self presentModalViewController:newsroom animated:NO];
        [newsroom release];
    }
    else if([text isEqualToString:@"Newsroom"]){
        NewsroomViewController *newsroom = [[NewsroomViewController alloc]init];
        [self presentModalViewController:newsroom animated:NO];
        [newsroom release];
    }
    else if([text isEqualToString:@"Credits"]){
        CreditsViewController *credits = [[CreditsViewController alloc]init];
        [self presentModalViewController:credits animated:NO];
        [credits release];
    }
        
    [tableView deselectRowAtIndexPath:indexPath animated:YES];
}

@end
