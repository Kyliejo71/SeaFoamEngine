#ifndef _Frigate
#define _Frigate

#include "AzulCore.h"
#include "GameObject.h"

class BlankFrigate;
class WorldPlane;
class TreeObj;

class Frigate : public GameObject
{
public:

	Frigate();
	Frigate(const Frigate&) = default;
	Frigate& operator=(const Frigate&) = default;
	virtual ~Frigate();


	virtual void Collision(BlankFrigate*);
	virtual void Collision(TreeObj*) {}

private:

	virtual void Update();
	virtual void Draw();
	virtual void Draw2D() {}
	virtual void KeyPressed(AZUL_KEY) { }
	virtual void KeyReleased(AZUL_KEY) { }
	virtual void SceneEntry();
	virtual void SceneExit();

	GraphicsObject_TextureLight* pGObj_SpaceFrigateLight;
	Matrix ShipScale;
	Vect ShipPos;
	Matrix ShipRot;
	const float ShipTransSpeed = 1;
	const float ShipRotAng = .05f;
	bool BsphereToggle = false;
};

#endif _Frigate
