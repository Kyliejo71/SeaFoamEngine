#ifndef _CollisionGroupAttorney
#define _CollisionGroupAttorney

#include "CollisionGroup.h"

class CollisionGroupAttorney
{
	friend class CollisionManager;
public:

	CollisionGroupAttorney() = default;
	CollisionGroupAttorney(const CollisionGroupAttorney&) = delete;
	CollisionGroupAttorney& operator=(const CollisionGroupAttorney&) = delete;
	~CollisionGroupAttorney() = default;

private:

	static void UpdateCollisionGroup(CollisionGroup* cg) { cg->UpdateCollisionGroup(); }

};

#endif _CollisionGroupAttorney



