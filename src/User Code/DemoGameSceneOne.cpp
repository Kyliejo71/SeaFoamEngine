#include "DemoGameSceneOne.h"
#include "PlayerTank.h"
#include "GroundPlane.h"
#include "GodCam.h"
#include "PlayerCamera.h"
#include "Wave.h"
#include "FastEnemy.h"
#include "Bullet.h"
#include "BaseEnemy.h"
#include "SceneManager.h"

const int DemoGameSceneOne::CurrentLives() const
{
	return player->GetLives();
}

void DemoGameSceneOne::Initialize()
{
	player = new PlayerTank();
	pCam = new GodCam();
	//pPlayerCam = new PlayerCamera(player);

	Wave1 = new Wave(3, 2, true, false, player);

	player->SetWave(Wave1);

	SetCollisionPair<Bullet, BaseEnemy>();
	SetCollisionPair<Bullet, PlayerTank>();
	SetCollisionPair<FastEnemy, PlayerTank>();
	SetCollisionPair<FastEnemy, Bullet>();

	for(float i = 0; i < 5; i++)
	{
		for(float j = 0; j < 5; j++)
		{
			terrain.push_back(new GroundPlane(Vect(i * 100, 0, j * 100)));
		}
	}

	Wave1->StartWave();

}

void DemoGameSceneOne::SceneEnd()
{
	delete player;
	delete pCam;
	delete pPlayerCam;
	delete Wave1;
	
	std::vector<GroundPlane*>::iterator it;

	for (it = terrain.begin(); it != terrain.end(); it++)
	{
		delete (*it);
	}


}
