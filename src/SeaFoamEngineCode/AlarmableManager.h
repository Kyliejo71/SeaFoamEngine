#ifndef _AlarmableManager
#define _AlarmableManager

#include <map>

using namespace std;

class Alarmable;

class AlarmableManager
{

public:
	enum ALARM_ID { ALARM_0, ALARM_1, ALARM_2 };
	static const int ALARM_NUMBER = 3;

	using AlarmEvent = std::pair<Alarmable*, ALARM_ID>;
	using TimeLine = multimap <float, AlarmEvent>;
	using TimeLineIT = TimeLine::iterator;

	AlarmableManager() = default;
	AlarmableManager(const AlarmableManager&) = delete;
	AlarmableManager& operator=(const AlarmableManager&) = delete;
	~AlarmableManager();

	void Deregister(const TimeLineIT& ref);
	void ProcessAlarms();
	void Register(Alarmable* al, float t, ALARM_ID id, TimeLineIT& ref);

private:

	TimeLine alarmMap;
	
};

#endif _Updatable

