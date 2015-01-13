#include "IntakeRollers.h"
#include "../Robotmap.h"
#include "Commands/Subsystem.h"
#include "WPiLib.h"

IntakeRollers::IntakeRollers() :
	Subsystem("IntakeRollers") {
	rollerM = new CANJaguar(ch_IntakeM);
}
void IntakeRollers::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand()); 
}
void IntakeRollers::PickUp() {
	rollerM->Set(1.0);                      //Spins rollers in to pick up ball
}
void IntakeRollers::Pass() {
	rollerM->Set(-1.0);                     //Spins rollers out to pass ball
}
void IntakeRollers::Stop() {
	rollerM->Set(0);                       //Stops the intake
}
