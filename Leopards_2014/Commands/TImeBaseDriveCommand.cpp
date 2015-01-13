#include "TImeBaseDriveCommand.h"

TImeBaseDriveCommand::TImeBaseDriveCommand(int time) {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	Requires(chassis);
	SetTimeout(time);
}

// Called just before this Command runs the first time
void TImeBaseDriveCommand::Initialize() {
}

// Called repeatedly when this Command is scheduled to run
void TImeBaseDriveCommand::Execute() {
	chassis->ArcadeDrive(.5,0);
}

// Make this return true when this Command no longer needs to run execute()
bool TImeBaseDriveCommand::IsFinished() {
	return IsTimedOut();
}

// Called once after isFinished returns true
void TImeBaseDriveCommand::End() {
	chassis->ArcadeDrive(0,0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TImeBaseDriveCommand::Interrupted() {
	chassis->ArcadeDrive(0,0);
}
