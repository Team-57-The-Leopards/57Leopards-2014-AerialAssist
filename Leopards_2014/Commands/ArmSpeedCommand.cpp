#include "ArmSpeedCommand.h"

ArmSpeedCommand::ArmSpeedCommand(float setspeed) {
	// Use requires() here to declare subsystem dependencies
	Requires(intakearms);
	speed = setspeed;
}

// Called just before this Command runs the first time
void ArmSpeedCommand::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void ArmSpeedCommand::Execute() {
	intakearms->ArmSpeed(speed);
	
	
}

// Make this return true when this Command no longer needs to run execute()
bool ArmSpeedCommand::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void ArmSpeedCommand::End() {
	intakearms->ArmSpeed(0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ArmSpeedCommand::Interrupted() {
	intakearms->ArmSpeed(0.0);
}
