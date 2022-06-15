#ifndef _DemoGameSceneOne
#define _DemoGameSceneOne

#include "AzulCore.h"
#include "Scene.h"
#include <vector>

class PlayerTank;
class GroundPlane;
class GodCam;
class PlayerCamera;
class Wave;

class DemoGameSceneOne : public Scene
{
public:

	DemoGameSceneOne() = default;
	DemoGameSceneOne(const DemoGameSceneOne&) = default;
	DemoGameSceneOne& operator=(const DemoGameSceneOne&) = default;
	~DemoGameSceneOne() = default;

	const int CurrentLives() const;

private:

	friend class SeaFoamEngine;

	virtual void Initialize();
	virtual void SceneEnd();

	PlayerTank* player;
	std::vector<GroundPlane*> terrain;
	GodCam* pCam;
	PlayerCamera* pPlayerCam;

	Wave* Wave1;

};

#endif _DemoGameSceneOne

