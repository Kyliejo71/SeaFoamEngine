#include "InputRegistrationCommand.h"
#include "InputableAttorney.h"

InputRegistrationCommand::InputRegistrationCommand(Inputable* in)
	:ptrIn(in), e(Inputable::EventType::KEY_PRESS), key(AZUL_KEY::KEY_0)
{
}

void InputRegistrationCommand::execute()
{
	InputableAttorney::SceneRegistration(ptrIn, key, e);
}

void InputRegistrationCommand::SetEvent(Inputable::EventType ev)
{
	e = ev;
}

void InputRegistrationCommand::SetKey(AZUL_KEY k)
{
	key = k;
}
