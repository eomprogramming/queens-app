//
//  EventDataGetter.h
//  QBet
//
//  Created by Ian Dewan on 12-07-03.
//  Copyright (c) 2012 EOM. All rights reserved.
//

#import <Foundation/Foundation.h>
#include <conf-event.h>

@interface EventDataGetter : NSObject

+ (void) init;
+ (void) getFileFromInterwebs: (NSString *) name;
+ (void) update;
+ (int) isUpToDate: (NSString *) name;
+ (void) getImage: (NSString *) name;
+ (struct event *) getEventsForDay: (int) date;
+ (int) getEventCountForDay: (int) date;
+ (UIImage *) imageByName: (NSString *) name;
+(struct event*) getEvents: (NSInteger) day;

@end
