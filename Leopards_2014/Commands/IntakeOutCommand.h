#ifndef INTAKEOUTCOMMAND_H
#define INTAKEOUTCOMMAND_H

#include "../CommandBase.h"

/**
 *
 *
 * @author Leopards57
 */
class IntakeOutCommand: public CommandBase {
public:
	IntakeOutCommand();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
