#ifndef _PlayerCamera
#define _PlayerCamera

#include "AzulCore.h"
#include "GameObject.h"

class PlayerTank;

class PlayerCamera : public GameObject
{
public:

	PlayerCamera() = default;
	PlayerCamera(const PlayerCamera&) = default;
	PlayerCamera& operator=(const PlayerCamera&) = default;
	~PlayerCamera();

	PlayerCamera(PlayerTank* pTank);

private:
	Camera* pPlayerCam;
	Vect CamPos;
	Matrix CamRot;
	Vect CamUp;
	Vect CamDir;
	float CamTranSpeed;
	float CamRotSpeed;

	PlayerTank* myTank;

	virtual void Update();
	virtual void Draw() { }
	virtual void Draw2D() {}
	virtual void KeyPressed(AZUL_KEY) { }
	virtual void KeyReleased(AZUL_KEY) { }
	virtual void SceneEntry();
	virtual void SceneExit();
};

#endif _PlayerCamera
