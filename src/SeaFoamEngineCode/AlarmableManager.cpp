#include "AzulCore.h"
#include "AlarmableManager.h"
#include "AlarmableAttorney.h"
#include "TimeManager.h"

AlarmableManager::~AlarmableManager()
{
}

void AlarmableManager::Deregister(const TimeLineIT& ref)
{
	if(alarmMap.size() > 0 && alarmMap.find(ref->first) != alarmMap.end())
		alarmMap.erase(ref);
}

void AlarmableManager::ProcessAlarms()
{
	bool deleteIt = false;
	Alarmable* al;
	TimeLineIT it;
	float currTime = TimeManager::GetTime();


	for(it = alarmMap.begin(); (it != alarmMap.end()) && (it->first <= currTime); it++)
	{
		al = it->second.first;
		AlarmableAttorney::GameLoop::TriggerAlarm(al, it->second.second);
		deleteIt = true;
	}
	if (deleteIt)
	{
		alarmMap.erase(alarmMap.begin(), it);
	}
}

void AlarmableManager::Register(Alarmable* al, float t, ALARM_ID id, TimeLineIT& ref)
{
	float newTime = TimeManager::GetTime() + t;
	AlarmEvent ae = { al, id };
	ref = alarmMap.insert({ newTime, ae });
}
 