#ifndef _CollisionManager
#define _CollisionManager

#include <vector>
#include <list>

#include "CollisionDispatch.h"
#include "CollisionTestPairCmd.h"

class CollisionGroup;
class CollisionTestCmdBase;

class CollisionManager
{
public:

	using PWTypeID = int;
	static const PWTypeID PWID_UNDEFINED = -1;

	using CollisionTestCmds = std::list<CollisionTestCmdBase*>;

	CollisionManager();
	CollisionManager(const CollisionManager&) = default;
	CollisionManager& operator=(const CollisionManager&) = default;
	~CollisionManager();

private:
	static PWTypeID TypeIDNextNumber;
	CollisionTestCmds colTestCmds;

	using CollisionGroupCollection = std::vector<CollisionGroup*>;
	CollisionGroupCollection ColGroupCollection;

	void SetGroupForTypeID(CollisionManager::PWTypeID ind);
	const int MAX_COLLISION_GROUP = 50;

public:
	template <typename C>
	PWTypeID GetTypeID()
	{
		static PWTypeID myTypeID = TypeIDNextNumber++;

		SetGroupForTypeID(myTypeID);

		DebugMsg::out("Type ID: %i\n", myTypeID);
		return myTypeID;
	}
	template<typename c1, typename c2>
	void SetCollisionPair()
	{
		CollisionGroup* pg1 = ColGroupCollection[GetTypeID<c1>()];
		CollisionGroup* pg2 = ColGroupCollection[GetTypeID <c2>()];

		CollisionDispatch<c1, c2>* pDispatch = new CollisionDispatch<c1, c2>();

		colTestCmds.push_back(new CollisionTestPairCmd(pg1, pg2, pDispatch));
	}

	CollisionGroup* GetColGroup(PWTypeID id);
	void ProcessCollisions();
	void UpdateCollisionGroups();
};



#endif _CollisionManager