#ifndef _UpdateRegistrationCommand
#define _UpdateRegistrationCommand

#include "CommandBase.h"

class Updatable;

class UpdateRegistrationCommand : public CommandBase
{
public:

	UpdateRegistrationCommand(Updatable* up);
	UpdateRegistrationCommand(const UpdateRegistrationCommand&) = default;
	UpdateRegistrationCommand& operator=(const UpdateRegistrationCommand&) = default;
	virtual ~UpdateRegistrationCommand() = default;

	virtual void execute();

private:

	Updatable* ptrUp;

};

#endif _UpdateRegistrationCommand

