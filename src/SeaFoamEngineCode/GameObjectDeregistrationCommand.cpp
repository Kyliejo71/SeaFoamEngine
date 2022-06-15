#include "GameObjectDeregistrationCommand.h"
#include "GameObject.h"
#include "GameObjectAttorney.h"

GameObjectDeregistrationCommand::GameObjectDeregistrationCommand(GameObject* gm)
	:ptrGm(gm)
{
}

void GameObjectDeregistrationCommand::execute()
{
	GameObjectAttorney::DisconnectFromScene(ptrGm);
}
