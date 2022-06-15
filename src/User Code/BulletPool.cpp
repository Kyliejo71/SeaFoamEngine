#include "BulletPool.h"
#include "Bullet.h"

BulletPool::~BulletPool()
{
	while (!recycledItems.empty())
	{
		delete recycledItems.top();
		recycledItems.pop();
	}
	std::vector<Bullet*>::iterator it;

	for (it = onSceneBullets.begin(); it != onSceneBullets.end(); it++)
	{
		delete (*it);
	}
}

Bullet* BulletPool::GetBullet()
{
	Bullet* b;

	if (recycledItems.empty())
	{
		b = new Bullet();
	}
	else
	{
		b = recycledItems.top();
		recycledItems.pop();
	}

	onSceneBullets.push_back(b);

	return b;
}

void BulletPool::ReturnBullet(Bullet* b)
{
	std::vector<Bullet*>::iterator it;

	for (it = onSceneBullets.begin(); it != onSceneBullets.end(); it++)
	{
		if((*it) == b)
		{
			onSceneBullets.erase(it);
			break;
		}
	}


	recycledItems.push(static_cast<Bullet*>(b));
}