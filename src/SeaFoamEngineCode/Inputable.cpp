#include "Inputable.h"
#include "InputRegistrationCommand.h"
#include "InputDeregistrationCommand.h"
#include "SceneManager.h"
#include "SceneAttorney.h"

Inputable::Inputable()
{
}

Inputable::~Inputable()
{
	RegDataIt it;

	for (it = regData.begin(); it != regData.end(); it++)
	{
		delete it->second->pDeregistrationCmd;
		delete it->second->pRegistrationCmd;
		delete it->second;
	}

}

void Inputable::SubmitKeyRegistration(AZUL_KEY k, EventType e)
{
	if(regData.find(k) == regData.end())
	{
		RegistrationData* a = new RegistrationData();
		a->currState = RegistrationState::CURRENTLY_DEREGISTERED;
		a->pRegistrationCmd = new InputRegistrationCommand(this);
		a->pDeregistrationCmd = new InputDeregistrationCommand(this);
		regData.insert(InsertPair(k, a));
	}

	RegistrationData* currData = regData.at(k);

	assert(currData->currState == RegistrationState::CURRENTLY_DEREGISTERED);

	currData->pRegistrationCmd->SetKey(k);
	currData->pRegistrationCmd->SetEvent(e);

	SceneAttorney::SubmitCommand(currData->pRegistrationCmd, SceneManager::GetCurrentScene());

	currData->currState = RegistrationState::PENDING_REGISTRATION;
}

void Inputable::SubmitKeyDeregistration(AZUL_KEY k, EventType e)
{
	RegistrationData* currData = regData.at(k);

	assert(currData->currState == RegistrationState::CURRENTLY_REGISTERED);

	currData->pDeregistrationCmd->SetKey(k);
	currData->pDeregistrationCmd->SetEvent(e);

	SceneAttorney::SubmitCommand(currData->pDeregistrationCmd, SceneManager::GetCurrentScene());

	currData->currState = RegistrationState::PENDING_DEREGISTRATION;
}

void Inputable::SceneRegistration(AZUL_KEY k, EventType e)
{
	RegistrationData* currData = regData.at(k);

	assert(currData->currState == RegistrationState::PENDING_REGISTRATION);

	SceneAttorney::Register(SceneManager::GetCurrentScene(), this, k, e);

	currData->currState = RegistrationState::CURRENTLY_REGISTERED;
}

void Inputable::SceneDeregistration(AZUL_KEY k, EventType e)
{
	RegistrationData* currData = regData.at(k);

	assert(currData->currState == RegistrationState::PENDING_DEREGISTRATION);

	SceneAttorney::Deregister(SceneManager::GetCurrentScene(), this, k, e);

	currData->currState = RegistrationState::CURRENTLY_DEREGISTERED;
}
