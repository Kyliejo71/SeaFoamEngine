#include "TimeManager.h"
#include "FreezeTime.h"

TimeManager* TimeManager::ptrInstance = nullptr;

TimeManager::~TimeManager()
{
}

float TimeManager::privGetTime()
{
	return currentTime;
}

float TimeManager::priveGetFrameTime()
{
	return frameTime;
}

void TimeManager::privDelete()
{
	delete ptrInstance;
	ptrInstance = nullptr;
}

void TimeManager::privUpdateTime(float t)
{
	previousTime = currentTime;

	currentTime = FrzTime.GetTimeInSeconds(t);

	frameTime = currentTime - previousTime;
}
