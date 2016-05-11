//
//  skarvIO.h
//  skarvIO
//
//  Created by Benjamin Wolf on 09.05.16.
//  Copyright © 2016 denkwerk GmbH. All rights reserved.
//

#import <Foundation/Foundation.h>


/* ------------------------------------------------------------------------------------------------------------
 * ------------------------------------------------ DEFINES ---------------------------------------------------
 * ----------------------------------------------------------------------------------------------------------*/

FOUNDATION_EXPORT NSString * const      skarvIOStandardBufferFilename;

FOUNDATION_EXPORT double                skarvIOVersionNumber;
FOUNDATION_EXPORT const unsigned char   skarvIOVersionString[];


/* ------------------------------------------------------------------------------------------------------------
 * ------------------------------------------------ ENUMERATORS -----------------------------------------------
 * ----------------------------------------------------------------------------------------------------------*/

enum skarvIOState : uint16_t {
    skarvIOStateEnabled             = 0x1 << 0,
    skarvIOStateConnected           = 0x1 << 1,
    skarvIOStateBLActivated         = 0x1 << 2,
    skarvIOStateBLESupport          = 0x1 << 3,
    skarvIOStateDiscovering         = 0x1 << 4
};


/* ------------------------------------------------------------------------------------------------------------
 * ------------------------------------------------ PROTOCOLS -------------------------------------------------
 * ----------------------------------------------------------------------------------------------------------*/

@protocol skarvIODelegate <NSObject>

- (void) skarvIOReady: ( BOOL ) enable;

@optional

- (void) skarvIODisconnected;
- (void) skarvIOAutomatedReconnected;


@end


/* ------------------------------------------------------------------------------------------------------------
 * ------------------------------------------------ skarvIO CLASS ---------------------------------------------
 * ----------------------------------------------------------------------------------------------------------*/

@interface skarvIO : NSObject


+ (instancetype) sharedInstance;
- (instancetype) init __attribute__((unavailable("init not available")));

- (BOOL) skarvIOInitialize;
- (BOOL) skarvIOEnable;
- (BOOL) skarvIODisable;
- (BOOL) skarvIOConnectToDevice: ( NSInteger ) device completion: ( void(^)( BOOL Success, NSError *error ) ) completion;
- (BOOL) skarvIODisconnect;

- (BOOL) skarvIOPowerOff;
- (BOOL) skarvIODemoMode: ( BOOL ) enable completion: ( void(^)( BOOL Success, NSError *error ) ) completion;
- (BOOL) skarvIOAlarm: ( BOOL ) enable completion: ( void(^)( BOOL Success, NSError *error ) ) completion;
- (BOOL) skarvIOEnableVibrationUnit: ( uint8_t ) unit completion: ( void(^)( BOOL Success, NSError *error ) ) completion;
- (BOOL) skarvIODisableVibrationUnit: ( uint8_t ) unit completion: ( void(^)( BOOL Success, NSError *error ) ) completion;
- (BOOL) skarvIOSetValue: ( uint8_t ) value toVibrationUnit: ( uint8_t ) unit completion: ( void(^)( BOOL Success, NSError *error ) ) completion;
- (BOOL) skarvIOSetValue: ( uint8_t ) value toVibrationUnits: ( uint16_t ) units completion: ( void(^)( BOOL Success, NSError *error ) ) completion;
- (BOOL) skarvIOSetValuesToAllUnits: ( uint8_t* ) values completion: ( void(^)( BOOL Success, NSError *error ) ) completion;
- (BOOL) skarvIOUnitState: ( void(^)( BOOL Success, uint8_t units, NSError *error ) ) completion;
- (BOOL) skarvIOAlarmState: ( void(^)( BOOL Success, BOOL enabled, NSError *error ) ) completion;
- (BOOL) skarvIODemoState: ( void(^)( BOOL Success, BOOL enabled, NSError *error ) ) completion;
- (BOOL) skarvIOStopAllMotion: ( void(^)( BOOL Success, NSError *error ) ) completion;
- (BOOL) skarvIOEnableMotionFunction: ( uint8_t ) function toVibrationUnit: ( uint8_t ) unit completion: ( void(^)( BOOL Success, NSError *error ) ) completion;
- (BOOL) skarvIOEnableMotionFunction: ( uint8_t ) function toVibrationUnits: ( uint8_t ) units completion: ( void(^)( BOOL Success, NSError *error ) ) completion;


@property ( nonatomic, assign ) BOOL                    deviceBufferEnable;
@property ( nonatomic, assign ) BOOL                    autoConnect;
@property ( nonatomic, assign ) BOOL                    logging;
@property ( nonatomic, assign, readonly ) NSInteger     deviceID;
@property ( nonatomic, assign, readonly ) uint16_t      state;

@property ( nonatomic, strong ) NSString                *bufferFile;

@property ( nonatomic, strong ) id<skarvIODelegate>     delegate;


@end
