#include "SimpleAutonCommand.h"

SimpleAutonCommand::SimpleAutonCommand() {
	// Use requires() here to declare subsystem dependencies
    Requires(chassis);
}

// Called just before this Command runs the first time
void SimpleAutonCommand::Initialize() {
	dist = 0;
	inRange = false;
}

// Called repeatedly when this Command is scheduled to run
void SimpleAutonCommand::Execute() {
	dist = sensors->GetDistance()/12;
	if(dist>4){
	 chassis->ArcadeDrive(.5,0);
	 inRange = false;
	}
	else{
		chassis->ArcadeDrive(0.0,0.0);
		inRange = true;
	}
}

// Make this return true when this Command no longer needs to run execute()
bool SimpleAutonCommand::IsFinished() {
	return inRange;
}

// Called once after isFinished returns true
void SimpleAutonCommand::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SimpleAutonCommand::Interrupted() {
}
