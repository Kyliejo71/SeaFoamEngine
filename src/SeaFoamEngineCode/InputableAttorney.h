#ifndef _InputableAttorney
#define _InputableAttorney

#include "Inputable.h"

class InputableAttorney
{
	friend class InputRegistrationCommand;
	friend class InputDeregistrationCommand;
	friend class SingleKeyEventManager;
public:

	InputableAttorney() = default;
	InputableAttorney(const InputableAttorney&) = delete;
	InputableAttorney& operator=(const InputableAttorney&) = delete;
	~InputableAttorney() = default;

	static void KeyPressed(Inputable* in, AZUL_KEY k) { in->KeyPressed(k); }
	static void KeyReleased(Inputable* in, AZUL_KEY k) { in->KeyReleased(k); }
	static void SceneRegistration(Inputable* in, AZUL_KEY k, Inputable::EventType e) { in->SceneRegistration(k, e); }
	static void SceneDeregistration(Inputable* in, AZUL_KEY k, Inputable::EventType e) { in->SceneDeregistration(k, e); }
};

#endif _InputableAttorney
