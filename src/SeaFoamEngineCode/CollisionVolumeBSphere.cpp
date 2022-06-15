#include "CollisionVolumeBSphere.h"
#include "SFMathTools.h"
#include "Visualizer.h"

void CollisionVolumeBSphere::ComputeData(const Model* mod, const Matrix& mat)
{
	Vect newC = mod->getCenter();
	Radius = mod->getRadius() * Vect(mat.M0(), mat.M4(), mat.M8()).mag();
	Center = newC * mat;
}

void CollisionVolumeBSphere::DebugView(const Vect& col) const
{
	Visualizer::ShowBSphereCMD(*this, col);
}

bool CollisionVolumeBSphere::IntersectAccept(const CollisionVolume& other) const
{
	return other.IntersectVisit(*this);
}

bool CollisionVolumeBSphere::IntersectVisit(const CollisionVolumeBSphere& other) const
{
	return SFMathTools::Intersect(*this, other);
}

bool CollisionVolumeBSphere::IntersectVisit(const CollisionVolumeAABB& other) const
{

	return SFMathTools::Intersect(*this, other);
}

bool CollisionVolumeBSphere::IntersectVisit(const CollisionVolumeOBB& other) const
{
	return SFMathTools::Intersect(other, *this);
}

const Vect& CollisionVolumeBSphere::GetCenter() const
{
	return Center;
}

float CollisionVolumeBSphere::GetRadius() const
{
	return Radius;
}
