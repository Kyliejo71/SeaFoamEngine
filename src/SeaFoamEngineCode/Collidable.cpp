#include "Collidable.h"
#include "CollisionRegistrationCmd.h"
#include "CollisionDeregistrationCmd.h"
#include "SceneManager.h"
#include "SceneAttorney.h"
#include "CollisionVolume.h"
#include "CollisionVolumeBSphere.h"
#include "CollisionVolumeAABB.h"
#include "CollisionVolumeOBB.h"

Collidable::Collidable()
{
	pRegistrationCmd = new CollisionRegistrationCmd(this);
	pDeregistrationCmd = new CollisionDeregistrationCmd(this);
	currState = RegistrationState::CURRENTLY_DEREGISTERED;
	ColVolume = nullptr;
	defaultColV = new CollisionVolumeBSphere();
	pColModel = nullptr;
}

Collidable::~Collidable()
{
	delete pRegistrationCmd;
	delete pDeregistrationCmd;
	delete ColVolume;
	delete defaultColV;
}

void Collidable::SubmitCollisionRegistration()
{
	assert(currState == RegistrationState::CURRENTLY_DEREGISTERED);

	SceneAttorney::SubmitCommand(pRegistrationCmd, SceneManager::GetCurrentScene());

	currState = RegistrationState::PENDING_REGISTRATION;
}

void Collidable::SubmitCollisionDeregistration()
{
	assert(currState == RegistrationState::CURRENTLY_REGISTERED);

	SceneAttorney::SubmitCommand(pDeregistrationCmd, SceneManager::GetCurrentScene());

	currState = RegistrationState::PENDING_DEREGISTRATION;
}

const CollisionVolume& Collidable::GetCollisionVolume() const
{
	return *ColVolume;
}

const CollisionVolumeBSphere& Collidable::GetDefaultCollisionVolume() const
{
	return *defaultColV;
}

void Collidable::SceneRegistration()
{
	assert(currState == RegistrationState::PENDING_REGISTRATION);

	SceneAttorney::Register(SceneManager::GetCurrentScene(), this, pMyDeleteRef, myID);

	currState = RegistrationState::CURRENTLY_REGISTERED;
}

void Collidable::SceneDeregistration()
{
	assert(currState == RegistrationState::PENDING_DEREGISTRATION);

	SceneAttorney::Deregister(SceneManager::GetCurrentScene(), pMyDeleteRef, myID);

	currState = RegistrationState::CURRENTLY_DEREGISTERED;
}

void Collidable::SetColliderModel(Model* mod, VolumeType vol)
{
	pColModel = mod;
	delete ColVolume;

	switch (vol)
	{
	case Collidable::VolumeType::BSPHERE:
		ColVolume = new CollisionVolumeBSphere();
		break;
	case Collidable::VolumeType::AABB:
		ColVolume = new CollisionVolumeAABB();
		break;
	case Collidable::VolumeType::OBB:
		ColVolume = new CollisionVolumeOBB();
		break;
	default:
		break;
	}
}

 void Collidable::UpdateCollisionData(const Matrix& mat)
 {
	 defaultColV->ComputeData(pColModel, mat);
	 ColVolume->ComputeData(pColModel, mat);
 }
