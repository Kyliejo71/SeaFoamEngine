#ifndef _TreeObj
#define _TreeObj

#include "AzulCore.h"
#include "GameObject.h"

class Frigate;

class TreeObj : public GameObject
{
public:

	TreeObj();
	TreeObj(const TreeObj&) = default;
	TreeObj& operator=(const TreeObj&) = default;
	~TreeObj();


	void Collision(Frigate*);

private:

	virtual void Update(){}
	virtual void Draw();
	virtual void Draw2D() {}
	virtual void KeyPressed(AZUL_KEY) { }
	virtual void KeyReleased(AZUL_KEY) { }
	virtual void SceneEntry();
	virtual void SceneExit();

	GraphicsObject_TextureLight* pGObj_TreeLight;
	Matrix TreeScale;
	Vect TreePos;
	Matrix TreeRot;

	bool bSphereToggle;
};

#endif _TreeObj

