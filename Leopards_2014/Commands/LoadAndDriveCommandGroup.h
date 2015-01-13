#ifndef LOADANDDRIVECOMMANDGROUP_H
#define LOADANDDRIVECOMMANDGROUP_H

#include "Commands/CommandGroup.h"
#include "GotoDistanceCommand.h"
#include "ArmSetCommand.h"
#include "WinchPullCommand.h"
#include "WinchActiveCommand.h"
#include "WinchReleaseNewCommand.h"

/**
 *
 *
 * @author Kevin Sevcik
 */
class LoadAndDriveCommandGroup: public CommandGroup {
public:	
	LoadAndDriveCommandGroup();
};

#endif
