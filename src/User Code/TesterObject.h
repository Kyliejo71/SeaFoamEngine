#ifndef _TesterObject
#define _TesterObject

#include "AzulCore.h"
#include "GameObject.h"

class KeyStateTest;

class TesterObject : public GameObject
{
public:

	TesterObject();
	TesterObject(const TesterObject&) = default;
	TesterObject& operator=(const TesterObject&) = default;
	~TesterObject() = default;

private:

	virtual void Update();
	virtual void Draw() {};
	virtual void KeyPressed(AZUL_KEY k) { k = k; }
	virtual void KeyReleased(AZUL_KEY k) { k = k; }

	KeyStateTest* myKeyTest;

};

#endif _TesterObject

