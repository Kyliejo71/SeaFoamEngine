#ifndef _GameObject
#define _GameObject

#include "AzulCore.h"
#include "Updatable.h"
#include "Drawable.h"
#include "Alarmable.h"
#include "Inputable.h"
#include "Collidable.h"
#include "GameObjectRegistrationCommand.h"
#include "GameObjectDeregistrationCommand.h"
#include "RegistrationStates.h"

class GameObject : public Updatable, public Drawable, public Alarmable, public Inputable, public Collidable
{
	friend class GameObjectAttorney;
public:

	GameObject();
	GameObject(const GameObject&) = default;
	GameObject& operator=(const GameObject&) = default;
	virtual ~GameObject();

	void SubmitEntry();
	void SubmitExit();

private:

	void ConnectToScene();
	void DisconnectFromScene();
	virtual void SceneEntry() {}
	virtual void SceneExit() {}

	RegistrationState currState;
	GameObjectRegistrationCommand *pRegistrationCmd;
	GameObjectDeregistrationCommand *pDeregistrationCmd;
};

#endif _GameObject
