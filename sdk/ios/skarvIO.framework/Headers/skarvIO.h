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

/**
 State Enumerator
 */
enum skarvIOState : uint16_t {
    skarvIOStateEnabled             = 0x1 << 0,
    skarvIOStateConnected           = 0x1 << 1,
    skarvIOStateBLActivated         = 0x1 << 2,
    skarvIOStateBLESupport          = 0x1 << 3,
    skarvIOStateDiscovering         = 0x1 << 4
};

/**
 Unit Representation Enumerator
 */
enum skarvIOUnit : uint16_t {
    skarvIOUnit1                    = 0x1 << 0,
    skarvIOUnit2                    = 0x1 << 1,
    skarvIOUnit3                    = 0x1 << 2,
    skarvIOUnit4                    = 0x1 << 3,
    skarvIOUnit5                    = 0x1 << 4,
    skarvIOUnit6                    = 0x1 << 5,
    skarvIOUnit7                    = 0x1 << 6,
    skarvIOUnit8                    = 0x1 << 7,
    skarvIOUnit9                    = 0x1 << 8,
    skarvIOUnit10                   = 0x1 << 9,
    skarvIOUnit11                   = 0x1 << 10,
    skarvIOUnit12                   = 0x1 << 11,
    skarvIOUnit13                   = 0x1 << 12,
    skarvIOUnit14                   = 0x1 << 13,
    skarvIOUnit15                   = 0x1 << 14,
    skarvIOUnit16                   = 0x1 << 15,
};

/**
 Motion Representation Enumerator
 */
enum skarvIOMotion : uint8_t {
    skarvIOMotionPulse              = 0x0,
    skarvIOMotionOnOff              = 0x1,
    skarvIOMotionLinearOnOff        = 0x2,
    skarvIOMotionHeartBeat          = 0x3,
};


/* ------------------------------------------------------------------------------------------------------------
 * ------------------------------------------------ PROTOCOLS -------------------------------------------------
 * ----------------------------------------------------------------------------------------------------------*/

/**
 *  skarvIO Delegation Class
 *
 *  @since 1.0b
 */
@protocol skarvIODelegate <NSObject>

/**
 *  Ready to Use Delegate Method
 *
 *  @param enable SKARV is ready if the passed value is YES.
 *
 *  @since 1.0b
 */
- (void) skarvIOReady: ( BOOL ) enable;

@optional

/**
 *  Disconnect delegate method: called when the connection is canceled or disconnected.
 *
 *  @since 1.0b
 */
- (void) skarvIODisconnected;

/**
 *  Automated reconnect delegate method: called when a reconnect has occurred.
 *
 *  @since 1.0b
 */
- (void) skarvIOAutomatedReconnected;


@end


/* ------------------------------------------------------------------------------------------------------------
 * ------------------------------------------------ skarvIO CLASS ---------------------------------------------
 * ----------------------------------------------------------------------------------------------------------*/

/**
 *  skarvIO Main Class
 *
 *  @since 1.0b
 */
@interface skarvIO : NSObject

/**
*  Shared instance from the skarvIO Class
*
*  @return skarvIO Instance
*
*  @since 1.0b
*/
+ (instancetype) sharedInstance;

- (instancetype) init __attribute__((unavailable("init not available")));

/**
 *  skarvIO Inititalization Method.
 *
 *  @return Result of the Initialization.
 *  @warning Must be executed before other methods.
 *
 *  @since 1.0b
 */
- (BOOL) skarvIOInitialize;

/**
 *  Enable and initialize the bluetooth LE stack
 *
 *  @return Return NO when a general bluetooth error has occurred or the initialization method was not called before
 *
 *  @since 1.0b
 */
- (BOOL) skarvIOEnable;

/**
 *  Disable & uninitialize the bluetooth stack
 *
 *  @return Return NO when a general Error occured.
 *
 *  @since 1.0b
 */
- (BOOL) skarvIODisable;

/**
 *  Connect to a SKARV device with the given code
 *
 *  @param device     The Device Code.
 *  @param completion Completion block is executed after a successful or failed call. Error parameter not in use.
 *
 *  @return Return NO when a general Error occured.
 *
 *  @since 1.0b
 */
