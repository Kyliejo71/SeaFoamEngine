#include "SingleKeyEventManager.h"
#include "InputableAttorney.h"

SingleKeyEventManager::SingleKeyEventManager(AZUL_KEY k)
	:key(k), currState(PressState::CURRENTLY_RELEASED)
{
}

void SingleKeyEventManager::Deregister(Inputable* a, Inputable::EventType e)
{
	keyCollection::iterator it;
	if (e == Inputable::EventType::KEY_PRESS)
	{
		for (it = keyPress.begin(); it != keyPress.end(); it++)
		{
			if((*it) == a)
			{
				keyPress.erase(it);
			}
		}
	}
	else
	{
		for (it = keyRelease.begin(); it != keyRelease.end(); it++)
		{
			if ((*it) == a)
			{
				keyRelease.erase(it);
			}
		}
	}
}

void SingleKeyEventManager::Register(Inputable* a, Inputable::EventType e)
{
	if(e == Inputable::EventType::KEY_PRESS)
	{
		keyPress.push_back(a);
	}
	if(e == Inputable::EventType::KEY_RELEASE)
	{
		keyRelease.push_back(a);
	}
}

void SingleKeyEventManager::ProcessKeyEvent()
{
	if (Keyboard::GetKeyState(key))
	{
		if (currState == PressState::CURRENTLY_RELEASED)
		{
			keyCollection::iterator it;
			for (it = keyPress.begin(); it != keyPress.end(); it++)
			{
				InputableAttorney::KeyPressed((*it), key);
			}
			currState = PressState::CURRENTLY_PRESSED;
		}
	}
	else
	{
		if (currState == PressState::CURRENTLY_PRESSED)
		{
			keyCollection::iterator it;
			for (it = keyRelease.begin(); it != keyRelease.end(); it++)
			{
				InputableAttorney::KeyReleased((*it), key);
			}
			currState = PressState::CURRENTLY_RELEASED;
		}
	}
}
