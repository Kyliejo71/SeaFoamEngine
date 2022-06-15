#include "KeyBoardEventManager.h"
#include "SingleKeyEventManager.h"

KeyBoardEventManager::~KeyBoardEventManager()
{
	MapKeyManager::iterator it;
	for (it = mapSKMgrs.begin(); it != mapSKMgrs.end(); it++)
	{
		delete it->second;
	}
	mapSKMgrs.clear();
}

void KeyBoardEventManager::Deregister(Inputable* a, AZUL_KEY k, Inputable::EventType e)
{
	MapKeyManager::iterator it;
	it = mapSKMgrs.find(k);
	assert(it != mapSKMgrs.end());

	it->second->Deregister(a, e);
}

void KeyBoardEventManager::Register(Inputable* a, AZUL_KEY k, Inputable::EventType e)
{
	MapKeyManager::iterator it;
	SingleKeyEventManager* newKey;

	it = mapSKMgrs.find(k);

	if (it != mapSKMgrs.end())
	{
		newKey = it->second;
		newKey->Register(a, e);
	}
	else
	{
		newKey = new SingleKeyEventManager(k);
		newKey->Register(a, e);
		mapSKMgrs.insert({ k, newKey });
	}
}

void KeyBoardEventManager::ProcessKeyEvent()
{
	MapKeyManager::iterator it;
	for(it = mapSKMgrs.begin(); it != mapSKMgrs.end(); it++)
	{
		it->second->ProcessKeyEvent();
	}
}
