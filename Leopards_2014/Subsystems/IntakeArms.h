#ifndef INTAKEARMS_H
#define INTAKEARMS_H

#include "../AdvPIDSubsystem.h"

//#include "Commands/PIDSubsystem.h"
#include "WPILib.h"

/**
 *
 *
 * @author Family
 */
class IntakeArms: public PIDSubsystem {
private:
	 float armangle;
	 bool isSet;
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	// set the P, I, and D constants here
	static const double Kp = 0.0;
	static const double Ki = 0.0;
	static const double Kd = 0.0;
	static const double Kf = 0.0;
	static const bool inverted = false;

	static const double MinOutput = -1.0;
	static const double MaxOutput = 1.0;

	static const double MinInput = 0.08;
	static const double MaxInput = 1.0;
	
	static const double AbsErr = 0.01;
	
	

	double lastAngle, motorOut,threshold;
	

public:
	IntakeArms();
	double ReturnPIDInput();
	void UsePIDOutput(double output);
	void InitDefaultCommand();
	bool ArmSpeed(float speed);
	float GetAngle();
    bool SetArmAngle(float setangle);
	bool isArmSet();
	double GetOutput();
	bool IsEnabled();
	
	CANJaguar *leadscrew;
	AnalogChannel *arm_pot;
	DigitalInput *arm_limit;
	float currentangle;
	bool isThere;
	
	
};

#endif