- (BOOL) skarvIOConnectToDevice: ( NSInteger ) device completion: ( void(^)( BOOL Success, NSError *error ) ) completion;

/**
 *  Disconnect the SKARV device
 *
 *  @return Return NO when a general Error occured.
 *
 *  @since 1.0b
 */
- (BOOL) skarvIODisconnect;

/**
 *  Power off the SKARV device
 *
 *  @return Return NO when a general Error occured.
 *
 *  @since 1.0b
 */
- (BOOL) skarvIOPowerOff;

/**
 *  En- or disable the demo mode: the demo mode lets the vibration units randomly vibrate.
 *
 *  @param enable     En- or disable the demo mode.
 *  @param completion Completion block is executed after a successful or failed call. Error parameter not in use.
 *
 *  @return Return NO when a general Error occured.
 *
 *  @since 1.0b
 */
- (BOOL) skarvIODemoMode: ( BOOL ) enable completion: ( void(^)( BOOL Success, NSError *error ) ) completion;

/**
 *  En- or disable the alarm mode: if the alarm mode is activated, a vibration is triggered as soon as the SKARV is a certain distance from the smartphone.
 *
 *  @param enable     En- or disable the alarm mode.
 *  @param completion Completion block is executed after a successful or failed call. Error parameter not in use.
 *
 *  @return Return NO when a general Error occured.
 *
 *  @since 1.0b
 */
- (BOOL) skarvIOAlarm: ( BOOL ) enable completion: ( void(^)( BOOL Success, NSError *error ) ) completion;

/**
 *  Enabling a vibration unit
 *
 *  @param unit       The unit to be activated with full power. @see enum skarvIOUnit
 *  @param completion Completion block is executed after a successful or failed call. Error parameter not in use.
 *
 *  @return Return NO when a general Error occured.
 *
 *  @since 1.0b
 */
- (BOOL) skarvIOEnableVibrationUnit: ( enum skarvIOUnit ) unit completion: ( void(^)( BOOL Success, NSError *error ) ) completion;

/**
 *  Disabling a vibration unit
 *
 *  @param unit       The unit to be deactivated. @see enum skarvIOUnit
 *  @param completion Completion Block is executed after a successful or failed call. Error Parameter not in use.
 *
 *  @return Return NO when a general Error occured.
 *
 *  @since 1.0b
 */
- (BOOL) skarvIODisableVibrationUnit: ( enum skarvIOUnit ) unit completion: ( void(^)( BOOL Success, NSError *error ) ) completion;

/**
 *  Set a value between 0 and 255 to a vibration unit.
 *
 *  @param value      Value for the vibration units to be set.
 *  @param unit       Vibration unit. @see enum skarvIOUnit
 *  @param completion Completion Block is executed after a successful or failed call. Error Parameter not in use.
 *
 *  @return Return NO when a general Error occured.
 *
 *  @since 1.0b
 */
- (BOOL) skarvIOSetValue: ( uint8_t ) value toVibrationUnit: ( enum skarvIOUnit ) unit completion: ( void(^)( BOOL Success, NSError *error ) ) completion;

/**
 *  Set a value between 0 and 255 to certain vibration units.
 *
 *  @param value      Value for the vibration units to be set.
 *  @param units      Vibration units represented in a bitmask. @see enum skarvIOUnit
 *  @param completion Completion Block is executed after a successful or failed call. Error Parameter not in use.
 *
 *  @return Return NO when a general Error occured.
 *
 *  @since 1.0b
 */
- (BOOL) skarvIOSetValue: ( uint8_t ) value toVibrationUnits: ( uint16_t ) units completion: ( void(^)( BOOL Success, NSError *error ) ) completion;

/**
 *  Set a value between 0 and 255 to all vibration units.
 *
 *  @param values     Value for the vibration units to be set.
 *  @param completion Completion Block is executed after a successful or failed call. Error Parameter not in use.
 *
 *  @return Return NO when a general Error occured.
 *
 *  @since 1.0b
 */
