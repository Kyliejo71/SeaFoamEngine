#ifndef _PlayerTank
#define _PlayerTank

#include "AzulCore.h"
#include "GameObject.h"

class FastEnemy;
class Bullet;
class BaseEnemy;
class Wave;
class LifeBar;

class PlayerTank : public GameObject
{
public:

	PlayerTank();
	PlayerTank(const PlayerTank&) = default;
	PlayerTank& operator=(const PlayerTank&) = default;
	virtual ~PlayerTank();

	const Vect GetPos() const;
	const Vect GetFwd() const;
	const Vect GetUp() const;
	Matrix GetRot();

	const int GetLives()const;

	void SetWave(Wave* currWave);

	virtual void Collision(FastEnemy*);
	virtual void Collision(Bullet* b);

private:

	virtual void Update();
	virtual void Draw();
	virtual void Draw2D() {}
	virtual void KeyPressed(AZUL_KEY );
	virtual void KeyReleased(AZUL_KEY) {}
	virtual void SceneEntry();
	virtual void SceneExit();

	void CheckHealth();

	GraphicsObject_TextureLight* pGOTankBody;
	Matrix TankScale;
	Vect TankPos;
	Matrix TankRot;

	GraphicsObject_TextureLight* pGOTankTurret;
	Matrix TurretScale;
	Vect TurretPos;
	Matrix TurretRot;

	AZUL_KEY forward = AZUL_KEY::KEY_W;
	AZUL_KEY back = AZUL_KEY::KEY_S;
	AZUL_KEY left = AZUL_KEY::KEY_A;
	AZUL_KEY right = AZUL_KEY::KEY_D;
	AZUL_KEY rotLeft = AZUL_KEY::KEY_Q;
	AZUL_KEY rotRight = AZUL_KEY::KEY_E;
	AZUL_KEY fire = AZUL_KEY::KEY_SPACE;

	const float TankTransSpeed = 1;
	const float TankRotAng = .05f;
	bool BsphereToggle = false;

	Matrix TankWorld;
	Matrix TurretWorld;

	Wave* CurrentWave;

	LifeBar* HealthBar;

	int health;
};

#endif _PlayerTank

