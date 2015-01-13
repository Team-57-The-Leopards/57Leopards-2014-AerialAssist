#ifndef WINCHEXTENDCOMMAND_H
#define WINCHEXTENDCOMMAND_H

#include "../CommandBase.h"

/**
 *
 *
 * @author Leopards57
 */
class WinchExtendCommand: public CommandBase {
public:
	WinchExtendCommand();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
