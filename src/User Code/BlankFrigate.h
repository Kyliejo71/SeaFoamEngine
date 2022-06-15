#ifndef _BlankFrigate
#define _BlankFrigate

#include "AzulCore.h"
#include "GameObject.h"

class Frigate;
class WorldPlane;

class BlankFrigate : public GameObject
{
public:

	BlankFrigate();
	BlankFrigate(const BlankFrigate&) = default;
	BlankFrigate& operator=(const BlankFrigate&) = default;
	virtual ~BlankFrigate();


	virtual void Collision(Frigate*);

private:

	virtual void Update() {}
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

#endif _BlankFrigate

