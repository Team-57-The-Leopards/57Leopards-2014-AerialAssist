#ifndef SIMPLEAUTONCOMMAND_H
#define SIMPLEAUTONCOMMAND_H

#include "../CommandBase.h"

/**
 *
 *
 * @author Leopards57
 */
class SimpleAutonCommand: public CommandBase {
public:
	SimpleAutonCommand();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
	double dist;
	bool inRange;
};

#endif
