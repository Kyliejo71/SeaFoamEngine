#ifndef _Inputable
#define _Inputable

#include "AzulCore.h"
#include <list>
#include <map>
#include "RegistrationStates.h"

class InputRegistrationCommand;
class InputDeregistrationCommand;

class Inputable
{
	friend class InputableAttorney;

public:

	using keyCollectionIt = std::list<Inputable*>::iterator;

	Inputable();
	Inputable(const Inputable&) = delete;
	Inputable& operator=(const Inputable&) = delete;
	virtual ~Inputable();

	enum class EventType
	{
		KEY_PRESS,
		KEY_RELEASE
	};

	void SubmitKeyRegistration(AZUL_KEY k, EventType e);
	void SubmitKeyDeregistration(AZUL_KEY k, EventType e);

private:
	struct RegistrationData
	{
		RegistrationState currState;
		InputRegistrationCommand* pRegistrationCmd;
		InputDeregistrationCommand* pDeregistrationCmd;
	};

	using InsertPair = std::pair<AZUL_KEY, RegistrationData*>;
	using RegDataMap = std::map<AZUL_KEY, RegistrationData*>;
	using RegDataIt = RegDataMap::iterator;
	RegDataMap regData;

	virtual void KeyPressed(AZUL_KEY k) =0;
	virtual void KeyReleased(AZUL_KEY k) =0;

	void SceneRegistration(AZUL_KEY k, EventType e);
	void SceneDeregistration(AZUL_KEY k, EventType e);

};

#endif _Inputable

