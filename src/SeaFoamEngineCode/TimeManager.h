#ifndef _TimeManager
#define _TimeManager

#include "FreezeTime.h"

class TimeManager
{
	friend class TimeManagerAttorney;
private:
	static TimeManager* ptrInstance;

	TimeManager() = default;
	TimeManager(const TimeManager&) = delete;
	TimeManager& operator=(const TimeManager&) = delete;
	~TimeManager();

	static TimeManager& Instance()
	{
		if (!ptrInstance)
			ptrInstance = new TimeManager();
		return *ptrInstance;
	}

	float privGetTime();
	float priveGetFrameTime();

	void privDelete();
	void privUpdateTime(float t);

	static void Delete() { Instance().privDelete(); }
	static void UpdateTime(float t) { Instance().privUpdateTime(t); }

	float currentTime;
	float frameTime;
	float previousTime;

	FreezeTime FrzTime;

public:

	static float GetTime() { return Instance().privGetTime(); };
	static float GetFrameTime() { return Instance().priveGetFrameTime(); }

};

#endif _TimeManager

