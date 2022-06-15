#include "InputDeregistrationCommand.h"
#include "Inputable.h"
#include "InputableAttorney.h"

InputDeregistrationCommand::InputDeregistrationCommand(Inputable* in)
	:ptrIn(in), e(Inputable::EventType::KEY_PRESS), key(AZUL_KEY::KEY_0)
{
}

void InputDeregistrationCommand::execute()
{
	InputableAttorney::SceneDeregistration(ptrIn, key, e);
}

void InputDeregistrationCommand::SetEvent(Inputable::EventType ev)
{
	e = ev;
}

void InputDeregistrationCommand::SetKey(AZUL_KEY k)
{
	key = k;
}
