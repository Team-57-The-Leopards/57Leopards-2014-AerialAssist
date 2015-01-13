#ifndef AUTONCOMMANDGROUP_H
#define AUTONCOMMANDGROUP_H

#include "Commands/CommandGroup.h"
#include "GotoDistanceCommand.h"
#include "ArmSetCommand.h"
#include "WinchPullCommand.h"
#include "WinchActiveCommand.h"
#include "WinchReleaseNewCommand.h"
#include "LoadAndDriveCommandGroup.h"

/**
 *
 *
 * @author Leopards57
 */
class AutonCommandGroup: public CommandGroup {
public:	
	AutonCommandGroup();
};

#endif
