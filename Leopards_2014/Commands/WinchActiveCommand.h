#ifndef WINCHACTIVECOMMAND_H
#define WINCHACTIVECOMMAND_H

#include "../CommandBase.h"

/**
 *
 *
 * @author Leopards57
 */
class WinchActiveCommand: public CommandBase {
public:
	WinchActiveCommand();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
