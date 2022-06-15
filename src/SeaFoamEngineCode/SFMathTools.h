#ifndef _SFMathTools
#define _SFMathTools

class CollisionVolumeBSphere;
class CollisionVolumeAABB;
class CollisionVolumeOBB;
class Vect;
class Matrix;

namespace SFMathTools
{

	bool Intersect(const CollisionVolumeBSphere& A, const CollisionVolumeBSphere& B);
	bool Intersect(const CollisionVolumeBSphere& A, const CollisionVolumeAABB& B);
	bool Intersect(const CollisionVolumeAABB& A, const CollisionVolumeAABB& B);
	bool Intersect(const CollisionVolumeOBB& A, const CollisionVolumeOBB& B);
	bool Intersect(const CollisionVolumeOBB& A, const CollisionVolumeAABB& B);
	bool Intersect(const CollisionVolumeOBB& A, const CollisionVolumeBSphere& B);
	bool CheckAABBPoint(const float maxA, const float maxB, const float minA, const float minB);
	float IsInRange(const float center, const float min, const float max);
	float FindClampedPoint(float Check, float Center, float min, float max);
	bool IsVectorNonZero(Vect x);
	Vect SepratingAxis(Vect a, Vect b);
	float MaxProjection(Matrix inv, Vect v, float scale, Vect halfdiag);
	bool OBBOverlapTest(float maxProjA, float maxProjB, Vect ACenter, Vect BCenter, Vect v);

}

#endif _SFMathTools
