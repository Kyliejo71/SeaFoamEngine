#ifndef _DrawRegistrationCommand
#define _DrawRegistrationCommand

#include "CommandBase.h"

class Drawable;

class DrawRegistrationCommand : public CommandBase
{
public:

	DrawRegistrationCommand(Drawable* dr);
	DrawRegistrationCommand(const DrawRegistrationCommand&) = default;
	DrawRegistrationCommand& operator=(const DrawRegistrationCommand&) = default;
	virtual ~DrawRegistrationCommand() = default;

	virtual void execute();

private:

	Drawable* ptrDr;

};

#endif _DrawRegistrationCommand


