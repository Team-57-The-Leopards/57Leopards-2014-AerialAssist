#ifndef COLORTESTCOMMAND_H
#define COLORTESTCOMMAND_H

#include "../CommandBase.h"

/**
 *
 *
 * @author Leopards57
 */
class ColorTestCommand: public CommandBase {
public:
	ColorTestCommand();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
