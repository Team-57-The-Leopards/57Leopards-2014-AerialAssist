#include "ColorTestCommand.h"

ColorTestCommand::ColorTestCommand() {
	// Use requires() here to declare subsystem dependencies
	Requires(sensors);
}

// Called just before this Command runs the first time
void ColorTestCommand::Initialize() {
	SetTimeout(16);
	
}

// Called repeatedly when this Command is scheduled to run
void ColorTestCommand::Execute() {
	double tm = TimeSinceInitialized();
	if (tm < 2)
	sensors->redlight();
	else if (tm < 4)
	sensors->greenlight();
	else if (tm < 6)
	sensors->bluelight();
	else if (tm < 8)
	sensors->yellowlight();
	else if (tm < 10)
	sensors->violetlight();
	else if (tm < 12)
	sensors->cyanlight(); 
	else if (tm < 14)
	sensors->whitelight(); 
	else 
	sensors->ledoff();
}

// Make this return true when this Command no longer needs to run execute()
bool ColorTestCommand::IsFinished() {
	return IsTimedOut();
}

// Called once after isFinished returns true
void ColorTestCommand::End() {
	sensors->ledoff();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ColorTestCommand::Interrupted() {
	sensors->ledoff();
}
