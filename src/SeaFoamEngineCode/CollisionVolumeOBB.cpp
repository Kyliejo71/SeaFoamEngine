#include "CollisionVolumeOBB.h"
#include "SFMathTools.h"
#include "Visualizer.h"

void CollisionVolumeOBB::ComputeData(const Model* mod, const Matrix& mat)
{
	Min = mod->getMinAABB();
	Max = mod->getMaxAABB();

	HalfDiag = 0.5 * (Max - Min);
	Center = (Min + HalfDiag) * mat;

	float s = Vect(mat.M0(), mat.M4(), mat.M8()).mag();

	ScaleFactorSqr = s * s;

	World = mat;
}

void CollisionVolumeOBB::DebugView(const Vect& col) const
{
	Visualizer::ShowOBBCMD(*this, col);
}

bool CollisionVolumeOBB::IntersectAccept(const CollisionVolume& other) const
{
	return other.IntersectVisit(*this);
}

bool CollisionVolumeOBB::IntersectVisit(const CollisionVolumeBSphere& other) const
{
	return SFMathTools::Intersect(*this, other);
}

bool CollisionVolumeOBB::IntersectVisit(const CollisionVolumeAABB& other) const
{
	return SFMathTools::Intersect(*this, other);
}

bool CollisionVolumeOBB::IntersectVisit(const CollisionVolumeOBB& other) const
{
	return SFMathTools::Intersect(*this, other);
}

Vect CollisionVolumeOBB::GetMin() const
{
	return Min;
}

Vect CollisionVolumeOBB::GetMax() const
{
	return Max;
}

Vect CollisionVolumeOBB::GetCenter() const
{
	return Center;
}

Vect CollisionVolumeOBB::GetHalfDiagonal() const
{
	return HalfDiag;
}

Matrix CollisionVolumeOBB::GetWorld() const
{
	return World;
}

float CollisionVolumeOBB::GetScaleSqr() const
{
	return ScaleFactorSqr;
}
