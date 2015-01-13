#ifndef ARMSPEEDCOMMAND_H
#define ARMSPEEDCOMMAND_H

#include "../CommandBase.h"


/**
 *
 *
 * @author Leopards57
 */
class ArmSpeedCommand: public CommandBase {
public:
	ArmSpeedCommand();
	ArmSpeedCommand(float setspeed);
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();

private:
	float speed;
	
};
#endif
