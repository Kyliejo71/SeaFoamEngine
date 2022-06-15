#ifndef _DrawDeregistrationCommand
#define _DrawDeregistrationCommand

#include "CommandBase.h"

class Drawable;

class DrawDeregistrationCommand : public CommandBase
{
public:

	DrawDeregistrationCommand(Drawable* dr);
	DrawDeregistrationCommand(const DrawDeregistrationCommand&) = default;
	DrawDeregistrationCommand& operator=(const DrawDeregistrationCommand&) = default;
	virtual ~DrawDeregistrationCommand() = default;

	virtual void execute();

private:

	Drawable* ptrDr;

};

#endif _DrawDeregistrationCommand


