# skarvIO
SDK for SKARV

## Description

Das skarvIO SDK beinhaltet den kompletten Protokoll Stack zur Steuerung und Verwaltung des denkwerk Skarv Wearables ab der iOS 8.1 SDK. Der eigentlich Schal wird mittels eines eindeutigen Codes angesprochen bzw. verbunden. Nach dem verbinden stehen mehrere Funktionen und Status Abfragen zur Verfügung. Mittles des SDKs können eigene oder auch vorgefertigte Vibrationsmuster zur signalisierung oder Benachrichtigung des Benutzers an den Schal versendet werden. Für weitere Informationen besuchen sie bitte folgende Seite: http://www.skarv-fashion.com

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

This Method is called if the skarvIO SDK is Ready to Work.

    - (void) skarvIOReady:(BOOL)enable {
      [_skarvIO skarvIOConnectToDevice:102208706 completion:^(BOOL Success, NSError *error) {
        // If Success you're connected to a Skarv.
      }
    }

This Method is called if an unexpectedly or regular Disconnection to a SKARV is occurred.

    - (void) skarvIODisconnected {
    }

This Method is called if Auto-Reconnect is Enabled and an unexpectedly Disconnect is occured.

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
Set a Value to one or more Vibration Units ( units is a Bitmask bx0000000000000001 == Vibration Unit "One" ):
```
   - (BOOL) skarvIOSetValue: ( uint8_t ) value toVibrationUnits: ( uint16_t ) units completion: ( void(^)( BOOL Success, NSError *error ) ) completion;
```
Set a Value to all Vibration Units:
```
   - (BOOL) skarvIOSetValuesToAllUnits: ( uint8_t* ) values completion: ( void(^)( BOOL Success, NSError *error ) ) completion;
```
Get the Unit States ( Not Tested, Work in Progress ):
```
   - (BOOL) skarvIOUnitState: ( void(^)( BOOL Success, uint8_t units, NSError *error ) ) completion;
```
Get the Current Alarm State ( On / Off ):
```
   - (BOOL) skarvIOAlarmSta te: ( void(^)( BOOL Success, BOOL enabled, NSError *error ) ) completion;
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
   - (BOOL) skarvIOEnableMotionFunction: ( uint8_t ) function toVibrationUnit: ( uint8_t ) unit completion: ( void(^)( BOOL Success, NSError *error ) ) completion;
```
Enable a Motion Function to one or More Vibration Units:
```
   - (BOOL) skarvIOEnableMotionFunction: ( uint8_t ) function toVibrationUnits: ( uint8_t ) units completion: ( void(^)( BOOL Success, NSError *error ) ) completion;
```


Happy Coding!
