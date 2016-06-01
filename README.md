# skarvIO
SDK for SKARV

## Description

The skarvIO SDK contains the complete protocol stack for the control and management of the denkwerk SKARV wearable starting with iOS 8.1 SDK. The actual scarf is connected through a unique code. After connecting, many functions and status questions become available. Using the SDKs, you can send your own or ready-made vibration patterns to the scarf to signal or notify the user. For more information please visit the following website: http://www.skarv-fashion.com

## Requirements

There are a few prequites for this repository:

- iOS 8.1 Deployment Target
- Bluetooth LE capable Device
- denkwerk Skarv Wearable

## Initialization:

Get a Shared Instance:

    skarvIO *skarv = [skarvIO sharedInstance];

Set the Delegate ( skarvIODelegate ):

    skarv.delegate = self;

Enable Auto-Reconnection:

    skarv.autoConnect = YES;

Initialize & Enable the SDK:

    if ( [skarv skarvIOInitialize] == YES ) {
        if ( [_skarvIO skarvIOEnable] == YES ) {
        }
    }

## Delegates

This method is called if the skarvIO SDK is ready to work.

    - (void) skarvIOReady:(BOOL)enable {
      [_skarvIO skarvIOConnectToDevice:102208706 completion:^(BOOL Success, NSError *error) {
        // If Success you're connected to a Skarv.
      }
    }

This method is called if an unexpected or regular disconnection to SKARV has occurred.

    - (void) skarvIODisconnected {
    }

This method is called if auto-reconnect is enabled and an unexpected disconnect occurs.

    - (void) skarvIOAutomatedReconnected {
    }

## Methods

Power Off the SKARV:
```
   - (BOOL) skarvIOPowerOff;
```
Enable SKARV Demo Mode:  
```
   - (BOOL) skarvIODemoMode: ( BOOL ) enable completion: ( void(^)( BOOL Success, NSError *error ) ) completion;
```
Enable SKARV Range Alarm:
```
   - (BOOL) skarvIOAlarm: ( BOOL ) enable completion: ( void(^)( BOOL Success, NSError *error ) ) completion;
```
Enable One Vibration Unit ( Full Speed ):
```
   - (BOOL) skarvIOEnableVibrationUnit: ( uint8_t ) unit completion: ( void(^)( BOOL Success, NSError *error ) ) completion;
```
Disable One Vibration Unit:
```
   - (BOOL) skarvIODisableVibrationUnit: ( uint8_t ) unit completion: ( void(^)( BOOL Success, NSError *error ) ) completion;
```
Set a Value ( 0 - 255 ) to One Vibration Unit:
```
   - (BOOL) skarvIOSetValue: ( uint8_t ) value toVibrationUnit: ( uint8_t ) unit completion: ( void(^)( BOOL Success, NSError *error ) ) completion;
```
Set a value to one or more vibration units (units are a Bitmask bx0000000000000001 == vibration unit "one"):
```
   - (BOOL) skarvIOSetValue: ( uint8_t ) value toVibrationUnits: ( uint16_t ) units completion: ( void(^)( BOOL Success, NSError *error ) ) completion;
```
Set a Value to all Vibration Units:
```
   - (BOOL) skarvIOSetValuesToAllUnits: ( uint8_t* ) values completion: ( void(^)( BOOL Success, NSError *error ) ) completion;
```
Get the unit states (not tested, work in progress).:
```
   - (BOOL) skarvIOUnitState: ( void(^)( BOOL Success, uint8_t units, NSError *error ) ) completion;
```
Get the Current Alarm State ( On / Off ):
```
   - (BOOL) skarvIOAlarmState: ( void(^)( BOOL Success, BOOL enabled, NSError *error ) ) completion;
```
Get the Current Demo State ( On / Off ):
```
   - (BOOL) skarvIODemoState: ( void(^)( BOOL Success, BOOL enabled, NSError *error ) ) completion;
```
Disable All Motions:
```
   - (BOOL) skarvIOStopAllMotion: ( void(^)( BOOL Success, NSError *error ) ) completion;
```
Enable a Motion Function on One Vibration Unit:
```
   - (BOOL) skarvIOEnableMotionFunction: ( enum skarvIOMotion ) function toVibrationUnit: ( uint8_t ) unit completion: ( void(^)( BOOL Success, NSError *error ) ) completion;
```
Enable a Motion Function to one or More Vibration Units:
```
   - (BOOL) skarvIOEnableMotionFunction: ( enum skarvIOMotion ) function toVibrationUnits: ( uint16_t ) units completion: ( void(^)( BOOL Success, NSError *error ) ) completion;
```


Happy Coding!
