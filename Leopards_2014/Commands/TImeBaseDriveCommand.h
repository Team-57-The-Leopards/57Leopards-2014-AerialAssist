#ifndef TIMEBASEDRIVECOMMAND_H
#define TIMEBASEDRIVECOMMAND_H

#include "../CommandBase.h"

/**
 *
 *
 * @author Dillan
 */
class TImeBaseDriveCommand: public CommandBase {
public:
	TImeBaseDriveCommand(int time);
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
	int settime;
};

#endif
