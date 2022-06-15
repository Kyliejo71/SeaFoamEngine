#ifndef _FastEnemy
#define _FastEnemy

#include "AzulCore.h"
#include "GameObject.h"

class PlayerTank;
class Bullet;

class FastEnemy : public GameObject
{
public:

	FastEnemy() = delete;
	FastEnemy(PlayerTank* player, Vect StartingPos);
	FastEnemy(const FastEnemy&) = default;
	FastEnemy& operator=(const FastEnemy&) = default;
	virtual ~FastEnemy();

	virtual void Collision(Collidable*);

private:

	virtual void Update();
	virtual void Draw();
	virtual void Draw2D() {}
	virtual void KeyPressed(AZUL_KEY) {}
	virtual void KeyReleased(AZUL_KEY) {}
	virtual void SceneEntry();
	virtual void SceneExit();

	GraphicsObject_TextureLight* pGOTankBody;
	Matrix TankScale;
	Vect TankPos;
	Matrix TankRot;

	GraphicsObject_TextureLight* pGOTankTurret;
	Matrix TurretScale;
	Vect TurretPos;
	Matrix TurretRot;

	float TankRotAng = .05f;
	bool BsphereToggle = false;

	PlayerTank* CurrentPlayer;
	float speed;
};

#endif _FastEnemy
