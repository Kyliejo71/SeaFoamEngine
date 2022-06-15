#ifndef _InputDeregistrationCommand
#define _InputDeregistrationCommand

#include "CommandBase.h"
#include "AzulCore.h"
#include "Inputable.h"


class InputDeregistrationCommand : public CommandBase
{
public:

	InputDeregistrationCommand(Inputable* in);
	InputDeregistrationCommand(const InputDeregistrationCommand&) = default;
	InputDeregistrationCommand& operator=(const InputDeregistrationCommand&) = default;
	virtual ~InputDeregistrationCommand() = default;

	virtual void execute();

	void SetEvent(Inputable::EventType ev);
	void SetKey(AZUL_KEY k);

private:

	Inputable* ptrIn;
	Inputable::EventType e;
	AZUL_KEY key;
};

#endif _InputDeregistrationCommand



