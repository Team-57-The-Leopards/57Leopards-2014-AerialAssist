#ifndef LAUNCHER_H
#define LAUNCHER_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

/**
 *
 *
 * @author Family
 */
class Launcher: public Subsystem {
private:
	double shooterpos;
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	Launcher();
	void Extend();
	void Retract();
	void WinchActive();
	void WinchRelease();
	void Fire();
	double GetShooterPosition();
	void SetShooterPosition(float setposition);
	bool IsShooterSet();
	bool isSet;

	Solenoid *winchValve;
	CANJaguar *winchM;
	AnalogChannel *launcher_pot;
	DigitalInput *launcher_limit;
	double currentposition;
};
#endif

