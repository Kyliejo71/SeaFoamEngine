#include "SFMathTools.h"
#include <cmath>
#include "CollisionVolumeBSphere.h"
#include "CollisionVolumeAABB.h"
#include "CollisionVolumeOBB.h"


bool SFMathTools::Intersect(const CollisionVolumeBSphere& A, const CollisionVolumeBSphere& B)
{
	const Vect C1 = A.GetCenter();
	const Vect C2 = B.GetCenter();

	float totalR = A.GetRadius() + B.GetRadius();

	Vect dis = C2 - C1;

	float mag = std::sqrtf((dis.X() * dis.X()) + (dis.Y() * dis.Y()) + (dis.Z() * dis.Z()));

	return (mag <= totalR);
}

bool SFMathTools::Intersect(const CollisionVolumeBSphere& A, const CollisionVolumeAABB& B)
{
	CollisionVolumeAABB ColvB = B;

	Vect center = A.GetCenter();
	Vect min = ColvB.GetMin();
	Vect max = ColvB.GetMax();

	//RANGE CHECKS//

	float checkX = IsInRange(center.X(), min.X(), max.X());
	float checkY = IsInRange(center.Y(), min.Y(), max.Y());
	float checkZ = IsInRange(center.Z(), min.Z(), max.Z());

	Vect ClampedPoint;
	Vect difference;
	float radiusSqr = A.GetRadius() * A.GetRadius();
	float distanceSqr;

	//CENTER IN AABB
	if (checkX == center.X() && checkY == center.Y() && checkZ == center.Z())
	{
		return true;
	}
	//CENTER CLAMPED ON X
	else if(checkX == center.X())
	{
		ClampedPoint.X() = center.X();

		ClampedPoint.Y() = FindClampedPoint(checkY, center.Y(), min.Y(), max.Y());
		ClampedPoint.Z() = FindClampedPoint(checkZ, center.Z(), min.Z(), max.Z());

		difference = center - ClampedPoint;
		distanceSqr = difference.magSqr();
		return distanceSqr < radiusSqr;
	}

	//CENTER CLAMPED ON Y
	else if (checkY == center.Y())
	{
		ClampedPoint.Y() = center.Y();

		ClampedPoint.X() = FindClampedPoint(checkX, center.X(), min.X(), max.X());
		ClampedPoint.Z() = FindClampedPoint(checkZ, center.Z(), min.Z(), max.Z());

		difference = center - ClampedPoint;
		distanceSqr = difference.magSqr();
		return distanceSqr < radiusSqr;
	}

	//CENTER CLAMPED ON Z
	else if (checkZ == center.Z())
	{
		ClampedPoint.Z() = center.Z();

		ClampedPoint.X() = FindClampedPoint(checkX, center.X(), min.X(), max.X());
		ClampedPoint.Y() = FindClampedPoint(checkY, center.Y(), min.Y(), max.Y());

		difference = center - ClampedPoint;
		distanceSqr = difference.magSqr();
		return distanceSqr < radiusSqr;
	}

	return false;
}

bool SFMathTools::Intersect(const CollisionVolumeAABB& A, const CollisionVolumeAABB& B)
{
	CollisionVolumeAABB ColvA = A;
	const Vect MaxA = ColvA.GetMax();
	const Vect MinA = ColvA.GetMin();
	CollisionVolumeAABB ColvB = B;
	const Vect MaxB = ColvB.GetMax();
	const Vect MinB = ColvB.GetMin();

	bool IntersectOnX = false;
	bool IntersectOnY = false;
	bool IntersectOnZ = false;

	//if (IsVectorNonZero(SepratingAxis(A.GetWorld().get(ROW_0), B.GetWorld().get(ROW_0))))
	IntersectOnX = CheckAABBPoint(MaxA.X(), MaxB.X(), MinA.X(), MinB.X());
	//if (IsVectorNonZero(SepratingAxis(A.GetWorld().get(ROW_1), B.GetWorld().get(ROW_1))))
	IntersectOnY = CheckAABBPoint(MaxA.Y(), MaxB.Y(), MinA.Y(), MinB.Y());
	//if (IsVectorNonZero(SepratingAxis(A.GetWorld().get(ROW_2), B.GetWorld().get(ROW_2))))
	IntersectOnZ = CheckAABBPoint(MaxA.Z(), MaxB.Z(), MinA.Z(), MinB.Z());

	if (IntersectOnX && IntersectOnY && IntersectOnZ) return true;
	else return false;

}

