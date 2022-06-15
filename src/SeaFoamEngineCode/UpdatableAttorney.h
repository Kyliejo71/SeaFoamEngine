#ifndef _UpdatableAttorney
#define _UpdatableAttorney

#include "Updatable.h"

class UpdatableAttorney
{
public:

	UpdatableAttorney() = default;
	UpdatableAttorney(const UpdatableAttorney&) = delete;
	UpdatableAttorney& operator=(const UpdatableAttorney&) = delete;
	~UpdatableAttorney() = default;
	
	class GameLoop
	{
		friend class UpdatableManager;

		GameLoop() = default;
		GameLoop(const GameLoop&) = delete;
		GameLoop& operator=(const GameLoop&) = delete;
		~GameLoop() = default;

	private:
		static void Update(Updatable* p) { p->Update(); }
	};

	class Registration
	{
		friend class UpdateRegistrationCommand;

		Registration() = default;
		Registration(const Registration&) = delete;
		Registration& operator=(const Registration&) = delete;
		~Registration() = default;

	private:
		static void SceneRegistration(Updatable* p) { p->SceneRegistration(); }
	};

	class Deregistration
	{
		friend class UpdateDeregistrationCommand;

		Deregistration() = default;
		Deregistration(const Deregistration&) = delete;
		Deregistration& operator=(const Deregistration&) = delete;
		~Deregistration() = default;

	private:
		static void SceneDeregistration(Updatable* p) { p->SceneDeregistration(); }
	};
};

#endif _UpdatableAttorney