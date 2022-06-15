#ifndef _LifeBar
#define _LifeBar

#include "GameObject.h"

class SeaFoamSprite;

class LifeBar : public GameObject
{
public:

	LifeBar();
	LifeBar(const LifeBar&) = default;
	LifeBar& operator=(const LifeBar&) = default;
	virtual ~LifeBar();

	virtual void Collision(Collidable*) {}

	void UpdateHealth();

private:

	virtual void Update() {}
	virtual void Draw() {}
	virtual void Draw2D();
	virtual void KeyPressed(AZUL_KEY){}
	virtual void KeyReleased(AZUL_KEY) { }
	virtual void SceneEntry();
	virtual void SceneExit();

	SeaFoamSprite* Heart1;
	SeaFoamSprite* Heart2;
	SeaFoamSprite* Heart3;

	int TotalLives = 3;

};

#endif _LifeBar
