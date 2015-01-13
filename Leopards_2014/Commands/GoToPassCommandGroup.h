#ifndef GOTOPASSCOMMANDGROUP_H
#define GOTOPASSCOMMANDGROUP_H

#include "Commands/CommandGroup.h"
#include "ArmSetCommand.h"
#include "WinchPullCommand.h"
#include "IntakeOutCommand.h"
#include "WinchActiveCommand.h"


/**
 *
 *
 * @author Leopards57
 */
class GoToPassCommandGroup: public CommandGroup {
public:	
	GoToPassCommandGroup();
};

#endif
