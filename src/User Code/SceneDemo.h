#ifndef _SceneDemo
#define _SceneDemo

#include "AzulCore.h"
#include "Scene.h"

class Frigate;
class WorldPlane;
class GodCam;
class TreeObj;
class HUDTest;
class BlankFrigate;
class TerrainTest;

class SceneDemo : public Scene
{
public:

	SceneDemo() = default;
	SceneDemo(const SceneDemo&) = default;
	SceneDemo& operator=(const SceneDemo&) = default;
	~SceneDemo() = default;

private:

	friend class SeaFoamEngine;

	virtual void Initialize();
	virtual void SceneEnd();

	Frigate* GOFrig;
	WorldPlane* GOPlane;
	GodCam* pGodCam;
	//TreeObj* pTree;
	HUDTest* pHUD;
	BlankFrigate* pBlankFrig;
	TerrainTest* pTerrain;
};

#endif _SceneDemo
