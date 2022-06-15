#ifndef _Collidable
#define _Collidable

#include "CollisionManager.h"
#include "CollisionGroup.h"
#include "Scene.h"
#include "SceneManager.h"
#include "AzulCore.h"
#include "CollisionVolume.h"
#include "RegistrationStates.h"
#include "SceneAttorney.h"

class CollisionRegistrationCmd;
class CollisionDeregistrationCmd;
class CollisionVolumeBSphere;

class Collidable
{
	friend class CollidableAttorney;

public:

	Collidable();
	Collidable(const Collidable&) = delete;
	Collidable& operator=(const Collidable&) = delete;
	virtual ~Collidable();

	void SubmitCollisionRegistration();
	void SubmitCollisionDeregistration();

	const CollisionVolume& GetCollisionVolume() const;
	const CollisionVolumeBSphere& GetDefaultCollisionVolume() const;

	enum class VolumeType
	{
		BSPHERE,
		AABB,
		OBB
	};

protected:

	void SetColliderModel(Model* mod, VolumeType vol);
	void UpdateCollisionData(const Matrix& mat);

private:

	CollisionGroup::CollidableCollectionRef pMyDeleteRef;

	CollisionManager::PWTypeID myID = CollisionManager::PWID_UNDEFINED;

	void SceneRegistration(); 
	void SceneDeregistration();

	CollisionRegistrationCmd* pRegistrationCmd;
	CollisionDeregistrationCmd* pDeregistrationCmd;
	RegistrationState currState;

	CollisionVolume* ColVolume;
	CollisionVolumeBSphere* defaultColV;
	Model* pColModel;

protected:
	template < typename C>
	void SetCollidableGroup()
	{
		myID = SceneAttorney::GetCollisionMgr(SceneManager::GetCurrentScene()).GetTypeID<C>();
	}
};

#endif _Collidable


