//
//  DWIwOSPaket.h
//  e-Textil M
//
//  Created by Benjamin Wolf on 05.11.15.
//  Copyright © 2015 denkwerk GmbH. All rights reserved.
//

#ifndef Skarv_DWIwOSPaket_h
#define Skarv_DWIwOSPaket_h

#import <Foundation/Foundation.h>


@interface DWIwOSPaket : NSObject


- (id) initWithPaket: (NSData*) data;
- (NSArray*) getData;

@end

#endif