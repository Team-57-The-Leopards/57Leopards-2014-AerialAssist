#ifndef SHOOTERSETCOMMAND_H
#define SHOOTERSETCOMMAND_H

#include "../CommandBase.h"

/**
 *
 *
 * @author Family
 */
class ShooterSetCommand: public CommandBase {
public:
	ShooterSetCommand();
	ShooterSetCommand(int  num);
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
	
private:
	int select;
};

#endif