bool SFMathTools::Intersect(const CollisionVolumeOBB& A, const CollisionVolumeOBB& B)
{
	Matrix WorldMatA = A.GetWorld();
	Matrix WorldMatB = B.GetWorld();
	Matrix InvWorldMatA = WorldMatA.getInv();
	Matrix InvWorldMatB = WorldMatB.getInv();
	Vect ACenter = A.GetCenter();
	Vect BCenter = B.GetCenter();
	Vect AHalfDiag = A.GetHalfDiagonal();
	Vect BHalfDiag = B.GetHalfDiagonal();
	float AScaleSqr = A.GetScaleSqr();
	float BScaleSqr = B.GetScaleSqr();

	//Find 3 face normals for A
	Vect xVectA = WorldMatA.get(ROW_0);
	Vect yVectA = WorldMatA.get(ROW_1);
	Vect zVectA = WorldMatA.get(ROW_2);
	//Find 3 face normals for B
	Vect xVectB = WorldMatB.get(ROW_0);
	Vect yVectB = WorldMatB.get(ROW_1);
	Vect zVectB = WorldMatB.get(ROW_2);

	//all axis
	Vect XAcrossYA = SepratingAxis(xVectA, yVectA);
	Vect XAcrossZA = SepratingAxis(xVectA, zVectA);
	Vect XAcrossXB = SepratingAxis(xVectA, xVectB);
	Vect XAcrossYB = SepratingAxis(xVectA, yVectB);
	Vect XAcrossZB = SepratingAxis(xVectA, zVectB);
	Vect YAcrossZA = SepratingAxis(yVectA, zVectA);
	Vect YAcrossXB = SepratingAxis(yVectA, xVectB);
	Vect YAcrossYB = SepratingAxis(yVectA, yVectB);
	Vect YAcrossZB = SepratingAxis(yVectA, zVectB);
	Vect ZAcrossXB = SepratingAxis(zVectA, xVectB);
	Vect ZAcrossYB = SepratingAxis(zVectA, yVectB);
	Vect ZAcrossZB = SepratingAxis(zVectA, zVectB);
	Vect XBcrossYB = SepratingAxis(xVectB, yVectB);
	Vect XBcrossZB = SepratingAxis(xVectB, zVectB);
	Vect YBcrossZB = SepratingAxis(yVectB, zVectB);

	if (IsVectorNonZero(XAcrossYA))
	{
		float maxProjA = MaxProjection(InvWorldMatA, XAcrossYA, AScaleSqr, AHalfDiag);
		float maxProjB = MaxProjection(InvWorldMatB, XAcrossYA, BScaleSqr, BHalfDiag);

		bool test = OBBOverlapTest(maxProjA, maxProjB, ACenter, BCenter, XAcrossYA);
		if(!test)
		{
			return false;
		}
	}
	if (IsVectorNonZero(XAcrossZA))
	{
		float maxProjA = MaxProjection(InvWorldMatA, XAcrossZA, AScaleSqr, AHalfDiag);
		float maxProjB = MaxProjection(InvWorldMatB, XAcrossZA, BScaleSqr, BHalfDiag);

		bool test = OBBOverlapTest(maxProjA, maxProjB, ACenter, BCenter, XAcrossZA);
		if (!test)
		{
			return false;
		}
	}
	if (IsVectorNonZero(XAcrossXB))
	{
		float maxProjA = MaxProjection(InvWorldMatA, XAcrossXB, AScaleSqr, AHalfDiag);
		float maxProjB = MaxProjection(InvWorldMatB, XAcrossXB, BScaleSqr, BHalfDiag);

		bool test = OBBOverlapTest(maxProjA, maxProjB, ACenter, BCenter, XAcrossXB);
		if (!test)
		{
			return false;
		}
	}
	if (IsVectorNonZero(XAcrossYB))
	{
		float maxProjA = MaxProjection(InvWorldMatA, XAcrossYB, AScaleSqr, AHalfDiag);
		float maxProjB = MaxProjection(InvWorldMatB, XAcrossYB, BScaleSqr, BHalfDiag);

		bool test = OBBOverlapTest(maxProjA, maxProjB, ACenter, BCenter, XAcrossYB);
		if (!test)
		{
			return false;
		}
	}
	if (IsVectorNonZero(XAcrossZB))
	{
		float maxProjA = MaxProjection(InvWorldMatA, XAcrossZB, AScaleSqr, AHalfDiag);
		float maxProjB = MaxProjection(InvWorldMatB, XAcrossZB, BScaleSqr, BHalfDiag);

		bool test = OBBOverlapTest(maxProjA, maxProjB, ACenter, BCenter, XAcrossZB);
		if (!test)
		{
			return false;
		}
	}
	if (IsVectorNonZero(YAcrossZA))
	{
		float maxProjA = MaxProjection(InvWorldMatA, YAcrossZA, AScaleSqr, AHalfDiag);
		float maxProjB = MaxProjection(InvWorldMatB, YAcrossZA, BScaleSqr, BHalfDiag);

		bool test = OBBOverlapTest(maxProjA, maxProjB, ACenter, BCenter, YAcrossZA);
		if (!test)
		{
			return false;
		}
	}
	if (IsVectorNonZero(YAcrossXB))
	{
		float maxProjA = MaxProjection(InvWorldMatA, YAcrossXB, AScaleSqr, AHalfDiag);
		float maxProjB = MaxProjection(InvWorldMatB, YAcrossXB, BScaleSqr, BHalfDiag);

		bool test = OBBOverlapTest(maxProjA, maxProjB, ACenter, BCenter, YAcrossXB);
		if (!test)
		{
			return false;
		}
	}
	if (IsVectorNonZero(YAcrossYB))
	{
		float maxProjA = MaxProjection(InvWorldMatA, YAcrossYB, AScaleSqr, AHalfDiag);
		float maxProjB = MaxProjection(InvWorldMatB, YAcrossYB, BScaleSqr, BHalfDiag);

		bool test = OBBOverlapTest(maxProjA, maxProjB, ACenter, BCenter, YAcrossYB);
		if (!test)
		{
			return false;
		}
	}
	if (IsVectorNonZero(YAcrossZB))
	{
		float maxProjA = MaxProjection(InvWorldMatA, YAcrossZB, AScaleSqr, AHalfDiag);
		float maxProjB = MaxProjection(InvWorldMatB, YAcrossZB, BScaleSqr, BHalfDiag);

		bool test = OBBOverlapTest(maxProjA, maxProjB, ACenter, BCenter, YAcrossZB);
		if (!test)
		{
			return false;
		}
	}
	if (IsVectorNonZero(ZAcrossXB))
	{
		float maxProjA = MaxProjection(InvWorldMatA, ZAcrossXB, AScaleSqr, AHalfDiag);
		float maxProjB = MaxProjection(InvWorldMatB, ZAcrossXB, BScaleSqr, BHalfDiag);

		bool test = OBBOverlapTest(maxProjA, maxProjB, ACenter, BCenter, ZAcrossXB);
		if (!test)
		{
			return false;
		}
	}
	if (IsVectorNonZero(ZAcrossYB))
	{
		float maxProjA = MaxProjection(InvWorldMatA, ZAcrossYB, AScaleSqr, AHalfDiag);
		float maxProjB = MaxProjection(InvWorldMatB, ZAcrossYB, BScaleSqr, BHalfDiag);

		bool test = OBBOverlapTest(maxProjA, maxProjB, ACenter, BCenter, ZAcrossYB);
		if (!test)
		{
			return false;
		}
	}
	if (IsVectorNonZero(ZAcrossZB))
	{
		float maxProjA = MaxProjection(InvWorldMatA, ZAcrossZB, AScaleSqr, AHalfDiag);
		float maxProjB = MaxProjection(InvWorldMatB, ZAcrossZB, BScaleSqr, BHalfDiag);

		bool test = OBBOverlapTest(maxProjA, maxProjB, ACenter, BCenter, ZAcrossZB);
		if (!test)
		{
			return false;
		}
	}
	if (IsVectorNonZero(XBcrossYB))
	{
		float maxProjA = MaxProjection(InvWorldMatA, XBcrossYB, AScaleSqr, AHalfDiag);
		float maxProjB = MaxProjection(InvWorldMatB, XBcrossYB, BScaleSqr, BHalfDiag);

		bool test = OBBOverlapTest(maxProjA, maxProjB, ACenter, BCenter, XBcrossYB);
		if (!test)
		{
			return false;
		}
	}
	if (IsVectorNonZero(XBcrossZB))
	{
		float maxProjA = MaxProjection(InvWorldMatA, XBcrossZB, AScaleSqr, AHalfDiag);
		float maxProjB = MaxProjection(InvWorldMatB, XBcrossZB, BScaleSqr, BHalfDiag);

		bool test = OBBOverlapTest(maxProjA, maxProjB, ACenter, BCenter, XBcrossZB);
		if (!test)
		{
			return false;
		}
	}
	if (IsVectorNonZero(YBcrossZB))
	{
		float maxProjA = MaxProjection(InvWorldMatA, YBcrossZB, AScaleSqr, AHalfDiag);
		float maxProjB = MaxProjection(InvWorldMatB, YBcrossZB, BScaleSqr, BHalfDiag);

		bool test = OBBOverlapTest(maxProjA, maxProjB, ACenter, BCenter, YBcrossZB);
		if (!test)
		{
			return false;
		}
	}
	return true;
}

