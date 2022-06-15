#ifndef _CollidableAttorney
#define _CollidableAttorney

#include "Collidable.h"

class CollidableAttorney
{
public:

	CollidableAttorney() = default;
	CollidableAttorney(const CollidableAttorney&) = delete;
	CollidableAttorney& operator=(const CollidableAttorney&) = delete;
	~CollidableAttorney() = default;

	class Registration
	{
		friend class CollisionRegistrationCmd;

		Registration() = default;
		Registration(const Registration&) = delete;
		Registration& operator=(const Registration&) = delete;
		~Registration() = default;

	private:
		static void CollisionRegistration(Collidable* p) { p->SceneRegistration(); }
	};

	class Deregistration
	{
		friend class CollisionDeregistrationCmd;

		Deregistration() = default;
		Deregistration(const Deregistration&) = delete;
		Deregistration& operator=(const Deregistration&) = delete;
		~Deregistration() = default;

	private:
		static void CollisionDeregistration(Collidable* p) { p->SceneDeregistration(); }
	};
};

#endif _CollidableAttorney

