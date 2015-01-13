#ifndef LEDLIGHTCOMMAND_H
#define LEDLIGHTCOMMAND_H
#include "../CommandBase.h"

/**
 *
 *
 * @author Dillan
 */
class LedLightCommand: public CommandBase {
public:
	LedLightCommand();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
