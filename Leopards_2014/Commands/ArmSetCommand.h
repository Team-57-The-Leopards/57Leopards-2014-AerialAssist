#ifndef ARMSETCOMMAND_H
#define ARMSETCOMMAND_H

#include "../CommandBase.h"

/**
 *
 *
 * @author Family
 */
class ArmSetCommand: public CommandBase {
public:
	ArmSetCommand();
	ArmSetCommand(int num);
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();

private:
	int select;
	bool isSet;
};

#endif
