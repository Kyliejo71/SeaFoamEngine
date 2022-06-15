#ifndef _BulletPool
#define _BulletPool

#include <stack>
#include <vector>

class Bullet;

class BulletPool
{
private:
	std::stack<Bullet*> recycledItems;
	std::vector<Bullet*> onSceneBullets;

public:
	BulletPool() = default;
	BulletPool(const BulletPool&) = delete;
	BulletPool& operator=(const BulletPool&) = delete;
	~BulletPool();

	Bullet* GetBullet();

	void ReturnBullet(Bullet* b);
};


#endif _BulletPool

