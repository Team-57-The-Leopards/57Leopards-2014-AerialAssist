#ifndef GOTOFIRECOMMANDGROUP_H
#define GOTOFIRECOMMANDGROUP_H

#include "Commands/CommandGroup.h"
#include "ArmSetCommand.h"
#include "WinchPullCommand.h"
#include "WinchActiveCommand.h"
/**
 *
 *
 * @author Leopards57
 */
class GoToFireCommandGroup: public CommandGroup {
public:	
	GoToFireCommandGroup();
};

#endif
