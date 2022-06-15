#include "AlarmDeregistrationCommand.h"
#include "AlarmableAttorney.h"
#include "AlarmableManager.h"

AlarmDeregistrationCommand::AlarmDeregistrationCommand(Alarmable* a)
	:ptrA(a)
{
	alarmId = AlarmableManager::ALARM_0;
}

void AlarmDeregistrationCommand::execute()
{
	AlarmableAttorney::Deregistration::AlarmDeregistration(ptrA, alarmId);
}

void AlarmDeregistrationCommand::setId(AlarmableManager::ALARM_ID id)
{
	alarmId = id;
}
