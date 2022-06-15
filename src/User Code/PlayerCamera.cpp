#include "PlayerCamera.h"
#include "SeaFoamEngine.h"
#include "SceneManager.h"
#include "PlayerTank.h"

PlayerCamera::~PlayerCamera()
{
	delete pPlayerCam;
}

PlayerCamera::PlayerCamera(PlayerTank* pTank)
{
	myTank = pTank;

	CamPos = Vect(200, 500, -50);
	CamRot = Matrix(IDENTITY);
	CamUp = Vect(0, 1, 0);
	CamDir = Vect(0, 0, 1);
	CamTranSpeed = 0.5f;
	CamRotSpeed = .05f;

	pPlayerCam = new Camera(Camera::Type::PERSPECTIVE_3D);
	pPlayerCam->setViewport(0, 0, SeaFoamEngine::GetWidth(), SeaFoamEngine::GetHeight());
	pPlayerCam->setPerspective(35.0f, float(SeaFoamEngine::GetWidth()) / float(SeaFoamEngine::GetHeight()), 1.0f, 5000.0f);

	// Position and Orient Camera
	//      First: we create a rotation matrix pointing (Z) towards the target
	Vect Target(0, 0, 0);
	CamRot.set(ROT_ORIENT, Target - CamPos, CamUp);

	//		Second: we set the camera to its position and pointing toward the target
	CamRot *= Matrix(ROT_Y, 26 * CamRotSpeed);
	CamRot *= Matrix(ROT_AXIS_ANGLE, Vect(1, 0, 0) * CamRot, 0.75f * -CamRotSpeed);
	pPlayerCam->setOrientAndPosition(CamUp * CamRot, CamPos + CamDir * CamRot, CamPos);
	pPlayerCam->updateCamera();

	SceneManager::SetCurrCamera(pPlayerCam);

	SubmitEntry();
}

void PlayerCamera::Update()
{
	Vect newPos = Vect(myTank->GetPos().X(), 20, myTank->GetPos().Z()-35);
	Matrix newRot = myTank->GetRot();

	pPlayerCam->setOrientAndPosition(CamUp * newRot, newPos + CamDir * newRot, newPos);
	pPlayerCam->updateCamera();
}

void PlayerCamera::SceneEntry()
{
	SubmitUpdateRegistration();
}

void PlayerCamera::SceneExit()
{
	SubmitUpdateDeregistration();
}