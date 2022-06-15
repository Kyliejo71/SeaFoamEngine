#include "GameObject.h"
#include "GameObjectRegistrationCommand.h"
#include "GameObjectDeregistrationCommand.h"
#include "SceneManager.h"
#include "SceneAttorney.h"

GameObject::GameObject()
{
	currState = RegistrationState::CURRENTLY_DEREGISTERED;
	pRegistrationCmd = new GameObjectRegistrationCommand(this);
	pDeregistrationCmd = new GameObjectDeregistrationCommand(this);
}

GameObject::~GameObject()
{
	delete pRegistrationCmd;
	delete pDeregistrationCmd;
}

void GameObject::SubmitEntry()
{
	assert(currState == RegistrationState::CURRENTLY_DEREGISTERED);

	SceneAttorney::SubmitCommand(pRegistrationCmd, SceneManager::GetCurrentScene());

	currState = RegistrationState::PENDING_REGISTRATION;
}

void GameObject::SubmitExit()
{
	assert(currState == RegistrationState::CURRENTLY_REGISTERED);

	SceneAttorney::SubmitCommand(pDeregistrationCmd, SceneManager::GetCurrentScene());

	currState = RegistrationState::PENDING_DEREGISTRATION;
}

void GameObject::ConnectToScene()
{
	assert(currState == RegistrationState::PENDING_REGISTRATION);

	currState = RegistrationState::CURRENTLY_REGISTERED;
	this->SceneEntry();
}

void GameObject::DisconnectFromScene()
{
	assert(currState == RegistrationState::PENDING_DEREGISTRATION);

	currState = RegistrationState::CURRENTLY_DEREGISTERED;
	this->SceneExit();
}
