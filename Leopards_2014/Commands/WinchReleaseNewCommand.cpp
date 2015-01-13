#include "WinchReleaseNewCommand.h"

WinchReleaseNewCommand::WinchReleaseNewCommand() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	Requires(launcher);
				
}

// Called just before this Command runs the first time
void WinchReleaseNewCommand::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void WinchReleaseNewCommand::Execute() {
launcher->WinchRelease();
}

// Make this return true when this Command no longer needs to run execute()
bool WinchReleaseNewCommand::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void WinchReleaseNewCommand::End() {
	launcher->WinchRelease();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void WinchReleaseNewCommand::Interrupted() {
	launcher->WinchRelease();
}
