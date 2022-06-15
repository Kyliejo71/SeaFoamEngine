#include "UpdatableManager.h"
#include "UpdatableAttorney.h"

UpdatableManager::~UpdatableManager()
{
	
}

void UpdatableManager::ProcessElements()
{
	for (StorageList::const_iterator it = storageList.begin(); it != storageList.end(); it++)
	{
		UpdatableAttorney::GameLoop::Update((*it));
	}
}

void UpdatableManager::Register(Updatable* up, StorageListIt &ref)
{
	ref = storageList.insert(storageList.end(), up);
}

void UpdatableManager::Deregister(StorageListIt& ref)
{
	storageList.erase(ref);
}
