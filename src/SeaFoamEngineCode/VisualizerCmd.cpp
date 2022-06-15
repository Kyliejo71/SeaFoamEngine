#include "VisualizerCmd.h"
#include "CollisionVolumeBSphere.h"
#include "CollisionVolumeAABB.h"
#include "CollisionVolumeOBB.h"
#include "VisualizerAttorney.h"

VisualizerCmd::VisualizerCmd(const CollisionVolumeBSphere& c, const Vect& col, Visualizer::CollidableType type)
{
	BSphere = c;
	color = col;
	Type = type;
}

VisualizerCmd::VisualizerCmd(const CollisionVolumeAABB& c, const Vect& col, Visualizer::CollidableType type)
{
	AABB = c;
	color = col;
	Type = type;
}

VisualizerCmd::VisualizerCmd(const CollisionVolumeOBB& c, const Vect& col, Visualizer::CollidableType type)
{
	OBB = c;
	color = col;
	Type = type;
}

void VisualizerCmd::execute()
{
	switch (Type)
	{
	case Visualizer::BSPHERE:
		VisualizerAttorney::ShowBSphere(BSphere, color, this);
		break;
	case Visualizer::AABB:
		VisualizerAttorney::ShowAABB(AABB, color, this);
		break;
	case Visualizer::OBB:
		VisualizerAttorney::ShowOBB(OBB, color, this);
		break;
	default:
		break;
	}
}
