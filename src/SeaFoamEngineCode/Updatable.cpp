#include "Updatable.h"
#include "SceneManager.h"
#include "UpdateRegistrationCommand.h"
#include "UpdateDeregistrationCommand.h"
#include "SceneAttorney.h"

Updatable::Updatable()
{
	currState = RegistrationState::CURRENTLY_DEREGISTERED;
	pRegistrationCmd = new UpdateRegistrationCommand(this);
	pDeregistrationCmd = new UpdateDeregistrationCommand(this);
}

Updatable::~Updatable()
{
	delete pRegistrationCmd;
	delete pDeregistrationCmd;
}

void Updatable::SubmitUpdateRegistration()
{
	assert(currState == RegistrationState::CURRENTLY_DEREGISTERED);

	SceneAttorney::SubmitCommand(pRegistrationCmd, SceneManager::GetCurrentScene());

	currState = RegistrationState::PENDING_REGISTRATION;
}

void Updatable::SubmitUpdateDeregistration()
{
	assert(currState == RegistrationState::CURRENTLY_REGISTERED);

	SceneAttorney::SubmitCommand(pDeregistrationCmd, SceneManager::GetCurrentScene());

	currState = RegistrationState::PENDING_DEREGISTRATION;
}

void Updatable::SceneRegistration()
{
	assert(currState == RegistrationState::PENDING_REGISTRATION);

	SceneAttorney::Register(SceneManager::GetCurrentScene(), this, pMyDeleteRef);

	currState = RegistrationState::CURRENTLY_REGISTERED;
}

void Updatable::SceneDeregistration()
{
	assert(currState == RegistrationState::PENDING_DEREGISTRATION);

	SceneAttorney::Deregister(SceneManager::GetCurrentScene(), pMyDeleteRef);

	currState = RegistrationState::CURRENTLY_DEREGISTERED;
}
