#ifndef _DrawableAttorney
#define _DrawableAttorney

#include "Drawable.h"

class DrawableAttorney
{
public:

	DrawableAttorney() = default;
	DrawableAttorney(const DrawableAttorney&) = delete;
	DrawableAttorney& operator=(const DrawableAttorney&) = delete;
	~DrawableAttorney() = default;

	class GameLoop
	{
		friend class DrawableManager;

		GameLoop() = default;
		GameLoop(const GameLoop&) = delete;
		GameLoop& operator=(const GameLoop&) = delete;
		~GameLoop() = default;

	private:
		static void Draw(Drawable* p) { p->Draw(); }
		static void Draw2D(Drawable* p) { p->Draw2D(); }
	};

	class Registration
	{
		friend class DrawRegistrationCommand;

		Registration() = default;
		Registration(const Registration&) = delete;
		Registration& operator=(const Registration&) = delete;
		~Registration() = default;

	private:
		static void SceneRegistration(Drawable* p) { p->SceneRegistration(); }
	};

	class Deregistration
	{
		friend class DrawDeregistrationCommand;

		Deregistration() = default;
		Deregistration(const Deregistration&) = delete;
		Deregistration& operator=(const Deregistration&) = delete;
		~Deregistration() = default;

	private:
		static void SceneDeregistration(Drawable* p) { p->SceneDeregistration(); }
	};
};

#endif _DrawableAttorney
