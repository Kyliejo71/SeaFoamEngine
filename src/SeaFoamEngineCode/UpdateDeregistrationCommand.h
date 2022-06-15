#ifndef _UpdateDeregistrationCommand
#define _UpdateDeregistrationCommand

#include "CommandBase.h"

class Updatable;

class UpdateDeregistrationCommand : public CommandBase
{
public:

	UpdateDeregistrationCommand(Updatable* up);
	UpdateDeregistrationCommand(const UpdateDeregistrationCommand&) = default;
	UpdateDeregistrationCommand& operator=(const UpdateDeregistrationCommand&) = default;
	virtual ~UpdateDeregistrationCommand() = default;

	virtual void execute();

private:

	Updatable* ptrUp;

};

#endif _UpdateDeregistrationCommand


