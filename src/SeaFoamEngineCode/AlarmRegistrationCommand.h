#ifndef _AlarmRegistrationCommand
#define _AlarmRegistrationCommand

#include "CommandBase.h"
#include "AlarmableManager.h"

class Alarmable;

class AlarmRegistrationCommand : public CommandBase
{
public:

	AlarmRegistrationCommand(Alarmable* a);
	AlarmRegistrationCommand(const AlarmRegistrationCommand&) = default;
	AlarmRegistrationCommand& operator=(const AlarmRegistrationCommand&) = default;
	virtual ~AlarmRegistrationCommand() = default;

	virtual void execute();
	void SetTime(float t);
	void SetID(AlarmableManager::ALARM_ID id);

private:

	Alarmable* ptrA;
	AlarmableManager::ALARM_ID alarmId;
	float time;
};

#endif _AlarmRegistrationCommand
