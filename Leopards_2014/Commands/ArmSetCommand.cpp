#include "ArmSetCommand.h"

ArmSetCommand::ArmSetCommand() {
	// Use requires() here to declare subsystem dependencies
	Requires(intakearms);
	select = 0;
	isSet = false;
}

ArmSetCommand::ArmSetCommand(int num) {
	// Use requires() here to declare subsystem dependencies
	Requires(intakearms);
	select = num;
	isSet = false;
}

// Called just before this Command runs the first time
void ArmSetCommand::Initialize() {//Numbers are not correct will be change
		
}

// Called repeatedly when this Command is scheduled to run
void ArmSetCommand::Execute() {
	if (select == 0){               //Preset for Pickup
		isSet = intakearms->SetArmAngle(1.4);
		}
		else if(select==1) {          //Preset for Fire
			isSet = intakearms->SetArmAngle(1.9);
		}
		else if(select==2) {          //Sets the arm for pre-autonomous
		isSet = intakearms->SetArmAngle(0.0);
		}
		else{
	    intakearms->ArmSpeed(0.0);       //Tells the arm to do nothing 
	    isSet = true;
		}
}

// Make this return true when this Command no longer needs to run execute()
bool ArmSetCommand::IsFinished() {
	return isSet;
    intakearms->ArmSpeed(0.0);       //Tells the arm to do nothing 

}

// Called once after isFinished returns true
void ArmSetCommand::End() {
    intakearms->ArmSpeed(0.0);       //Tells the arm to do nothing 

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ArmSetCommand::Interrupted() {
    intakearms->ArmSpeed(0.0);       //Tells the arm to do nothing 

}
