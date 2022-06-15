#ifndef _ExplodingBarrel
#define _ExplodingBarrel

#include "AzulCore.h"
#include "GameObject.h"

class ExplodingBarrel : public GameObject
{
public:

	ExplodingBarrel();
	ExplodingBarrel(const ExplodingBarrel&) = default;
	ExplodingBarrel& operator=(const ExplodingBarrel&) = default;
	virtual ~ExplodingBarrel();

	virtual void Collision(Collidable*);

private:

	virtual void Update() {}
	virtual void Draw();
	virtual void Draw2D() {}
	virtual void KeyPressed(AZUL_KEY) {}
	virtual void KeyReleased(AZUL_KEY) {}
	virtual void SceneEntry();
	virtual void SceneExit();

	void Explode();

	GraphicsObject_TextureLight* pGOBarrel;
	Matrix BarrelScale;
	Vect BarrelPos;
	Matrix BarrelRot;

	GraphicsObject_ColorNoTexture* explosion;
	Matrix ExScale;
	Vect ExPos;
	Matrix ExRot;

	bool BsphereToggle = false;

	bool exploded;
};

#endif _ExplodingBarrel
