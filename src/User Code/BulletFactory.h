#ifndef _BulletFactory
#define _BulletFactory

#include "BulletPool.h"
#include "AzulCore.h"
#include "Bullet.h"

class GameObject;

class BulletFactory
{
private:

	static BulletFactory* ptrInstance;

	BulletFactory() = default;
	BulletFactory(const BulletFactory&) = delete;
	BulletFactory& operator=(const BulletFactory&) = delete;
	~BulletFactory() = default;

	static BulletFactory& Instance()	   
	{
		if (!ptrInstance)
			ptrInstance = new BulletFactory();
		return *ptrInstance;
	};

	BulletPool myBulletPool;


	void privCreateBullet(Vect pos, Matrix rot, Bullet::Sender x);
	void privRecycleBullet(GameObject* b);

public:

	static void CreateBullet(Vect pos, Matrix rot, Bullet::Sender x) { Instance().privCreateBullet(pos, rot, x); };
	static void RecycleBullet(GameObject* b) { Instance().privRecycleBullet(b); };

	static void Terminate();
};


#endif _BulletFactory
