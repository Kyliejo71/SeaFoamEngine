#include "Wave.h"
#include "BaseEnemy.h"
#include "PlayerTank.h"
#include "FastEnemy.h"
#include "DemoGameStart.h"
#include "SceneManager.h"

Wave::Wave(int numNormal, int numFast, bool fastOn, bool flyingOn, PlayerTank* playerRef)
	:NormalEnemies(numNormal), FastEnemies(numFast), FastCount(numFast), FastSwitch(fastOn), FlyingSwitch(flyingOn), CurrPlayer(playerRef)
{
	StartScreen = new DemoGameStart();

	TotalEnemiesToKill = numNormal + numFast;

	NormalSpawns.push_back(Vect(100, 1, 200));
	NormalSpawns.push_back(Vect(300, 1, 50));
	NormalSpawns.push_back(Vect(75, 1, 300));

	//Fast spawners

	FastSpawns.push_back(Vect(500, 1, 500));
	FastSpawns.push_back(Vect(500, 1, 0));
	FastSpawns.push_back(Vect(0, 1, 500));
	FastSpawns.push_back(Vect(0, 1, 0));

	SceneChanged = false;


	//Flying Spawners

}

Wave::~Wave()
{
	if(!SceneChanged)
	{
		delete StartScreen;
	}

	std::list<BaseEnemy*>::iterator it;

	for (it = OffScreenNorm.begin(); it != OffScreenNorm.end(); it++)
	{
		delete (*it);
	}

	std::list<FastEnemy*>::iterator it2;

	for (it2 = OffScreenFast.begin(); it2 != OffScreenFast.end(); it2++)
	{
		delete (*it2);
	}

	for (it = NormalList.begin(); it != NormalList.end(); it++)
	{
		delete (*it);
	}


	for (it2 = FastList.begin(); it2 != FastList.end(); it2++)
	{
		delete (*it2);
	}

}

void Wave::Alarm0()
{
	Vect playerPos = CurrPlayer->GetPos();

	if(playerPos.X() < 250 && playerPos.Z() < 250)
	{
		FastList.push_back(new FastEnemy(CurrPlayer, FastSpawns.at(0), this));
	}
	else if(playerPos.X() < 250 && playerPos.Z() >= 250)
	{
		FastList.push_back(new FastEnemy(CurrPlayer, FastSpawns.at(1), this));
	}
	else if(playerPos.X() >= 250 && playerPos.Z() < 250)
	{
		FastList.push_back(new FastEnemy(CurrPlayer, FastSpawns.at(2), this));
	}
	else 
	{
		FastList.push_back(new FastEnemy(CurrPlayer, FastSpawns.at(3), this));
	}

	FastCount--;

}

void Wave::Alarm1()
{
}

void Wave::StartWave()
{
	for(int x = 0; x < NormalEnemies; x++)
	{
		NormalList.push_back(new BaseEnemy(CurrPlayer, NormalSpawns.at(x), this));
	}

	if(FastSwitch)
	{
		SubmitAlarmRegistration(4, AlarmableManager::ALARM_0);
	}

	if(FlyingSwitch)
	{
		//FLYING ALARM
	}

}

void Wave::StopWave()
{
	//SubmitAlarmDeregistration(AlarmableManager::ALARM_0);

	std::list<BaseEnemy*>::iterator it;

	for (it = NormalList.begin(); it != NormalList.end(); it++)
	{
		delete (*it);
	}

	std::list<FastEnemy*>::iterator it2;

	for (it2 = FastList.begin(); it2 != FastList.end(); it2++)
	{
		delete (*it2);
	}
}

void Wave::FastDeath(FastEnemy* fe)
{
	fe->SubmitExit();
	OffScreenFast.push_back(fe);
	 
	TotalEnemiesToKill--;

	SubmitAlarmRegistration(4, AlarmableManager::ALARM_0);

	CheckEnemyCount();
}

void Wave::BaseDeath(BaseEnemy* be)
{
	be->SubmitExit();
	OffScreenNorm.push_back(be);

	TotalEnemiesToKill--;

	CheckEnemyCount();
}

void Wave::GameOverByDeath()
{
	SceneChanged = true;
	SceneManager::SetNextScene(StartScreen);
}

void Wave::GameOverByWin()
{
	SceneChanged = true;
	SceneManager::SetNextScene(StartScreen);
}

void Wave::CheckEnemyCount()
{
	if(TotalEnemiesToKill <= 0)
	{
		GameOverByWin();
	}
}

