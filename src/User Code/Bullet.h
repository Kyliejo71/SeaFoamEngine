#ifndef _Bullet
#define _Bullet

#include "AzulCore.h"
#include "GameObject.h"

class BaseEnemy;
class PlayerTank;
class FastEnemy;

class Bullet : public GameObject
{
public:

	enum Sender
	{
		PLAYER,
		ENEMY
	};

	Bullet();
	Bullet(const Bullet&) = default;
	Bullet& operator=(const Bullet&) = default;
	virtual ~Bullet();

	void Initialize(Vect pos, Matrix rot, Sender x);

	virtual void Collision(BaseEnemy*);
	virtual void Collision(PlayerTank*);
	virtual void Collision(FastEnemy*);
	void Destroy();

	Sender WhoShot();

private:

	virtual void Update();
	virtual void Draw();
	virtual void Draw2D() {}
	virtual void KeyPressed(AZUL_KEY) {}
	virtual void KeyReleased(AZUL_KEY) {}
	virtual void SceneEntry();
	virtual void SceneExit();

	virtual void Alarm0();

	GraphicsObject_TextureLight* pGOBullet;
	Matrix BulletScale;
	Vect BulletPos;
	Matrix BulletRot;

	const float BulletTransSpeed = 2;
	const float BulletRotAng = .05f;
	bool BsphereToggle = false;

	Sender whoShot;
};

#endif _Bullet

