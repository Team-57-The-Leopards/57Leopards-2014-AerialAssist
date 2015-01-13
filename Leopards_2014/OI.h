#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI {
private:

public:
	OI();
	Joystick *driveStick;
	Joystick *shooterbox;
	JoystickButton *distancechecker;
	JoystickButton *shifttrigger;
	JoystickButton *pickupbutton;
	JoystickButton *passbutton;
	JoystickButton *firebutton;
	JoystickButton *gotofirebutton;
	JoystickButton *shootersetbutton;
	JoystickButton *testbutton;
	JoystickButton *armup;
	JoystickButton *armdown;
	JoystickButton *winchactive;
	JoystickButton *winchrelease;
	JoystickButton *winchpull;
	JoystickButton *winchextend;
	
	Joystick *GetDriveJoystick();
	
	
};

#endif
