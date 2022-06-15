#ifndef _WorldPlane
#define _WorldPlane

#include "AzulCore.h"
#include "GameObject.h"

class Frigate;
class Scene;

class WorldPlane : public GameObject
{
public:

	WorldPlane();
	WorldPlane(const WorldPlane&) = default;
	WorldPlane& operator=(const WorldPlane&) = default;
	~WorldPlane();

	void Collision(Collidable*) {}

private:

	virtual void Update() {}
	virtual void Draw();
	virtual void Draw2D() {}
	virtual void Alarm0();

	virtual void KeyPressed(AZUL_KEY ) {}
	virtual void KeyReleased(AZUL_KEY) { }
	virtual void SceneEntry();
	virtual void SceneExit();

	GraphicsObject_TextureFlat* pGObj_Plane;
	GraphicsObject_ColorNoTexture* pGObj_Axis;


	Scene* testScene;

};

#endif _WorldPlane