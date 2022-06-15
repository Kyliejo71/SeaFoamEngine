#ifndef _BaseEnemy
#define _BaseEnemy

#include "AzulCore.h"
#include "GameObject.h"

class PlayerTank;
class Bullet;
class Wave;

class BaseEnemy : public GameObject
{
public:

	BaseEnemy() = delete;
	BaseEnemy(PlayerTank* player, Vect StartingPos, Wave* currWave);
	BaseEnemy(const BaseEnemy&) = default;
	BaseEnemy& operator=(const BaseEnemy&) = default;
	virtual ~BaseEnemy();

	virtual void Collision(Bullet* b);

private:

	void UpdateDirection();
	void ShootAtPlayer();

	virtual void Update();
	virtual void Draw();
	virtual void Draw2D() {}
	virtual void KeyPressed(AZUL_KEY) {}
	virtual void KeyReleased(AZUL_KEY) {}
	virtual void SceneEntry();
	virtual void SceneExit();
	virtual void Alarm0();

	GraphicsObject_TextureLight* pGOTankBody;
	Matrix TankScale;
	Vect TankPos;
	Matrix TankRot;

	GraphicsObject_TextureLight* pGOTankTurret;
	Matrix TurretScale;
	Vect TurretPos;
	Matrix TurretRot;

	float TankRotAng;
	bool BsphereToggle = false;

	int health;
	PlayerTank* CurrentPlayer;
	float speed;

	Matrix TankWorld;
	Matrix TurretWorld;

	Wave* CurrentWave;
};

#endif _BaseEnemy
