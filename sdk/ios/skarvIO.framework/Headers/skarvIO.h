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
 *  @param enable The Skarv is ready if the passed value is YES.
 *
 *  @since 1.0b
 */
- (void) skarvIOReady: ( BOOL ) enable;

@optional

/**
 *  Disconnect Delegate Method. Called when the Connection is canceled or disconnected.
 *
 *  @since 1.0b
 */
- (void) skarvIODisconnected;

/**
 *  Automated Reconnect Delegate Method. Called when an Reconnect has occured.
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
*  Shared Instance from the skarvIO Class
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
 *  @warning Must be executed before other Methods.
 *
 *  @since 1.0b
 */
- (BOOL) skarvIOInitialize;

/**
 *  Enable and Initialize the Bluetooth LE Stack
 *
 *  @return Return NO when a general Bluetooth error occurred or the initialization method was not called before.
 *
 *  @since 1.0b
 */
- (BOOL) skarvIOEnable;

/**
 *  Disable & Uninitialize the Bluetooth Stack
 *
 *  @return Return NO when a general Error occured.
 *
 *  @since 1.0b
 */
- (BOOL) skarvIODisable;

/**
 *  Connecta to a SKARV Device with the given code.
 *
 *  @param device     The Device Code.
 *  @param completion Completion Block is executed after a successful or failed call. Error Parameter not in use.
 *
 *  @return Return NO when a general Error occured.
 *
 *  @since 1.0b
 */
- (BOOL) skarvIOConnectToDevice: ( NSInteger ) device completion: ( void(^)( BOOL Success, NSError *error ) ) completion;

/**
 *  Disconnect the Device
 *
 *  @return Return NO when a general Error occured.
 *
 *  @since 1.0b
 */
- (BOOL) skarvIODisconnect;

/**
 *  Power Off the SKARV Device.
 *
 *  @return Return NO when a general Error occured.
 *
 *  @since 1.0b
 */
- (BOOL) skarvIOPowerOff;

/**
 *  En- or Disable the Demo Mode. The Demo Mode lets the vibration Units randomly vibrate.
 *
 *  @param enable     En- or Disable the Demo Mode.
 *  @param completion Completion Block is executed after a successful or failed call. Error Parameter not in use.
 *
 *  @return Return NO when a general Error occured.
 *
 *  @since 1.0b
 */
- (BOOL) skarvIODemoMode: ( BOOL ) enable completion: ( void(^)( BOOL Success, NSError *error ) ) completion;

/**
 *  En- or Disable the Alarm Mode. If the Alarm Mode is activated, a Vibration is triggered as soon as the SKARV staying a certain Distance from the Smartphone away.
 *
 *  @param enable     En- or Disable the Alarm Mode.
 *  @param completion Completion Block is executed after a successful or failed call. Error Parameter not in use.
 *
 *  @return Return NO when a general Error occured.
 *
 *  @since 1.0b
 */
- (BOOL) skarvIOAlarm: ( BOOL ) enable completion: ( void(^)( BOOL Success, NSError *error ) ) completion;

/**
 *  Enabling a vibration unit
 *
 *  @param unit       The Unit to be Activated. With Full Power. @see enum skarvIOUnit
 *  @param completion Completion Block is executed after a successful or failed call. Error Parameter not in use.
 *
 *  @return Return NO when a general Error occured.
 *
 *  @since 1.0b
 */
- (BOOL) skarvIOEnableVibrationUnit: ( enum skarvIOUnit ) unit completion: ( void(^)( BOOL Success, NSError *error ) ) completion;

/**
 *  Disabling a vibration unit
 *
 *  @param unit       The Unit to be Deactivated. @see enum skarvIOUnit
 *  @param completion Completion Block is executed after a successful or failed call. Error Parameter not in use.
 *
 *  @return Return NO when a general Error occured.
 *
 *  @since 1.0b
 */
- (BOOL) skarvIODisableVibrationUnit: ( enum skarvIOUnit ) unit completion: ( void(^)( BOOL Success, NSError *error ) ) completion;

/**
 *  Set a Value between 0 and 255 to a Vibration Unit.
 *
 *  @param value      Value to a Vibration Unit to be set.
 *  @param unit       Vibration Unit. @see enum skarvIOUnit
 *  @param completion Completion Block is executed after a successful or failed call. Error Parameter not in use.
 *
 *  @return Return NO when a general Error occured.
 *
 *  @since 1.0b
 */
