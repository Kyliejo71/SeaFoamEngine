#ifndef _GameObjectAttorney
#define _GameObjectAttorney

#include "GameObject.h"

class GameObjectAttorney
{
	friend class GameObjectRegistrationCommand;
	friend class GameObjectDeregistrationCommand;
public:

	GameObjectAttorney() = default;
	GameObjectAttorney(const GameObjectAttorney&) = delete;
	GameObjectAttorney& operator=(const GameObjectAttorney&) = delete;
	~GameObjectAttorney() = default;

	static void ConnectToScene(GameObject* gm) { gm->ConnectToScene(); }
	static void DisconnectFromScene(GameObject* gm) { gm->DisconnectFromScene(); }
	
};

#endif _GameObjectAttorney
