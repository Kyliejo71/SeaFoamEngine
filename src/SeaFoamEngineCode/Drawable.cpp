#include "Drawable.h"
#include "SceneManager.h"
#include "DrawRegistrationCommand.h"
#include "DrawDeregistrationCommand.h"
#include "SceneAttorney.h"

Drawable::Drawable()
{
	currState = RegistrationState::CURRENTLY_DEREGISTERED;
	pRegistrationCmd = new DrawRegistrationCommand(this);
	pDeregistrationCmd = new DrawDeregistrationCommand(this);
}

Drawable::~Drawable()
{
	delete pRegistrationCmd;
	delete pDeregistrationCmd;
}

void Drawable::SubmitDrawRegistration()
{
	assert(currState == RegistrationState::CURRENTLY_DEREGISTERED);

	SceneAttorney::SubmitCommand(pRegistrationCmd, SceneManager::GetCurrentScene());

	currState = RegistrationState::PENDING_REGISTRATION;
}

void Drawable::SubmitDrawDeregistration()
{
	assert(currState == RegistrationState::CURRENTLY_REGISTERED);

	SceneAttorney::SubmitCommand(pDeregistrationCmd, SceneManager::GetCurrentScene());

	currState = RegistrationState::PENDING_DEREGISTRATION;
}

void Drawable::SceneRegistration()
{
	assert(currState == RegistrationState::PENDING_REGISTRATION);

	SceneAttorney::Register(SceneManager::GetCurrentScene(), this, pMyDeleteRef);

	currState = RegistrationState::CURRENTLY_REGISTERED;
}

void Drawable::SceneDeregistration()
{
	assert(currState == RegistrationState::PENDING_DEREGISTRATION);

	SceneAttorney::Deregister(SceneManager::GetCurrentScene(), pMyDeleteRef);

	currState = RegistrationState::CURRENTLY_DEREGISTERED;
}
