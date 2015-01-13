#ifndef WINCHSTOPCOMMAND_H
#define WINCHSTOPCOMMAND_H

#include "../CommandBase.h"

/**
 *
 *
 * @author Leopards57
 */
class WinchStopCommand: public CommandBase {
public:
	WinchStopCommand();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
