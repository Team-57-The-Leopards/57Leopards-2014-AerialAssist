#include "IntakeInCommand.h"

IntakeInCommand::IntakeInCommand() {
	// Use requires() here to declare subsystem dependencies
	Requires(intakerollers);
}

// Called just before this Command runs the first time
void IntakeInCommand::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void IntakeInCommand::Execute() {
	intakerollers->PickUp();
}

// Make this return true when this Command no longer needs to run execute()
bool IntakeInCommand::IsFinished() {
	if(CommandBase::oi->pickupbutton->Get() == false){
		return true;
	}
	else{
		return false;
	}
}

// Called once after isFinished returns true
void IntakeInCommand::End() {
	intakerollers->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void IntakeInCommand::Interrupted() {
}
