#include "WinchExtendCommand.h"

WinchExtendCommand::WinchExtendCommand() {
	// Use requires() here to declare subsystem dependencies
	Requires(launcher);
}

// Called just before this Command runs the first time
void WinchExtendCommand::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void WinchExtendCommand::Execute() {
	launcher->winchM->Set(.5);
}

// Make this return true when this Command no longer needs to run execute()
bool WinchExtendCommand::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void WinchExtendCommand::End() {
	launcher->winchM->Set(0);	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void WinchExtendCommand::Interrupted() {
	launcher->winchM->Set(0);
}
