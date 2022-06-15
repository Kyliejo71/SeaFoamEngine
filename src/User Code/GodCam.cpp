#include "GodCam.h"
#include "SeaFoamEngine.h"
#include "SceneManager.h"

GodCam::GodCam()
{
	CamPos = Vect(50, 50, 100.0f);
	CamRot = Matrix(IDENTITY);
	CamUp = Vect(0, 1, 0);
	CamDir = Vect(0, 0, 1);
	CamTranSpeed = 2;
	CamRotSpeed = .02f;

	pGodCam = new Camera(Camera::Type::PERSPECTIVE_3D);
	pGodCam->setViewport(0, 0, SeaFoamEngine::GetWidth(), SeaFoamEngine::GetHeight());
	pGodCam->setPerspective(35.0f, float(SeaFoamEngine::GetWidth()) / float(SeaFoamEngine::GetHeight()), 1.0f, 5000.0f);

	// Position and Orient Camera
	//      First: we create a rotation matrix pointing (Z) towards the target
	Vect Target(0, 0, 0);
	CamRot.set(ROT_ORIENT, Target - CamPos, CamUp);

	//		Second: we set the camera to its position and pointing toward the target
	pGodCam->setOrientAndPosition(CamUp * CamRot, CamPos + CamDir * CamRot, CamPos);
	pGodCam->updateCamera();

	SceneManager::SetCurrCamera(pGodCam);

	SubmitEntry();
}

GodCam::~GodCam()
{
	SubmitExit();
	delete pGodCam;
}

void GodCam::Update()
{
	if (Keyboard::GetKeyState(AZUL_KEY::KEY_T))
	{
		CamPos += Vect(0, 0, 1) * CamRot * CamTranSpeed;
	}
	else if (Keyboard::GetKeyState(AZUL_KEY::KEY_G))
	{
		CamPos += Vect(0, 0, 1) * CamRot * -CamTranSpeed;
	}

	if (Keyboard::GetKeyState(AZUL_KEY::KEY_F))
	{
		CamPos += Vect(1, 0, 0) * CamRot * CamTranSpeed;
	}
	else if (Keyboard::GetKeyState(AZUL_KEY::KEY_H))
	{
		CamPos += Vect(1, 0, 0) * CamRot * -CamTranSpeed;
	}

	// Camera Rotation movement (NOTE: This time, I'm NOT using time-based values for simplicity)
	if (Keyboard::GetKeyState(AZUL_KEY::KEY_ARROW_LEFT))
	{
		CamRot *= Matrix(ROT_Y, CamRotSpeed);
	}
	else if (Keyboard::GetKeyState(AZUL_KEY::KEY_ARROW_RIGHT))
	{
		CamRot *= Matrix(ROT_Y, -CamRotSpeed);
	}

	if (Keyboard::GetKeyState(AZUL_KEY::KEY_ARROW_UP))
	{
		CamRot *= Matrix(ROT_AXIS_ANGLE, Vect(1, 0, 0) * CamRot, -CamRotSpeed);
	}
	else if (Keyboard::GetKeyState(AZUL_KEY::KEY_ARROW_DOWN))
	{
		CamRot *= Matrix(ROT_AXIS_ANGLE, Vect(1, 0, 0) * CamRot, CamRotSpeed);
	}

	// Update the camera settings
	pGodCam->setOrientAndPosition(CamUp * CamRot, CamPos + CamDir * CamRot, CamPos);
	pGodCam->updateCamera();

}

void GodCam::SceneEntry()
{
	SubmitUpdateRegistration();
}

void GodCam::SceneExit()
{
	SubmitUpdateDeregistration();
}
