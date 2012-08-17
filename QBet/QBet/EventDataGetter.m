//
//  EventDataGetter.m
//  QBet
//
//  Created by Ian Dewan on 12-07-03.
//  Copyright (c) 2012 EOM. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "EventDataGetter.h"
#include <conf-event.h>

static int exists(NSString *path, NSString *name);
static NSString * cacheLoc;

@implementation EventDataGetter

+ (void) init {
    cacheLoc = [[NSString alloc] initWithString:[NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) objectAtIndex:0]];
}

+ (void) getFileFromInterwebs:(NSString *)name {
    
}

+ (int) isUpToDate: (NSString *) name {
    if (!exists(cacheLoc, name))
        return 0;
    // TODO
}

+ (struct event *) getEventsForDay:(int)date {
    if ((date < 1) || (date > 3))
        return NULL;
    
    NSString *file = [cacheLoc stringByAppendingPathComponent:[[NSString alloc] initWithFormat:@"%i", date]];
    if ([self isUpToDate:file]) {
        return read_event_list([file UTF8String], NULL);
    } else {
        // TODO
        return NULL;
    }
}

+ (UIImage *) imageByName:(NSString *)name {
    if (!exists(cacheLoc, name))
        [EventDataGetter getFileFromInterwebs: name];
    
    return [UIImage imageWithContentsOfFile:[cacheLoc stringByAppendingPathComponent:name]];
}

@end

static int exists(NSString *path, NSString *name) {
    NSString *file = [path stringByAppendingPathComponent:name];
    
    return [[NSFileManager defaultManager] fileExistsAtPath:file]? 1: 0;
}