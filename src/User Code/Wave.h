#ifndef _Wave
#define _Wave

#include <list>
#include <vector>
#include "AzulCore.h"
#include "Alarmable.h"

class BaseEnemy;
class PlayerTank;
class FastEnemy;
class DemoGameStart;

class Wave : public Alarmable
{
public:

	Wave(int numNormal, int numFast, bool fastOn, bool flyingOn, PlayerTank* playerRef);
	Wave() = default;
	Wave(const Wave&) = default;
	Wave& operator=(const Wave&) = default;
	~Wave();

	virtual void Alarm0();
	virtual void Alarm1();

	void StartWave();
	void StopWave();

	void FastDeath(FastEnemy* fe);
	void BaseDeath(BaseEnemy* be);

	void GameOverByDeath();
	void GameOverByWin();

private:

	void CheckEnemyCount();


	PlayerTank* CurrPlayer;

	int NormalEnemies;
	int FastEnemies;

	int FastCount;

	int TotalEnemiesToKill;

	bool FastSwitch;
	bool FlyingSwitch;

	std::vector<Vect> NormalSpawns;
	std::vector<Vect> FastSpawns;
	std::vector<Vect> FlyingSpawns;

	std::list<BaseEnemy*> NormalList;
	std::list<FastEnemy*> FastList;

	std::list<BaseEnemy*> OffScreenNorm;
	std::list<FastEnemy*> OffScreenFast;

	DemoGameStart* StartScreen;

	bool SceneChanged;

};

#endif _Wave


