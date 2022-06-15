#include "BulletFactory.h"
#include "BulletPool.h"
#include "Bullet.h"

BulletFactory* BulletFactory::ptrInstance = nullptr;

void BulletFactory::privCreateBullet(Vect pos, Matrix rot, Bullet::Sender x)
{
	Bullet* b = myBulletPool.GetBullet();

	b->Initialize(pos, rot, x);
}

void BulletFactory::privRecycleBullet(GameObject* b)
{
	myBulletPool.ReturnBullet(static_cast<Bullet*>(b));
}

void BulletFactory::Terminate()
{
	delete ptrInstance;
	ptrInstance = nullptr;
}