bool SFMathTools::Intersect(const CollisionVolumeOBB& A, const CollisionVolumeAABB& B)
{
	UNREFERENCED_PARAMETER(A);
	UNREFERENCED_PARAMETER(B);
	return false;  
}

bool SFMathTools::Intersect(const CollisionVolumeOBB& A, const CollisionVolumeBSphere& B)
{
	Vect min = A.GetMin();
	Vect max = A.GetMax();
	Matrix OBBWorld = A.GetWorld();
	Matrix OBBWorldInv = OBBWorld.getInv();
	Vect center = B.GetCenter();
	Vect centerInv = center * OBBWorldInv;
	float RadiusInv = B.GetRadius() * Vect(OBBWorldInv.M0(), OBBWorldInv.M4(), OBBWorldInv.M8()).mag();

	float checkX = IsInRange(centerInv.X(), min.X(), max.X());
	float checkY = IsInRange(centerInv.Y(), min.Y(), max.Y());
	float checkZ = IsInRange(centerInv.Z(), min.Z(), max.Z());

	Vect ClampedPoint;
	Vect difference;
	float radiusSqr = RadiusInv * RadiusInv;
	float distanceSqr;

	//CENTER IN OBB
	if (checkX == centerInv.X() && checkY == centerInv.Y() && checkZ == centerInv.Z())
	{
		return true;
	} 
	//CENTER CLAMPED ON X
	else if (checkX == centerInv.X())
	{
		ClampedPoint.X() = centerInv.X();

		ClampedPoint.Y() = FindClampedPoint(checkY, centerInv.Y(), min.Y(), max.Y());
		ClampedPoint.Z() = FindClampedPoint(checkZ, centerInv.Z(), min.Z(), max.Z());

		ClampedPoint = ClampedPoint * OBBWorld;

		difference = center - ClampedPoint;
		distanceSqr = difference.magSqr();
		return distanceSqr < radiusSqr;
	}

	//CENTER CLAMPED ON Y
	else if (checkY == centerInv.Y())
	{
		ClampedPoint.Y() = centerInv.Y();

		ClampedPoint.X() = FindClampedPoint(checkX, centerInv.X(), min.X(), max.X());
		ClampedPoint.Z() = FindClampedPoint(checkZ, centerInv.Z(), min.Z(), max.Z());

		ClampedPoint = ClampedPoint * OBBWorld;

		difference = center - ClampedPoint;
		distanceSqr = difference.magSqr();
		return distanceSqr < radiusSqr;
	}

	//CENTER CLAMPED ON Z
	else if (checkZ == centerInv.Z())
	{
		ClampedPoint.Z() = centerInv.Z();

		ClampedPoint.X() = FindClampedPoint(checkX, centerInv.X(), min.X(), max.X());
		ClampedPoint.Y() = FindClampedPoint(checkY, centerInv.Y(), min.Y(), max.Y());

		ClampedPoint = ClampedPoint * OBBWorld;

		difference = center - ClampedPoint;
		distanceSqr = difference.magSqr();
		return distanceSqr < radiusSqr;
	}

	return false;

}

