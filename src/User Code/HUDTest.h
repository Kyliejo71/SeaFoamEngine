#ifndef _HUDTest
#define _HUDTest

#include "GameObject.h"

class SeaFoamSprite;

class HUDTest : public GameObject
{
public:

	HUDTest();
	HUDTest(const HUDTest&) = default;
	HUDTest& operator=(const HUDTest&) = default;
	virtual ~HUDTest();

	virtual void Collision(Collidable*) {}

private:

	virtual void Update() {}
	virtual void Draw(){}
	virtual void Draw2D();
	virtual void KeyPressed(AZUL_KEY) { }
	virtual void KeyReleased(AZUL_KEY) { }
	virtual void SceneEntry();
	virtual void SceneExit();


	SeaFoamSprite* stitch;
	
};

#endif _HUDTest

