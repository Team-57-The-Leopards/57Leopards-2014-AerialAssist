#include "ShooterSetCommand.h"

ShooterSetCommand::ShooterSetCommand() {
	// Use requires() here to declare subsystem dependencies
	Requires(launcher);
	select = 0; 
}

ShooterSetCommand::ShooterSetCommand(int num) {
	// Use requires() here to declare subsystem dependencies
	Requires(launcher);
	select = num;
}

// Called just before this Command runs the first time
void ShooterSetCommand::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void ShooterSetCommand::Execute() {
	if (select == 0){                        //Preset for arm down
		  launcher->SetShooterPosition(0.0);
		}
		else if(select==1) {                  //Sets the arm for pick up
			launcher->SetShooterPosition(2.5);
		}
		else if(select==2) {                  //Sets the arm for pre-autonomous
			launcher->SetShooterPosition(3.5);
		}
		else{
			launcher->winchM->Set(0.0);       //Tells the arm to do nothing 
		}
}

// Make this return true when this Command no longer needs to run execute()
bool ShooterSetCommand::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void ShooterSetCommand::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ShooterSetCommand::Interrupted() {
}
