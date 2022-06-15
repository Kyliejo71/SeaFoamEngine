#ifndef _KeyBoardEventManager
#define _KeyBoardEventManager

#include "AzulCore.h"
#include "Inputable.h"
#include "SingleKeyEventManager.h"
#include <map>

class KeyBoardEventManager
{

public:

	using MapKeyManager = std::map<AZUL_KEY, SingleKeyEventManager*>; 

	KeyBoardEventManager() = default;
	KeyBoardEventManager(const KeyBoardEventManager&) = delete;
	KeyBoardEventManager& operator=(const KeyBoardEventManager&) = delete;
	virtual ~KeyBoardEventManager();

	void Deregister(Inputable* a, AZUL_KEY k, Inputable::EventType e);
	void Register(Inputable* a, AZUL_KEY k, Inputable::EventType e);
	void ProcessKeyEvent();

private:

	MapKeyManager mapSKMgrs;


};

#endif _KeyBoardEventManager


