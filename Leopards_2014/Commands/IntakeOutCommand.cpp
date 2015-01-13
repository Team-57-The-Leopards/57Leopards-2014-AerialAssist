#include "IntakeOutCommand.h"

IntakeOutCommand::IntakeOutCommand() {
	// Use requires() here to declare subsystem dependencies
	Requires(intakerollers);
}

// Called just before this Command runs the first time
void IntakeOutCommand::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void IntakeOutCommand::Execute() {
	intakerollers->Pass();
}

// Make this return true when this Command no longer needs to run execute()
bool IntakeOutCommand::IsFinished() {
	if(CommandBase::oi->passbutton->Get() == false){
		return true;
	}
	else{
		return false;
	}
}

// Called once after isFinished returns true
void IntakeOutCommand::End() {
	intakerollers->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void IntakeOutCommand::Interrupted() {
}
