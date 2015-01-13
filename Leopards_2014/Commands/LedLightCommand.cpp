#include "LedLightCommand.h"

LedLightCommand::LedLightCommand() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
}

// Called just before this Command runs the first time
void LedLightCommand::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void LedLightCommand::Execute() {
	sensors->DistanceIndicator();
}

// Make this return true when this Command no longer needs to run execute()
bool LedLightCommand::IsFinished() {
	if(CommandBase::oi->GetDriveJoystick()->GetRawButton(3) == false){
		return true;
	}
	else{
		return false;
	}
}

// Called once after isFinished returns true
void LedLightCommand::End() {
	sensors->ledoff();	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LedLightCommand::Interrupted() {
	sensors->ledoff();
}
