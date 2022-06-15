#ifndef _GameObjectDeregistrationCommand
#define _GameObjectDeregistrationCommand

#include "CommandBase.h"

class GameObject;

class GameObjectDeregistrationCommand : public CommandBase
{
public:

	GameObjectDeregistrationCommand(GameObject* dr);
	GameObjectDeregistrationCommand(const GameObjectDeregistrationCommand&) = default;
	GameObjectDeregistrationCommand& operator=(const GameObjectDeregistrationCommand&) = default;
	virtual ~GameObjectDeregistrationCommand() = default;

	virtual void execute();

private:

	GameObject* ptrGm;

};

#endif _GameObjectDeregistrationCommand