- (BOOL) skarvIOSetValuesToAllUnits: ( uint8_t* ) values completion: ( void(^)( BOOL Success, NSError *error ) ) completion;

/**
 *  Get the current state of the vibration units. ( Not completely implemented ).
 *
 *  @param completion Completion Block is executed after a successful or failed call. Error Parameter not in use.
 *
 *  @return Return NO when a general Error occured.
 *
 *  @since 1.0b
 */
- (BOOL) skarvIOUnitState: ( void(^)( BOOL Success, uint8_t units, NSError *error ) ) completion;

/**
 *  Get the current state of the alarm mode.
 *
 *  @param completion Completion Block is executed after a successful or failed call. Error Parameter not in use.
 *
 *  @return Return NO when a general Error occured.
 *
 *  @since 1.0b
 */
- (BOOL) skarvIOAlarmState: ( void(^)( BOOL Success, BOOL enabled, NSError *error ) ) completion;

/**
 *  Get the current state of the demo mode.
 *
 *  @param completion Completion Block is executed after a successful or failed call. Error Parameter not in use.
 *
 *  @return Return NO when a general Error occured.
 *
 *  @since 1.0b
 */
- (BOOL) skarvIODemoState: ( void(^)( BOOL Success, BOOL enabled, NSError *error ) ) completion;

/**
 *  Deactivate all vibration Units.
 *
 *  @param completion Completion Block is executed after a successful or failed call. Error Parameter not in use.
 *
 *  @return Return NO when a general Error occured.
 *
 *  @since 1.0b
 */
- (BOOL) skarvIOStopAllMotion: ( void(^)( BOOL Success, NSError *error ) ) completion;

/**
 *  Enable a given function for a specific vibration unit.
 *
 *  @param function Vibration function to be activated.
 *  @param unit Vibration unit. @see enum skarvIOUnit
 *  @param completion Completion Block is executed after a successful or failed call. Error Parameter not in use.
 *
 *  @return Return NO when a general Error occured.
 *
 *  @since 1.0b
 */
- (BOOL) skarvIOEnableMotionFunction: ( enum skarvIOMotion ) function toVibrationUnit: ( uint8_t ) unit completion: ( void(^)( BOOL Success, NSError *error ) ) completion;

/**
 *  Enable a given function for all vibration units.
 *
 *  @param function Vibration Function to be activated.
 *  @param units Vibration Units. @see enum skarvIOUnit
 *  @param completion Completion Block is executed after a successful or failed call. Error Parameter not in use.
 *
 *  @return Return NO when a general Error occured.
 *
 *  @since 1.0b
 */
- (BOOL) skarvIOEnableMotionFunction: ( enum skarvIOMotion ) function toVibrationUnits: ( uint16_t ) units completion: ( void(^)( BOOL Success, NSError *error ) ) completion;


/**
 *  En- or disable the bluetooth device buffer. Backup all bluetooth devices where they are found in a specified File. This accelerates the reconnection process after opening the App.
 *
 *  @since 1.0b
 */
@property ( nonatomic, assign ) BOOL                    deviceBufferEnable;

/**
 *  En- or disable the reconnection process. Here it will automatically reconnect after a exceptional disconnect.
 *
 *  @since 1.0b
 */
@property ( nonatomic, assign ) BOOL                    autoConnect;

/**
 *  En- or disable the logging function.
 *
 *  @since 1.0b
 */
@property ( nonatomic, assign ) BOOL                    logging;

/**
 *  Property holds the current connected device ID.
 *
 *  @since 1.0b
 */
@property ( nonatomic, assign, readonly ) NSInteger     deviceID;

/**
 *  State Property.
 *
 *  @since 1.0b
 */
@property ( nonatomic, assign, readonly ) uint16_t      state;

/**
 *  Bluetooth device buffer file name.
 *
 *  @since 1.0b
 */
@property ( nonatomic, strong ) NSString                *bufferFile;

/**
 *  Delegate Property.
 *
 *  @since 1.0b
 */
@property ( nonatomic, strong ) id<skarvIODelegate>     delegate;


@end
