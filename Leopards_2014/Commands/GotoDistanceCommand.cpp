#include "GotoDistanceCommand.h"

GotoDistanceCommand::GotoDistanceCommand(double dist) {
	// Use requires() here to declare subsystem dependencies
	Requires(chassis);
	setdistance = dist;
	currentdistance = 0 ;
	threshhold = 1.0;
	inRange = false;
}

// Called just before this Command runs the first time
void GotoDistanceCommand::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void GotoDistanceCommand::Execute() {
	currentdistance = sensors->GetDistance();
	if(currentdistance > setdistance + threshhold ){
		chassis->ArcadeDrive(0.6,0.0);
		inRange = false;
	}
	else if(currentdistance < setdistance - threshhold ){
		chassis->ArcadeDrive(-0.6,0.0);
		inRange = false;
	}
	else{
		chassis->ArcadeDrive(0.0,0.0);
		inRange = true;
	}
}

// Make this return true when this Command no longer needs to run execute()
bool GotoDistanceCommand::IsFinished() {
	return inRange;
}

// Called once after isFinished returns true
void GotoDistanceCommand::End() {
	chassis->ArcadeDrive(0.0,0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void GotoDistanceCommand::Interrupted() {
	chassis->ArcadeDrive(0.0,0.0);
}
