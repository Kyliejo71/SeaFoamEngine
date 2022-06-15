#ifndef _CollisionVolumeAABB
#define _CollisionVolumeAABB

#include "AzulCore.h"
#include "CollisionVolume.h"

class CollisionVolumeBSphere;
class CollisionVolumeOBB;

class CollisionVolumeAABB : public CollisionVolume
{
public:

	CollisionVolumeAABB() = default;
	CollisionVolumeAABB(const CollisionVolumeAABB&) = default;
	CollisionVolumeAABB& operator=(const CollisionVolumeAABB&) = default;
	virtual ~CollisionVolumeAABB() = default;

	virtual void ComputeData(const Model* mod, const Matrix& mat);
	virtual void DebugView(const Vect& col) const;
	virtual bool IntersectAccept(const CollisionVolume& other) const;
	virtual bool IntersectVisit(const CollisionVolumeBSphere& other) const;
	virtual bool IntersectVisit(const CollisionVolumeAABB& other) const;
	virtual bool IntersectVisit(const CollisionVolumeOBB& other) const;

	void CollisionGroupAABB(Vect min, Vect max);

	const Matrix& GetWorld() const;
	
	Vect GetMin();
	Vect GetMax();

private:

	Vect CornerMax;
	Vect CornerMin;
	Matrix World;

};

#endif _CollisionVolumeAABB
