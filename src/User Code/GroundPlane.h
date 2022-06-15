#ifndef _GroundPlane
#define _GroundPlane

#include "AzulCore.h"
#include "GameObject.h"

class GroundPlane : public GameObject
{
public:

	GroundPlane() = default;
	GroundPlane(const GroundPlane&) = default;
	GroundPlane& operator=(const GroundPlane&) = default;
	~GroundPlane();

	GroundPlane(Vect pos);

	virtual void Collision(Collidable*) {}

private:

	virtual void Update() {}
	virtual void Draw();
	virtual void Draw2D() {}
	virtual void Alarm0() {}

	virtual void KeyPressed(AZUL_KEY) {}
	virtual void KeyReleased(AZUL_KEY) { }
	virtual void SceneEntry();
	virtual void SceneExit();

	GraphicsObject_TextureFlat* pGObj_Plane;
	Matrix GroundScale;
	Vect GroundPos;
	Matrix GroundRot;
};

#endif _GroundPlane
