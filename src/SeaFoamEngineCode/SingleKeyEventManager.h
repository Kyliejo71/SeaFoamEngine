#ifndef _SingleKeyEventManager
#define _SingleKeyEventManager

#include "AzulCore.h"
#include "Inputable.h"
#include <list>

class SingleKeyEventManager
{

public:
	using keyCollection = std::list<Inputable*>;

	SingleKeyEventManager() = default;
	SingleKeyEventManager(AZUL_KEY k);
	SingleKeyEventManager(const SingleKeyEventManager&) = delete;
	SingleKeyEventManager& operator=(const SingleKeyEventManager&) = delete;
	virtual ~SingleKeyEventManager() = default;

	enum PressState
	{
		CURRENTLY_PRESSED,
		CURRENTLY_RELEASED
	};

	void Deregister(Inputable* a, Inputable::EventType e);
	void Register(Inputable* a, Inputable::EventType e);
	void ProcessKeyEvent();

private:
	
	AZUL_KEY key;
	keyCollection keyPress;
	keyCollection keyRelease;
	PressState currState;
};

#endif _SingleKeyEventManager

