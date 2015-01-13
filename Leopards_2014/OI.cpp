#include "OI.h"
#include "Robotmap.h"
#include "Commands/LowGearCommand.h"
#include "Commands/HighGearCommand.h"
#include "Commands/FireCommand.h"
#include "Commands/ShooterSetCommand.h"
#include "Commands/GoToPickUpCommandGroup.h"
#include "Commands/GoToFireCommandGroup.h"
#include "Commands/GoToPassCommandGroup.h"
#include "Commands/LedLightCommand.h"
#include "Commands/IntakeInCommand.h"
#include "Commands/IntakeOutCommand.h"
#include "Commands/ArmSpeedCommand.h"
#include "Commands/WinchActiveCommand.h"
#include "Commands/WinchReleaseNewCommand.h"
#include "Commands/WinchPullCommand.h"
#include "Commands/WinchExtendCommand.h"
#include "Commands/WinchStopCommand.h"
#include "Commands/ColorTestCommand.h"

OI::OI() {
	// Process operator interface input here.
	driveStick = new Joystick(ch_DriveJoystick);
	shooterbox = new Joystick(ch_ShooterBox); 
	
	shifttrigger = new JoystickButton(driveStick,ch_ShiftTrigger);
	distancechecker = new JoystickButton(driveStick,ch_DistanceChecker);
	
	gotofirebutton = new JoystickButton(shooterbox,8);
	firebutton = new JoystickButton(shooterbox,9);
	pickupbutton = new JoystickButton(shooterbox,3);
	passbutton = new JoystickButton(shooterbox,7);
	
    armdown = new JoystickButton(shooterbox,1);
    armup = new JoystickButton(shooterbox,2);
    winchactive = new JoystickButton(driveStick,4);
    winchrelease = new JoystickButton(driveStick,5);
    winchpull = new JoystickButton(driveStick,8);
    winchextend = new JoystickButton(driveStick,9);
	
	shifttrigger->WhenPressed(new LowGearCommand());
	shifttrigger->WhenReleased(new HighGearCommand());
	firebutton->WhenPressed(new FireCommand());
	firebutton->WhenReleased(new WinchReleaseNewCommand());
	//shootersetbutton->WhenPressed(new ShooterSetCommand());
	distancechecker->WhenPressed(new LedLightCommand());
	//distancechecker->WhenPressed(new ColorTestCommand());
	
	pickupbutton->WhenPressed(new GoToPickUpCommandGroup());
	passbutton->WhenPressed(new GoToPassCommandGroup());
	gotofirebutton->WhenPressed(new GoToFireCommandGroup());
	
	armup->WhenPressed(new ArmSpeedCommand(-.6));
	armdown->WhenPressed(new ArmSpeedCommand(.4));
	armup->WhenReleased(new ArmSpeedCommand(0));
	armdown->WhenReleased(new ArmSpeedCommand(0));	
	winchrelease->WhenPressed(new WinchReleaseNewCommand());
	winchactive->WhenPressed(new WinchActiveCommand());
	winchpull->WhenPressed(new WinchPullCommand());
    winchextend->WhenPressed(new WinchExtendCommand());
	winchpull->WhenReleased(new WinchStopCommand());
	winchextend->WhenReleased(new WinchStopCommand());
}
Joystick * OI::GetDriveJoystick()
{
	return driveStick;
}

