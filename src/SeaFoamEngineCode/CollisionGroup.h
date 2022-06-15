#ifndef _CollisionGroup
#define _CollisionGroup

#include <list>

class Collidable;
class CollisionVolumeAABB;

class CollisionGroup
{
	friend class CollisionGroupAttorney;
public:
	using CollidableCollection = std::list<Collidable*>;
	using CollidableCollectionRef = CollidableCollection::iterator;

	CollisionGroup();
	CollisionGroup(const CollisionGroup&) = delete;
	CollisionGroup& operator=(const CollisionGroup&) = delete;
	~CollisionGroup();

	const CollidableCollection& GetColliderCollection();
	void Register(Collidable* c, CollidableCollectionRef& ref);
	void Deregister(const CollidableCollectionRef& ref);

	const CollisionVolumeAABB& GetAABB() const;

private:

	void UpdateCollisionGroup();

	CollidableCollection colCollection;

	CollisionVolumeAABB* AABB;

	int Count;

};

#endif _CollisionGroup



