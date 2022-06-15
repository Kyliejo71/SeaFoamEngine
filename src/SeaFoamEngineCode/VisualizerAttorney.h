#ifndef _VisualizerAttorney
#define _VisualizerAttorney

#include "Visualizer.h"

class VisualizerCmd;

class VisualizerAttorney
{
	friend class SeaFoamEngine;
	friend class VisualizerCmd;
public:

	VisualizerAttorney() = default;
	VisualizerAttorney(const VisualizerAttorney&) = delete;
	VisualizerAttorney& operator=(const VisualizerAttorney&) = delete;
	~VisualizerAttorney() = default;

private:

	static void Delete() { Visualizer::Delete(); }
	static void ShowBSphere(const CollisionVolumeBSphere& S, const Vect& col, VisualizerCmd* cmd) { Visualizer::ShowBSphere(S, col, cmd); }
	static void ShowAABB(const CollisionVolumeAABB& S, const Vect& col, VisualizerCmd* cmd) { Visualizer::ShowAABB(S, col, cmd); }
	static void ShowOBB(const CollisionVolumeOBB& S, const Vect& col, VisualizerCmd* cmd) { Visualizer::ShowOBB(S, col, cmd); }
};	

#endif _VisualizerAttorney