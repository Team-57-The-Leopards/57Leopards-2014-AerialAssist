#include "WinchPullCommand.h"

WinchPullCommand::WinchPullCommand() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
    Requires(launcher);
   
}

// Called just before this Command runs the first time
void WinchPullCommand::Initialize() {
 SetTimeout(10);
}

// Called repeatedly when this Command is scheduled to run
void WinchPullCommand::Execute() {
	 launcher->Retract();	
}

// Make this return true when this Command no longer needs to run execute()
bool WinchPullCommand::IsFinished() {
	return launcher->launcher_limit->Get();
}

// Called once after isFinished returns true
void WinchPullCommand::End() {
	launcher->winchM->Set(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void WinchPullCommand::Interrupted() {
	launcher->winchM->Set(0);
}
