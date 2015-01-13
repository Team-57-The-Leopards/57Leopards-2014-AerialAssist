#ifndef FIRECOMMAND_H
#define FIRECOMMAND_H

#include "../CommandBase.h"

/**
 *
 *
 * @author Family
 */
class FireCommand: public CommandBase {
public:
	FireCommand();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
