#ifndef GOTOPICKUPCOMMANDGroup_H
#define GOTOPICKUPCOMMANDGroup_H

#include "Commands/CommandGroup.h"
#include "ArmSetCommand.h"
#include "WinchPullCommand.h"
#include "IntakeInCommand.h"
#include "WinchActiveCommand.h"
/**
 *
 *
 * @author Family
 */
class GoToPickUpCommandGroup: public CommandGroup {
public:	
	GoToPickUpCommandGroup();

};

#endif
