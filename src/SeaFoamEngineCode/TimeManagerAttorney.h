#ifndef _TimeManagerAttorney
#define _TimeManagerAttorney

#include "TimeManager.h"

class TimeManagerAttorney
{
	friend class SeaFoamEngine;
public:

	TimeManagerAttorney() = default;
	TimeManagerAttorney(const TimeManagerAttorney&) = delete;
	TimeManagerAttorney& operator=(const TimeManagerAttorney&) = delete;
	~TimeManagerAttorney() = default;

private:
	
	static void Delete() { TimeManager::Delete(); }
	static void UpdateTime(float t) { TimeManager::UpdateTime(t); }

};

#endif _TimeManagerAttorney



