#include "AlarmRegistrationCommand.h"
#include "AlarmableAttorney.h"
#include "AlarmableManager.h"

AlarmRegistrationCommand::AlarmRegistrationCommand(Alarmable* a)
	:ptrA(a)
{
	time = 0;
	alarmId = AlarmableManager::ALARM_0;
}

void AlarmRegistrationCommand::execute()
{
	AlarmableAttorney::Registration::AlarmRegistration(ptrA, time, alarmId);
}

void AlarmRegistrationCommand::SetTime(float t)
{
	time = t;
}

void AlarmRegistrationCommand::SetID(AlarmableManager::ALARM_ID id)
{
	alarmId = id;
}

