#ifndef _GodCam
#define _GodCam

#include "AzulCore.h"
#include "GameObject.h"


class GodCam : public GameObject
{
public:

	GodCam();
	GodCam(const GodCam&) = default;
	GodCam& operator=(const GodCam&) = default;
	~GodCam();

private:
	Camera* pGodCam;
	Vect CamPos;
	Matrix CamRot;
	Vect CamUp;
	Vect CamDir;
	float CamTranSpeed;
	float CamRotSpeed;

	virtual void Update();
	virtual void Draw() { }
	virtual void Draw2D() {}
	virtual void KeyPressed(AZUL_KEY) { }
	virtual void KeyReleased(AZUL_KEY) { }
	virtual void SceneEntry();
	virtual void SceneExit();
};

#endif _GodCam
