#ifndef ROBOTMAP_H
#define ROBOTMAP_H

// Safety Enabled set false for debugging, true for motor safety enabled.
static const bool kMotorSafety = false;

// CAN Jaguars for chassis
static const UINT32 ch_FrontLeftM = 2;
static const UINT32 ch_BackLeftM = 1;
static const UINT32 ch_BackRightM = 4;
static const UINT32 ch_FrontRightM = 3;

//Can Jaguar for Wench
static const UINT32 ch_WinchM = 5;

// CAN Jaguars for Intake and Arm
static const UINT32 ch_Leadscrew = 6;
static const UINT32 ch_IntakeM = 7;

//Relay Constants
static const UINT32 ch_PumpRelay = 1;

//Relay for LEDs
static const UINT32 ch_RG = 2;
static const UINT32 ch_B = 3;

// Solenlid channel for pneumaitiocs         
static const UINT32 ch_LowGear = 4;
static const UINT32 ch_WinchValve = 5;

// Joysticks
static const UINT32 ch_DriveJoystick = 1;
static const UINT32 ch_ShooterBox = 2;

//Buttons
static const UINT32 ch_ShiftTrigger = 1;
static const UINT32 ch_DistanceChecker = 3;
static const UINT32 ch_ShooterFire = 2;
static const UINT32 ch_ShooterSet = 3;
static const UINT32 ch_PickUp = 4;
static const UINT32 ch_Pass = 5;
static const UINT32 ch_GoToPresets = 10;

//Digital IO for Sensors
static const UINT32 ch_LauncherLimitSwitch = 3;
static const UINT32 ch_ArmLimitSwitch = 2;
static const UINT32 ch_PressureSwitch = 4;

//Analog IO for Sensors
//static const UINT32 ch_LauncherPotentiometer = 2;
static const UINT32 ch_ArmPotentiometer = 1;
static const UINT32 ch_ULTRASONIC = 2;
static const UINT32 ch_LauncherPotentiometer = 3;
#endif
