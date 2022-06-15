#ifndef _VisualizerCmd
#define _VisualizerCmd

#include "Visualizer.h"
#include "CollisionVolumeBSphere.h"
#include "CollisionVolumeAABB.h"
#include "CollisionVolumeOBB.h"
class Vect;

class VisualizerCmd
{
public:

	VisualizerCmd(const CollisionVolumeBSphere& c, const Vect& col, Visualizer::CollidableType type);
	VisualizerCmd(const CollisionVolumeAABB& c, const Vect& col, Visualizer::CollidableType type);
	VisualizerCmd(const CollisionVolumeOBB& c, const Vect& col, Visualizer::CollidableType type);
	VisualizerCmd(const VisualizerCmd&) = default;
	VisualizerCmd& operator=(const VisualizerCmd&) = default;
	virtual ~VisualizerCmd() = default;

	virtual void execute();

private:

	CollisionVolumeBSphere BSphere;
	CollisionVolumeAABB AABB;
	CollisionVolumeOBB OBB;
	Vect color;
	Visualizer::CollidableType Type;
};

#endif _VisualizerCmd

