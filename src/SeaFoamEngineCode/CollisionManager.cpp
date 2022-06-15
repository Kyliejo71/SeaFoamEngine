#include "CollisionManager.h"
#include "CollisionGroup.h"
#include "CollisionTestCmdBase.h"
#include "CollisionGroupAttorney.h"

int CollisionManager::TypeIDNextNumber = 0;

CollisionManager::CollisionManager()
{
	for(int i = 0; i < MAX_COLLISION_GROUP; i++)
	{
		ColGroupCollection.push_back(nullptr);
	}
}

CollisionManager::~CollisionManager()
{
	CollisionGroupCollection::iterator it;

	for (it = ColGroupCollection.begin(); it != ColGroupCollection.end(); it++)
	{
		delete (*it);
	}

	CollisionTestCmds::iterator it2;

	for (it2 = colTestCmds.begin(); it2 != colTestCmds.end(); it2++)
	{
		delete (*it2);
	}
}

void CollisionManager::SetGroupForTypeID(CollisionManager::PWTypeID ind)
{
	if (ind < MAX_COLLISION_GROUP && ColGroupCollection[ind] == nullptr)
	{
		ColGroupCollection[ind] = new CollisionGroup();
	}
}

void CollisionManager::UpdateCollisionGroups()
{
	CollisionGroupCollection::iterator it;

	for (it = ColGroupCollection.begin(); it != ColGroupCollection.end(); it++)
	{
		if ((*it) != nullptr)
		{
			CollisionGroupAttorney::UpdateCollisionGroup((*it));
		}
	}
}

CollisionGroup* CollisionManager::GetColGroup(PWTypeID id)
{
	assert(id != -1);

	return ColGroupCollection[id];
}

void CollisionManager::ProcessCollisions()
{
	for(CollisionTestCmds::iterator it = colTestCmds.begin(); it != colTestCmds.end(); it++)
	{
		(*it)->execute();
	}
}
