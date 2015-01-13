#ifndef WINCHPULLCOMMAND_H
#define WINCHPULLCOMMAND_H

#include "../CommandBase.h"

/**
 *
 *
 * @author Leopards57
 */
class WinchPullCommand: public CommandBase {
public:
	WinchPullCommand();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
