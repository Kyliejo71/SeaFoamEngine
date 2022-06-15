#include "DrawableManager.h"
#include "DrawableAttorney.h"

DrawableManager::~DrawableManager()
{
}

void DrawableManager::ProcessElements()
{
	for (StorageList::const_iterator it = storageList.begin(); it != storageList.end(); it++)
	{
		DrawableAttorney::GameLoop::Draw(*it);
	}
	for (StorageList::const_iterator it = storageList.begin(); it != storageList.end(); it++)
	{
		DrawableAttorney::GameLoop::Draw2D(*it);
	}
}

void DrawableManager::Register(Drawable* up, StorageListIt& ref)
{
	ref = storageList.insert(storageList.end(), up);
}

void DrawableManager::Deregister(StorageListIt& ref)
{
	storageList.erase(ref);
}
