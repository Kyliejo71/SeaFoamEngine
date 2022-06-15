#ifndef _Drawable
#define _Drawable

#include "DrawableManager.h"
#include "RegistrationStates.h"

class DrawRegistrationCommand;
class DrawDeregistrationCommand;

class Drawable
{
public:

	friend class DrawableAttorney;

public:

	Drawable();
	Drawable(const Drawable&) = delete;
	Drawable& operator=(const Drawable&) = delete;
	virtual ~Drawable();

	void SubmitDrawRegistration();
	void SubmitDrawDeregistration();


private:
	DrawableManager::StorageListIt pMyDeleteRef;

	RegistrationState currState;
	DrawRegistrationCommand* pRegistrationCmd;
	DrawDeregistrationCommand* pDeregistrationCmd;

	void SceneRegistration();
	void SceneDeregistration();

	virtual void Draw() = 0;
	virtual void Draw2D() = 0;

};

#endif _Drawable

