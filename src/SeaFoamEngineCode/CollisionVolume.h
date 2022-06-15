#ifndef _CollisionVolume
#define _CollisionVolume

#include "AzulCore.h"

class CollisionVolumeBSphere;
class CollisionVolumeAABB;
class CollisionVolumeOBB;

class CollisionVolume
{
public:

	CollisionVolume() = default;
	CollisionVolume(const CollisionVolume&) = default;
	CollisionVolume& operator=(const CollisionVolume&) = default;
	virtual ~CollisionVolume() = default;

	virtual void ComputeData(const Model* mod, const Matrix& mat) = 0;
	virtual void DebugView(const Vect& col) const = 0;
	virtual bool IntersectAccept(const CollisionVolume& other) const = 0;
	virtual bool IntersectVisit(const CollisionVolumeBSphere& other) const = 0;
	virtual bool IntersectVisit(const CollisionVolumeAABB& other) const = 0;
	virtual bool IntersectVisit(const CollisionVolumeOBB& other) const = 0;

};

#endif _CollisionVolume