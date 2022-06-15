#ifndef _TankGameSceneOne
#define _TankGameSceneOne

#include "AzulCore.h"
#include "Scene.h"
#include <vector>

class PlayerTank;
class GroundPlane;
class GodCam;
class ExplodingBarrel;
class BaseEnemy;

class TankGameSceneOne : public Scene
{
public:

	TankGameSceneOne() = default;
	TankGameSceneOne(const TankGameSceneOne&) = default;
	TankGameSceneOne& operator=(const TankGameSceneOne&) = default;
	~TankGameSceneOne() = default;

private:

	virtual void Initialize();
	virtual void SceneEnd();

	PlayerTank* player;
	std::vector<GroundPlane*> terrain;
	GodCam* pCam;
	ExplodingBarrel* barrelTest;
	BaseEnemy* enemy;
};

#endif _TankGameSceneOne

