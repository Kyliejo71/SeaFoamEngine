#include "GameObjectRegistrationCommand.h"
#include "GameObject.h"
#include "GameObjectAttorney.h"

GameObjectRegistrationCommand::GameObjectRegistrationCommand(GameObject* gm)
	:ptrGm(gm)
{
}

void GameObjectRegistrationCommand::execute()
{
	GameObjectAttorney::ConnectToScene(ptrGm);
}
