#ifndef INTAKEROLLERS_H
#define INTAKEROLLERS_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

/**
 *
 *
 * @author Leopards57
 */
class IntakeRollers: public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

public:
	IntakeRollers();
	void InitDefaultCommand();
	void PickUp();
	void Pass();
	void Stop();
	CANJaguar *rollerM;
	
	

};

#endif
