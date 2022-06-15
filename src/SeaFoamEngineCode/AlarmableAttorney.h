#ifndef _AlarmableAttorney
#define _AlarmableAttorney

#include "Alarmable.h"
#include "AlarmableManager.h"

class AlarmableAttorney
{
public:

	AlarmableAttorney() = default;
	AlarmableAttorney(const AlarmableAttorney&) = delete;
	AlarmableAttorney& operator=(const AlarmableAttorney&) = delete;
	~AlarmableAttorney() = default;

	class GameLoop
	{
		friend class AlarmableManager;

		GameLoop() = default;
		GameLoop(const GameLoop&) = delete;
		GameLoop& operator=(const GameLoop&) = delete;
		~GameLoop() = default;

	private:
		static void TriggerAlarm(Alarmable* p, AlarmableManager::ALARM_ID id) { p->TriggerAlarm(id); }
	};

	class Registration
	{
		friend class AlarmRegistrationCommand;

		Registration() = default;
		Registration(const Registration&) = delete;
		Registration& operator=(const Registration&) = delete;
		~Registration() = default;

	private:
		static void AlarmRegistration(Alarmable* p, float time, AlarmableManager::ALARM_ID id) { p->AlarmRegistration(time, id); }
	};

	class Deregistration
	{
		friend class AlarmDeregistrationCommand;

		Deregistration() = default;
		Deregistration(const Deregistration&) = delete;
		Deregistration& operator=(const Deregistration&) = delete;
		~Deregistration() = default;

	private:
		static void AlarmDeregistration(Alarmable* p, AlarmableManager::ALARM_ID id) { p->AlarmDeregistration(id); }
	};
};

#endif _AlarmableAttorney
