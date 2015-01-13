#include "CommandBase.h"
#include "Commands/Scheduler.h"

CommandBase::CommandBase(const char *name) : Command(name) {
}

CommandBase::CommandBase() : Command() {
}
// Initialize a single static instance of all of your subsystems to NULL
Launcher* CommandBase::launcher = NULL;
IntakeArms* CommandBase::intakearms = NULL;
IntakeRollers* CommandBase::intakerollers = NULL;
Chassis* CommandBase::chassis = NULL;
Sensors* CommandBase::sensors = NULL;
OI* CommandBase::oi = NULL;

void CommandBase::init() {
    // Create a single static instance of all of your subsystems. The following
	// line should be repeated for each subsystem in the project.
	chassis = new Chassis();
	launcher = new Launcher();
	intakearms = new IntakeArms();
	intakerollers = new IntakeRollers();
	sensors = new Sensors();
	oi = new OI();
};
