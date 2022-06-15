#ifndef _StartGame
#define _StartGame

#include "GameObject.h"

class SeaFoamSprite;
class DemoGameSceneOne;

class StartGame : public GameObject
{
public:

	StartGame();
	StartGame(const StartGame&) = default;
	StartGame& operator=(const StartGame&) = default;
	virtual ~StartGame();

	virtual void Collision(Collidable*) {}

private:

	virtual void Update() {}
	virtual void Draw() {}
	virtual void Draw2D();
	virtual void KeyPressed(AZUL_KEY);
	virtual void KeyReleased(AZUL_KEY) { }
	virtual void SceneEntry();
	virtual void SceneExit();

	AZUL_KEY sceneSwitch = AZUL_KEY::KEY_SPACE;

	DemoGameSceneOne* NextScene;

	SeaFoamSprite* start;
	SeaFoamSprite* lilTank;

	bool SceneChanged;

};

#endif _StartGame
