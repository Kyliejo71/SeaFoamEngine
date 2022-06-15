#ifndef _Alarmable
#define _Alarmable

#include "AlarmableManager.h"
#include "RegistrationStates.h"

class AlarmableManager;
class AlarmRegistrationCommand;
class AlarmDeregistrationCommand;

class Alarmable
{
	friend class AlarmableAttorney;
public:

	Alarmable();
	Alarmable(const Alarmable&) = delete;
	Alarmable& operator=(const Alarmable&) = delete;
	virtual ~Alarmable();

	void SubmitAlarmRegistration(float t, AlarmableManager::ALARM_ID id);
	void SubmitAlarmDeregistration(AlarmableManager::ALARM_ID id);

private:

	struct RegistrationData
	{
		AlarmableManager::TimeLineIT pMyDeleteRef;
		RegistrationState currState;
		AlarmRegistrationCommand* pRegistrationCmd;
		AlarmDeregistrationCommand* pDeregistrationCmd;
	};

	RegistrationData RegData[AlarmableManager::ALARM_NUMBER];
	virtual void Alarm0() {};
	virtual void Alarm1() {};
	virtual void Alarm2() {};
	void TriggerAlarm(AlarmableManager::ALARM_ID id);

	void AlarmRegistration(float t, AlarmableManager::ALARM_ID id);
	void AlarmDeregistration(AlarmableManager::ALARM_ID id);
};

#endif _Updatable
