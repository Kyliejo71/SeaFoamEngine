#ifndef _CollisionVolumeBSphere
#define _CollisionVolumeBSphere

#include "AzulCore.h"
#include "CollisionVolume.h"

class CollisionVolumeAABB;
class CollisionVolumeOBB;

class CollisionVolumeBSphere : public CollisionVolume
{
public:

	CollisionVolumeBSphere() = default;
	CollisionVolumeBSphere(const CollisionVolumeBSphere&) = default;
	CollisionVolumeBSphere& operator=(const CollisionVolumeBSphere&) = default;
	virtual ~CollisionVolumeBSphere() = default;

	virtual void ComputeData(const Model* mod, const Matrix& mat);
	virtual void DebugView(const Vect& col) const;
	virtual bool IntersectAccept(const CollisionVolume& other) const;
	virtual bool IntersectVisit(const CollisionVolumeBSphere& other) const;
	virtual bool IntersectVisit(const CollisionVolumeAABB& other) const;
	virtual bool IntersectVisit(const CollisionVolumeOBB& other) const;
	const Vect& GetCenter() const;
	float GetRadius() const;

private:

	Vect Center;
	float Radius;

};

#endif _CollisionVolumeBSphere