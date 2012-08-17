//
//  ItineraryViewController.m
//  QBet
//
//  Created by David Huynh on 12-06-08.
//  Copyright (c) 2012 EOM. All rights reserved.
//

#import "ItineraryViewController.h"
#import "ViewController.h"
#import "EventInfoViewController.h"
#import "EventDataGetter.h"
@interface ItineraryViewController ()

@end

@implementation ItineraryViewController
struct event* e;
-(IBAction)goBack{
    ViewController *main = [[ViewController alloc]init];
    [self presentModalViewController:main animated:NO];
    [main release];
}

-(void)changeDates:(NSString *)date{
    // INSERT THAT CODE YOU NEED LOL
    int year = [[date substringFromIndex:[date rangeOfString:@"  "].location+1]integerValue];
    int month = [[date substringToIndex:[date rangeOfString:@" "].location]integerValue];
    int day = [[[date substringFromIndex:[date rangeOfString:@" "].location+1]substringToIndex:[date rangeOfString:@"  "].location]integerValue];
    if(month<=11&&year==12){
        // VALID DAY
        if(month<11||(month==11&&day==1)){
            dateLabel.title = @"November 1, 2012";
             bar.selectedItem = day1; 
        }
        else if(month==11&&day>0&&day<4){
            dateLabel.title = [NSString stringWithFormat:@"November %i, 2012",day];
            if ([day2.title integerValue]==day) {
                bar.selectedItem = day2;
            }
            else if([day3.title integerValue]==day){
                bar.selectedItem = day3;
            }
        }
        else{
            
        }
    }
    else if(year>12||(month==11&&day>3&&year==12)||(month>11&&year==11)){
        // INVALID
    }
    
    //REFRESH TABLE...
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
    
    [EventDataGetter init];
    
    e = [ViewController getEvents];
    struct event current;
    
    eventData = [[NSMutableArray alloc]init];
    for (int i = 0; !EVENT_IS_NULL(&(e[i])); i++)
    {
        current = e[i];
        NSString *s = [NSString stringWithCString:ev_title(&e[i])encoding:NSUTF8StringEncoding];
        [eventData addObject:s];
    }
    //[eventData addObject:nil];

    [eventTable setDataSource:self];
    [eventTable setDelegate:self];
    [eventTable reloadData];
    
    NSDateFormatter* dateFormatter = [[NSDateFormatter alloc] init];
    [dateFormatter setDateFormat:@"MM dd  yy"];
    NSString *dateString = [dateFormatter stringFromDate:[NSDate date]];
    [dateFormatter release];
    [self changeDates:dateString];
    // Do any additional setup after loading the view from its nib.
}

- (void)viewDidUnload
{
    [backButton release];
    backButton = nil;
    [eventTable release];
    eventTable = nil;
    [day1 release];
    day1 = nil;
    [day2 release];
    day2 = nil;
    [day3 release];
    day3 = nil;
    [dateLabel release];
    dateLabel = nil;
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
    [eventTable release];
    [day1 release];
    [day2 release];
    [day3 release];
    [dateLabel release];
    [super dealloc];
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
    return [eventData count];
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@""];
    if (cell == nil) {
        cell = [[[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:@""] autorelease];
    }
    
    // Configure the cell...
    
    cell.textLabel.text = [eventData objectAtIndex:indexPath.row];
    cell.textLabel.textColor = [UIColor blackColor];
    cell.accessoryType = UITableViewCellAccessoryDisclosureIndicator;
    
    
    return cell;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    NSString *text = [[tableView cellForRowAtIndexPath:indexPath].textLabel.text autorelease];
    [tableView deselectRowAtIndexPath:indexPath animated:YES];
    EventInfoViewController *event = [[EventInfoViewController alloc]initWithEvent:&e[indexPath.row]];
    [self presentModalViewController:event animated:YES];
    [event setPrevDate:[NSString stringWithFormat:@"11 0%@ 12",[[dateLabel.title substringToIndex:[dateLabel.title rangeOfString:@","].location]substringFromIndex:[dateLabel.title rangeOfString:@" "].location+1]] AndEventName:text];
}
@end
