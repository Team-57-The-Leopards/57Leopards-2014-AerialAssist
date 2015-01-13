#ifndef WINCHRELEASENEWCOMMAND_H
#define WINCHRELEASENEWCOMMAND_H

#include "../CommandBase.h"

/**
 *
 *
 * @author Leopards57
 */
class WinchReleaseNewCommand: public CommandBase {
public:
	WinchReleaseNewCommand();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
