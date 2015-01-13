#ifndef INTAKEINCOMMAND_H
#define INTAKEINCOMMAND_H

#include "../CommandBase.h"

/**
 *
 *
 * @author Leopards57
 */
class IntakeInCommand: public CommandBase {
public:
	IntakeInCommand();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
