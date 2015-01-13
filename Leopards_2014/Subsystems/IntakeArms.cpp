#include "IntakeArms.h"
#include "../Robotmap.h"
#include "SmartDashboard/SmartDashboard.h"

IntakeArms::IntakeArms() : PIDSubsystem("IntakeArms", Kp, Ki, Kd) {
	// Use these to get going:
	// SetSetpoint() -  Sets where the PID controller should move the system
	//                  to
	// Enable() - Enables the PID controller.
	leadscrew = new CANJaguar(ch_Leadscrew);
	arm_pot = new AnalogChannel(ch_ArmPotentiometer);
	lastAngle = 1;
	leadscrew->SetSafetyEnabled(kMotorSafety);
	threshold = .02;
	arm_limit = new DigitalInput(ch_ArmLimitSwitch);
	isThere = false;
	/*Adv*/PIDController *controller = GetPIDController(); 
		
	controller->SetInputRange(MinInput, MaxInput);
	controller->SetOutputRange(MinOutput, MaxOutput);
	controller->SetAbsoluteTolerance(AbsErr);
	
}

double IntakeArms::ReturnPIDInput() {
	// Return your input value for the PID loop
	// e.g. a sensor, like a potentiometer:
	// yourPot->SetAverageVoltage() / kYourMaxVoltage;
    armangle = arm_pot->GetVoltage();
	return armangle;
}
double IntakeArms::GetOutput() {
	return motorOut;
}

void IntakeArms::UsePIDOutput(double output) {
	// Use output to drive your system, like a motor
	// e.g. yourMotor->Set(output);
	motorOut = inverted ? -output : output;
		leadscrew->Set(motorOut);
}
bool IntakeArms::IsEnabled()
{
	return GetPIDController()->IsEnabled();
}


void IntakeArms::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//setDefaultCommand(new MySpecialCommand());
}

bool IntakeArms::ArmSpeed(float speed){        // Controls the speed lf leadscrew for the arm
	currentangle = GetAngle(); 
	isThere = arm_limit->Get();
	if(speed > 0.0)
	{
		if (currentangle > 1.95 || isThere == true)
		{
			leadscrew->Set(0);
			isThere = true;
		} else
		{
			leadscrew->Set(speed);
			isThere = false;			
		}			
	} else if (speed < 0.0)
	{
		if(currentangle <.3)
		{
			leadscrew->Set(0);
			isThere = true;
		} else
		{
			leadscrew->Set(speed);
			isThere = false;			
		}
	} else
	{
		leadscrew->Set(0);
		isThere = true;	
	}
	return isThere;
}

float IntakeArms::GetAngle() {
	armangle = arm_pot->GetVoltage();     //Returns the angle of the leadscrew
	return armangle;
}

bool IntakeArms::SetArmAngle(float setangle){ //Sets the angle of the arm by comparing it to that
	bool limited;
	currentangle = GetAngle();            //of the current arm angle
	if (currentangle  < setangle - threshold) {        //Know which direction is up
		limited = ArmSpeed(.4);
		return limited;
	} else if (currentangle > setangle + threshold ) {  //If the angle is below  
		limited = ArmSpeed(-.6);
		return limited;
	} else {
		ArmSpeed(0);
		return true;
	}
}

