#ifndef _GameObjectRegistrationCommand
#define _GameObjectRegistrationCommand

#include "CommandBase.h"

class GameObject;

class GameObjectRegistrationCommand : public CommandBase
{
public:

	GameObjectRegistrationCommand(GameObject* gm);
	GameObjectRegistrationCommand(const GameObjectRegistrationCommand&) = default;
	GameObjectRegistrationCommand& operator=(const GameObjectRegistrationCommand&) = default;
	virtual ~GameObjectRegistrationCommand() = default;

	virtual void execute();

private:

	GameObject* ptrGm;

};

#endif _GameObjectRegistrationCommand




