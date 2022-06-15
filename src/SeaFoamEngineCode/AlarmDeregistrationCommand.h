#ifndef _AlarmDeregistrationCommand
#define _AlarmDeregistrationCommand

#include "CommandBase.h"
#include "AlarmableManager.h"

class Alarmable;
class AlarmableManager;

class AlarmDeregistrationCommand : public CommandBase
{
public:

	AlarmDeregistrationCommand(Alarmable* a);
	AlarmDeregistrationCommand(const AlarmDeregistrationCommand&) = default;
	AlarmDeregistrationCommand& operator=(const AlarmDeregistrationCommand&) = default;
	virtual ~AlarmDeregistrationCommand() = default;

	virtual void execute();
	void setId(AlarmableManager::ALARM_ID id);

private:

	Alarmable* ptrA;
	AlarmableManager::ALARM_ID alarmId;
};

#endif _AlarmDeregistrationCommand


