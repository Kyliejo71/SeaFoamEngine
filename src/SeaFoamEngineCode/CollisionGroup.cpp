#include "CollisionGroup.h"
#include "AzulCore.h"
#include "Collidable.h"
#include "CollisionVolumeBSphere.h"
#include "Visualizer.h"
#include "CollisionVolumeAABB.h"

using CollidableCollection = std::list<Collidable*>;

CollisionGroup::CollisionGroup()
{
	AABB = new CollisionVolumeAABB();
	Count = 0;
}

CollisionGroup::~CollisionGroup()
{
	delete AABB;
}

const CollidableCollection& CollisionGroup::GetColliderCollection()
{
	return colCollection;
}

void CollisionGroup::Register(Collidable* c, CollidableCollectionRef& ref)
{
	ref = colCollection.insert(colCollection.begin(), c);
	Count++;
}

void CollisionGroup::Deregister(const CollidableCollectionRef& ref)
{
	colCollection.erase(ref);
	Count--;
}

const CollisionVolumeAABB& CollisionGroup::GetAABB() const
{
	return *AABB;
}

void CollisionGroup::UpdateCollisionGroup()
{
	if (Count > 0)
	{
		float tmp = colCollection.front()->GetDefaultCollisionVolume().GetRadius();
		Vect CurrentMax = colCollection.front()->GetDefaultCollisionVolume().GetCenter() + Vect(tmp, tmp, tmp, 0);
		Vect CurrentMin = colCollection.front()->GetDefaultCollisionVolume().GetCenter() - Vect(tmp, tmp, tmp, 0);

		float tmpRad;
		Vect tmpMin;
		Vect tmpMax;

		for (CollidableCollection::iterator it = colCollection.begin(); it != colCollection.end(); it++)
		{
			tmpRad = (*it)->GetDefaultCollisionVolume().GetRadius();
			tmpMax = (*it)->GetDefaultCollisionVolume().GetCenter() + Vect(tmpRad, tmpRad, tmpRad, 0);
			tmpMin = (*it)->GetDefaultCollisionVolume().GetCenter() - Vect(tmpRad, tmpRad, tmpRad, 0);

			if (tmpMax.X() >= CurrentMax.X())
			{
				CurrentMax.X() = tmpMax.X();
			}
			if (tmpMax.Y() >= CurrentMax.Y())
			{
				CurrentMax.Y() = tmpMax.Y();
			}
			if (tmpMax.Z() >= CurrentMax.Z())
			{
				CurrentMax.Z() = tmpMax.Z();
			}

			if (tmpMin.X() <= CurrentMin.X())
			{
				CurrentMin.X() = tmpMin.X();
			}
			if (tmpMin.Y() <= CurrentMin.Y())
			{
				CurrentMin.Y() = tmpMin.Y();
			}
			if (tmpMin.Z() <= CurrentMin.Z())
			{
				CurrentMin.Z() = tmpMin.Z();
			}
		}
		AABB->CollisionGroupAABB(CurrentMin, CurrentMax);
	}
}
