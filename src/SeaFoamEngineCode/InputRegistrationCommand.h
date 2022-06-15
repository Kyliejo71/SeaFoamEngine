#ifndef _InputRegistrationCommand
#define _InputRegistrationCommand

#include "CommandBase.h"
#include "AzulCore.h"
#include "Inputable.h"


class InputRegistrationCommand : public CommandBase
{
public:

	InputRegistrationCommand(Inputable* in);
	InputRegistrationCommand(const InputRegistrationCommand&) = default;
	InputRegistrationCommand& operator=(const InputRegistrationCommand&) = default;
	virtual ~InputRegistrationCommand() = default;

	virtual void execute();

	void SetEvent(Inputable::EventType ev);
	void SetKey(AZUL_KEY k);

private:

	Inputable* ptrIn;
	Inputable::EventType e;
	AZUL_KEY key;
};

#endif _InputRegistrationCommand




