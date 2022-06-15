#include "CollisionTestSelfCmd.h"
#include "CollisionGroup.h"
#include "CollisionDispatch.h"
#include "CollisionVolume.h"
#include "Collidable.h"

CollisionTestSelfCmd::CollisionTestSelfCmd(CollisionGroup* g, CollisionDispatchBase* pd)
	:pG(g), pDispatch(pd)
{
}

CollisionTestSelfCmd::~CollisionTestSelfCmd()
{
	delete pDispatch;
}

void CollisionTestSelfCmd::execute()
{
	const CollisionGroup::CollidableCollection& Collection = pG->GetColliderCollection();

	for(auto it1 = Collection.begin(); it1 != Collection.end(); it1++)
	{
		const CollisionVolume& cv1 = (*it1)->GetCollisionVolume();

		for(auto it2 = next(it1); it2 != Collection.end(); it2++)
		{
			const CollisionVolume& cv2 = (*it2)->GetCollisionVolume();

			if (cv1.IntersectAccept(cv2))
			{
				pDispatch->ProcessCallbacks(*it1, *it2);
			}
		}
	}
}
