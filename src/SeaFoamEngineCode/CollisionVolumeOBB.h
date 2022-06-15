#ifndef _CollisionVolumeOBB
#define _CollisionVolumeOBB

#include "AzulCore.h"
#include "CollisionVolume.h"

class CollisionVolumeBSphere;
class CollisionVolumeAABB;

class CollisionVolumeOBB : public CollisionVolume
{
public:

	CollisionVolumeOBB() = default;
	CollisionVolumeOBB(const CollisionVolumeOBB&) = default;
	CollisionVolumeOBB& operator=(const CollisionVolumeOBB&) = default;
	virtual ~CollisionVolumeOBB() = default;

	virtual void ComputeData(const Model* mod, const Matrix& mat);
	virtual void DebugView(const Vect& col) const;
	virtual bool IntersectAccept(const CollisionVolume& other) const;
	virtual bool IntersectVisit(const CollisionVolumeBSphere& other) const;
	virtual bool IntersectVisit(const CollisionVolumeAABB& other) const;
	virtual bool IntersectVisit(const CollisionVolumeOBB& other) const;
	Vect GetMin() const;
	Vect GetMax() const;
	Vect GetCenter() const;
	Vect GetHalfDiagonal() const;
	Matrix GetWorld() const;
	float GetScaleSqr() const;

private:

	Vect Min;
	Vect Max;
	Vect HalfDiag;
	Vect Center;
	Matrix World;
	float ScaleFactorSqr;

};

#endif _CollisionVolumeOBB
