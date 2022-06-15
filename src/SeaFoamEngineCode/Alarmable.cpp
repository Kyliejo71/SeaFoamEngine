#include "Alarmable.h"
#include "SceneManager.h"
#include "AlarmDeregistrationCommand.h"
#include "AlarmRegistrationCommand.h"
#include "DebugOut.h"
#include "SceneAttorney.h"

Alarmable::Alarmable()
{
	RegData[0].currState = RegistrationState::CURRENTLY_DEREGISTERED;
	RegData[0].pDeregistrationCmd = new AlarmDeregistrationCommand(this);
	RegData[0].pRegistrationCmd = new AlarmRegistrationCommand(this);
	RegData[1].currState = RegistrationState::CURRENTLY_DEREGISTERED;
	RegData[1].pDeregistrationCmd = new AlarmDeregistrationCommand(this);
	RegData[1].pRegistrationCmd = new AlarmRegistrationCommand(this);
	RegData[2].currState = RegistrationState::CURRENTLY_DEREGISTERED;
	RegData[2].pDeregistrationCmd = new AlarmDeregistrationCommand(this);
	RegData[2].pRegistrationCmd = new AlarmRegistrationCommand(this);
}

Alarmable::~Alarmable()
{
	delete RegData[0].pDeregistrationCmd;
	delete RegData[1].pDeregistrationCmd;
	delete RegData[2].pDeregistrationCmd;
	delete RegData[0].pRegistrationCmd;
	delete RegData[1].pRegistrationCmd;
	delete RegData[2].pRegistrationCmd;
}

void Alarmable::SubmitAlarmRegistration(float t, AlarmableManager::ALARM_ID id)
{
	DebugMsg::out("submit\n");
	assert(RegData[id].currState == RegistrationState::CURRENTLY_DEREGISTERED);

	RegData[id].pRegistrationCmd->SetTime(t);
	RegData[id].pRegistrationCmd->SetID(id);

	SceneAttorney::SubmitCommand(RegData[id].pRegistrationCmd, SceneManager::GetCurrentScene());

	RegData[id].currState = RegistrationState::PENDING_REGISTRATION;
}

void Alarmable::SubmitAlarmDeregistration(AlarmableManager::ALARM_ID id)
{
	DebugMsg::out("submit de\n");
	if (RegData[id].currState != RegistrationState::CURRENTLY_DEREGISTERED)
	{
		assert(RegData[id].currState == RegistrationState::CURRENTLY_REGISTERED);

		RegData[id].pDeregistrationCmd->setId(id);

		SceneAttorney::SubmitCommand(RegData[id].pDeregistrationCmd, SceneManager::GetCurrentScene());

		RegData[id].currState = RegistrationState::PENDING_DEREGISTRATION;
	}
}

void Alarmable::TriggerAlarm(AlarmableManager::ALARM_ID id)
{
	RegData[id].currState = RegistrationState::CURRENTLY_DEREGISTERED;

	switch (id)
	{
	case AlarmableManager::ALARM_0:
		this->Alarm0();
		break;
	case AlarmableManager::ALARM_1:
		this->Alarm1();
		break;
	case AlarmableManager::ALARM_2:
		this->Alarm2();
		break;
	};
}

void Alarmable::AlarmRegistration(float t, AlarmableManager::ALARM_ID id)
{
	DebugMsg::out("reg\n");
	assert(RegData[id].currState == RegistrationState::PENDING_REGISTRATION);

	SceneAttorney::Register(SceneManager::GetCurrentScene(), this, t, id, (RegData[id].pMyDeleteRef));

	RegData[id].currState = RegistrationState::CURRENTLY_REGISTERED;
}

void Alarmable::AlarmDeregistration(AlarmableManager::ALARM_ID id)
{
	DebugMsg::out("de reg\n");
	assert(RegData[id].currState == RegistrationState::PENDING_DEREGISTRATION);

	SceneAttorney::Deregister(SceneManager::GetCurrentScene(), RegData[id].pMyDeleteRef);

	RegData[id].currState = RegistrationState::CURRENTLY_DEREGISTERED;
}