bool SFMathTools::CheckAABBPoint(const float maxA, const float maxB, const float minA, const float minB)
{
	if ((maxA <= maxB && maxA >= minB) || (minA >= minB && minA <= maxB))
	{
		return true;
	}
	else return false;
}

float SFMathTools::IsInRange(const float center, const float min, const float max)
{
	if(center > max)
	{
		return max;
	}
	if (center < min)
	{
		return min;
	}
	else return center;
}

float SFMathTools::FindClampedPoint(float check, float center, float min, float max)
{
	if (check == min)
	{
		return min;
	}
	else if (check == max)
	{
		return max;
	}
	else return center;
}

bool SFMathTools::IsVectorNonZero(Vect x)
{
	if (x.magSqr() > FLT_EPSILON)
	{
		return true;
	}
	else return false;
}

Vect SFMathTools::SepratingAxis(Vect a, Vect b)
{
	return a.cross(b);
}

float SFMathTools::MaxProjection(Matrix inv, Vect v, float scale, Vect halfdiag)
{
	float maxProjection;
	Vect Vinv = v * inv;

	float x = Vinv.X() * halfdiag.X();
	float y = Vinv.Y() * halfdiag.Y();
	float z = Vinv.Z() * halfdiag.Z();

	float tmp = std::abs(x) + std::abs(y) + std::abs(z);

	maxProjection = tmp / v.mag();
	return scale * maxProjection;
}

bool SFMathTools::OBBOverlapTest(float maxProjA, float maxProjB, Vect ACenter, Vect BCenter, Vect v)
{
	Vect tmp = (BCenter - ACenter);
	float tmpD = tmp.dot(v);
	float D = std::abs(tmpD) / v.mag();
	if (D <= (maxProjA + maxProjB))
	{
		return true;
	}
	else return false;
}

