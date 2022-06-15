#include "CollisionVolumeAABB.h"
#include "CollisionVolumeOBB.h"
#include "SFMathTools.h"
#include "Visualizer.h"

void CollisionVolumeAABB::ComputeData(const Model* mod, const Matrix& mat)
{
	Vect* list = mod->getVectList();
	int num = mod->getVectNum();
	Vect tempmax = Vect(list->X(), list->Y(), list->Z()) * mat;
	Vect tempmin = Vect(list->X(), list->Y(), list->Z()) * mat;

	Vect tmp;

	for(int i = 0; i < num; i++)
	{ 
		tmp = Vect(list->X(), list->Y(), list->Z()) * mat;

		if (tmp.X() >= tempmax.X())
		{
			tempmax = Vect(tmp.X(), tempmax.Y(), tempmax.Z());
		}
		if (tmp.Y() >= tempmax.Y())
		{
			tempmax = Vect(tempmax.X(), tmp.Y(), tempmax.Z());
		}
		if (tmp.Z() >= tempmax.Z())
		{
			tempmax = Vect(tempmax.X(), tempmax.Y(), tmp.Z());
		}
	
		if (tmp.X() <= tempmin.X())
		{
			tempmin = Vect(tmp.X(), tempmin.Y(), tempmin.Z());
		}
		if (tmp.Y() <= tempmin.Y())
		{
			tempmin = Vect(tempmin.X(), tmp.Y(), tempmin.Z());
		}
		if (tmp.Z() <= tempmin.Z())
		{
			tempmin = Vect(tempmin.X(), tempmin.Y(), tmp.Z());
		}
		list++;
	}

	CornerMax = tempmax;
	CornerMin = tempmin;

	World = mat;
}

void CollisionVolumeAABB::DebugView(const Vect& col) const
{
	Visualizer::ShowAABBCMD(*this, col);
}

bool CollisionVolumeAABB::IntersectAccept(const CollisionVolume& other) const
{
	return other.IntersectVisit(*this);
}

bool CollisionVolumeAABB::IntersectVisit(const CollisionVolumeBSphere& other) const
{

	return SFMathTools::Intersect(other, *this);
}

bool CollisionVolumeAABB::IntersectVisit(const CollisionVolumeAABB& other) const
{

	return SFMathTools::Intersect(*this, other);
}

bool CollisionVolumeAABB::IntersectVisit(const CollisionVolumeOBB& other) const
{

	return SFMathTools::Intersect(other, *this);
}

void CollisionVolumeAABB::CollisionGroupAABB(Vect min, Vect max)
{
	CornerMin = min;
	CornerMax = max;
}

const Matrix& CollisionVolumeAABB::GetWorld() const
{
	return World;
}

Vect CollisionVolumeAABB::GetMin()
{
	return CornerMin;
}

Vect CollisionVolumeAABB::GetMax()
{
	return CornerMax;
}
