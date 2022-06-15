#ifndef _Visualizer
#define _Visualizer

#include "AzulCore.h"

class CollisionVolumeBSphere;
class CollisionVolumeAABB;
class CollisionVolumeOBB;
class CollisionVolume;
class VisualizerCmd;

class Visualizer : public Align16
{
	friend class VisualizerAttorney;
public:

	enum CollidableType
	{
		BSPHERE,
		AABB,
		OBB
	};

private:

	static Visualizer* ptrInstance;

	// constructor
	Visualizer();
	Visualizer(const Visualizer&) = delete;
	Visualizer& operator=(const Visualizer&) = delete;
	~Visualizer();

	static Visualizer& Instance()
	{
		if (!ptrInstance)
			ptrInstance = new Visualizer();
		return *ptrInstance;
	};

	static void Delete();

	static Vect DEFAULT_COLOR;
	GraphicsObject_WireframeConstantColor* WFUnitSphere;
	GraphicsObject_WireframeConstantColor* WFUnitBox;

	void privRenderBSphere(Matrix& S, const Vect& col);
	void privRenderBox(Matrix& S, const Vect& col);

	static void ShowBSphere(const CollisionVolumeBSphere& S, const Vect& col, VisualizerCmd* cmd);
	static void ShowAABB(const CollisionVolumeAABB& S, const Vect& col, VisualizerCmd* cmd);
	static void ShowOBB(const CollisionVolumeOBB& S, const Vect& col, VisualizerCmd* cmd);

	void privShowBSphereCMD(const CollisionVolumeBSphere& S, const Vect& col);
	void privShowAABBCMD(const CollisionVolumeAABB& S, const Vect& col);
	void privShowOBBCMD(const CollisionVolumeOBB& S, const Vect& col);

public:

	static void ShowBSphereCMD(const CollisionVolumeBSphere& S, const Vect& col) { Instance().privShowBSphereCMD(S, col); }
	static void ShowAABBCMD(const CollisionVolumeAABB& S, const Vect& col) { Instance().privShowAABBCMD(S, col); }
	static void ShowOBBCMD(const CollisionVolumeOBB& S, const Vect& col) { Instance().privShowOBBCMD(S, col); }
	static void ShowCollisionVolume(const CollisionVolume& c, const Vect& col = DEFAULT_COLOR);

};

#endif _Visualizer
