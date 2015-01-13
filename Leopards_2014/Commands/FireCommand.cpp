#include "FireCommand.h"

FireCommand::FireCommand() {
	// Use requires() here to declare subsystem dependencies
	Requires(launcher);
}

// Called just before this Command runs the first time
void FireCommand::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void FireCommand::Execute() {
  launcher->Fire();
}

// Make this return true when this Command no longer needs to run execute()
bool FireCommand::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void FireCommand::End() {
	launcher->WinchRelease();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void FireCommand::Interrupted() {
	launcher->WinchRelease();
}
