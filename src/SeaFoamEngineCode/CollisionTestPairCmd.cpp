#include "CollisionTestPairCmd.h"
#include "CollisionGroup.h"
#include "CollisionDispatch.h"
#include "CollisionVolumeBSphere.h"
#include "Collidable.h"
#include "CollisionVolume.h"
#include "SFMathTools.h"
#include "Visualizer.h"

CollisionTestPairCmd::CollisionTestPairCmd(CollisionGroup* g1, CollisionGroup* g2, CollisionDispatchBase* pd)
	:pG1(g1), pG2(g2), pDispatch(pd)
{
}

CollisionTestPairCmd::~CollisionTestPairCmd()
{
	delete pDispatch;
}

void CollisionTestPairCmd::execute()
{
	const CollisionGroup::CollidableCollection& Collection1 = pG1->GetColliderCollection();
	const CollisionGroup::CollidableCollection& Collection2 = pG2->GetColliderCollection();

	if (SFMathTools::Intersect(pG1->GetAABB(), pG2->GetAABB()))
	{
		Visualizer::ShowAABBCMD(pG1->GetAABB(), Vect(1.0f, 0.0f, 0.0f, 1.0f));
		Visualizer::ShowAABBCMD(pG2->GetAABB(), Vect(1.0f, 0.0f, 0.0f, 1.0f));
		for (auto it1 = Collection1.begin(); it1 != Collection1.end(); it1++)
		{
			if (SFMathTools::Intersect((*it1)->GetDefaultCollisionVolume(), pG2->GetAABB()))
			{
				Visualizer::ShowBSphereCMD((*it1)->GetDefaultCollisionVolume(), Vect(1.0f, 0.0f, 0.0f, 1.0f));
				Visualizer::ShowAABBCMD(pG2->GetAABB(), Vect(1.0f, 0.0f, 0.0f, 1.0f));

				const CollisionVolume& cv1 = (*it1)->GetCollisionVolume();

					for (auto it2 = Collection2.begin(); it2 != Collection2.end(); it2++)
					{
						const CollisionVolume& cv2 = (*it2)->GetCollisionVolume();

						if (SFMathTools::Intersect((*it1)->GetDefaultCollisionVolume(), (*it2)->GetDefaultCollisionVolume()))
						{
							if (cv1.IntersectAccept(cv2))
							{
								pDispatch->ProcessCallbacks(*it1, *it2);
							}
						}
					}
			}
			else
			{
				Visualizer::ShowBSphereCMD((*it1)->GetDefaultCollisionVolume(), Vect(0.0f, 1.0f, 1.0f, 1.0f));
				Visualizer::ShowAABBCMD(pG2->GetAABB(), Vect(0.0f, 1.0f, 1.0f, 1.0f));
			}
		}
	}
	else
	{
		Visualizer::ShowAABBCMD(pG1->GetAABB(), Vect(0.0f, 1.0f, 1.0f, 1.0f));
		Visualizer::ShowAABBCMD(pG2->GetAABB(), Vect(0.0f, 1.0f, 1.0f, 1.0f));
	}
}