- (BOOL) skarvIOSetValue: ( uint8_t ) value toVibrationUnit: ( enum skarvIOUnit ) unit completion: ( void(^)( BOOL Success, NSError *error ) ) completion;

/**
 *  Set a Value between 0 and 255 to certain Vibration Units.
 *
 *  @param value      Value to the Vibration Units to be set.
 *  @param units      Vibration Units represented in a Bitmask. @see enum skarvIOUnit
 *  @param completion Completion Block is executed after a successful or failed call. Error Parameter not in use.
 *
 *  @return Return NO when a general Error occured.
 *
 *  @since 1.0b
 */
- (BOOL) skarvIOSetValue: ( uint8_t ) value toVibrationUnits: ( uint16_t ) units completion: ( void(^)( BOOL Success, NSError *error ) ) completion;

/**
 *  Set a Value between 0 and 255 to all Vibration Units.
 *
 *  @param values     Value to the Vibration Units to be set.
 *  @param completion Completion Block is executed after a successful or failed call. Error Parameter not in use.
 *
 *  @return Return NO when a general Error occured.
 *
 *  @since 1.0b
 */
- (BOOL) skarvIOSetValuesToAllUnits: ( uint8_t* ) values completion: ( void(^)( BOOL Success, NSError *error ) ) completion;

/**
 *  Get the Current State of the Vibration Units. ( Not Completely Implemented ).
 *
 *  @param completion Completion Block is executed after a successful or failed call. Error Parameter not in use.
 *
 *  @return Return NO when a general Error occured.
 *
 *  @since 1.0b
 */
- (BOOL) skarvIOUnitState: ( void(^)( BOOL Success, uint8_t units, NSError *error ) ) completion;

/**
 *  Get the Current State of the Alarm Modus.
 *
 *  @param completion Completion Block is executed after a successful or failed call. Error Parameter not in use.
 *
 *  @return Return NO when a general Error occured.
 *
 *  @since 1.0b
 */
- (BOOL) skarvIOAlarmState: ( void(^)( BOOL Success, BOOL enabled, NSError *error ) ) completion;

/**
 *  Get the Current State of the Demo Modus.
 *
 *  @param completion Completion Block is executed after a successful or failed call. Error Parameter not in use.
 *
 *  @return Return NO when a general Error occured.
 *
 *  @since 1.0b
 */
- (BOOL) skarvIODemoState: ( void(^)( BOOL Success, BOOL enabled, NSError *error ) ) completion;

/**
 *  Deactivate all Vibration Units.
 *
 *  @param completion Completion Block is executed after a successful or failed call. Error Parameter not in use.
 *
 *  @return Return NO when a general Error occured.
 *
 *  @since 1.0b
 */
- (BOOL) skarvIOStopAllMotion: ( void(^)( BOOL Success, NSError *error ) ) completion;

/**
 *  Enable a given Function to a specific Vibration Unit.
 *
 *  @param function Vibration Function to be activated.
 *  @param unit Vibration Unit. @see enum skarvIOUnit
 *  @param completion Completion Block is executed after a successful or failed call. Error Parameter not in use.
 *
 *  @return Return NO when a general Error occured.
 *
 *  @since 1.0b
 */
- (BOOL) skarvIOEnableMotionFunction: ( enum skarvIOMotion ) function toVibrationUnit: ( uint8_t ) unit completion: ( void(^)( BOOL Success, NSError *error ) ) completion;

/**
 *  Enable a given Function to all Vibration Units.
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
 *  En- or Disable the Bluetooth Device Buffer. Backup all Bluetooth Devices, where found, in a specified File. Accelerates the Reconnection Process after opening the App.
 *
 *  @since 1.0b
 */
@property ( nonatomic, assign ) BOOL                    deviceBufferEnable;

/**
 *  En- or Disable the Reconnection Process. Automatically Reconnect after a exceptional Disconnect.
 *
 *  @since 1.0b
 */
@property ( nonatomic, assign ) BOOL                    autoConnect;

/**
 *  En- or Disable the Logging Function.
 *
 *  @since 1.0b
 */
@property ( nonatomic, assign ) BOOL                    logging;

/**
 *  Property holds the current connected Device ID.
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
 *  Bluetooth Device Buffer File Name.
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
