#ifndef GOTODISTANCECOMMAND_H
#define GOTODISTANCECOMMAND_H

#include "../CommandBase.h"

/**
 *
 *
 * @author Leopards57
 */
class GotoDistanceCommand: public CommandBase {
public:
	GotoDistanceCommand(double dist);
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
private:
	double currentdistance,setdistance,threshhold;
	bool inRange;
};

#endif
