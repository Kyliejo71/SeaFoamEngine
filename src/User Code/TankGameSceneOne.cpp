#include "TankGameSceneOne.h"
#include "PlayerTank.h"
#include "GroundPlane.h"
#include "GodCam.h"
#include "ExplodingBarrel.h"
#include "Bullet.h"
#include "BaseEnemy.h"

void TankGameSceneOne::Initialize()
{
	player = new PlayerTank();
	pCam = new GodCam();
	barrelTest = new ExplodingBarrel();
	//enemy = new BaseEnemy(player, );

	for (float i = 0; i < 5; i++)
	{
		for (float j = 0; j < 5; j++)
		{
			terrain.push_back(new GroundPlane(Vect(i * 100, 0, j * 100)));
		}
	}

	SetCollisionPair<ExplodingBarrel, Bullet>();
	SetCollisionPair<ExplodingBarrel, BaseEnemy>();
}

void TankGameSceneOne::SceneEnd()
{
	delete player;
	delete pCam;
	delete barrelTest;
	//delete enemy;

	std::vector<GroundPlane*>::iterator it;

	for (it = terrain.begin(); it != terrain.end(); it++)
	{
		delete (*it);
	}
}
