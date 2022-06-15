#ifndef _Updatable
#define _Updatable

#include "UpdatableManager.h"
#include "RegistrationStates.h"

class UpdatableManager;
class UpdateRegistrationCommand;
class UpdateDeregistrationCommand;

class Updatable
{
	friend class UpdatableAttorney;

public:

	Updatable();
	Updatable(const Updatable&) = delete;
	Updatable& operator=(const Updatable&) = delete;
	virtual ~Updatable();

	void SubmitUpdateRegistration();
	void SubmitUpdateDeregistration();

private:
	UpdatableManager::StorageListIt pMyDeleteRef;

	RegistrationState currState;
	UpdateRegistrationCommand* pRegistrationCmd;
	UpdateDeregistrationCommand* pDeregistrationCmd;

	void SceneRegistration();
	void SceneDeregistration();

	virtual void Update() = 0;

};

#endif _Updatable
