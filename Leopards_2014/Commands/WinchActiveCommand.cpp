#include "WinchActiveCommand.h"

WinchActiveCommand::WinchActiveCommand() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	Requires(launcher);
}

// Called just before this Command runs the first time
void WinchActiveCommand::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void WinchActiveCommand::Execute() {
	launcher->WinchActive();
	
}

// Make this return true when this Command no longer needs to run execute()
bool WinchActiveCommand::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void WinchActiveCommand::End() {
	launcher->WinchActive();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void WinchActiveCommand::Interrupted() {
	launcher->WinchActive();
	
}
