#include "CameraManager.h"
#include "Camera.h"
#include "SeaFoamEngine.h"

CameraManager::CameraManager()
{
	//Default Cam
	DefaultCamera = new Camera(Camera::Type::PERSPECTIVE_3D);
	camCurrent = DefaultCamera;

	DefaultCamera->setViewport(0, 0, SeaFoamEngine::GetWidth(), SeaFoamEngine::GetHeight());
	DefaultCamera->setPerspective(35.0f, float(SeaFoamEngine::GetWidth()) / float(SeaFoamEngine::GetHeight()), 1.0f, 5000.0f);

	// Orient Camera
	Vect up3DCam(0.0f, 1.0f, 0.0f);
	Vect pos3DCam(50.0f, 50.0f, 150.0f);
	Vect lookAt3DCam(0.0f, 0.0f, 0.0f);
	DefaultCamera->setOrientAndPosition(up3DCam, lookAt3DCam, pos3DCam);
	DefaultCamera->updateCamera();  // Note: if the camera moves/changes, we need to call update again

	//Default 2D Camera
	// 
	Default2DCamera = new Camera(Camera::Type::ORTHOGRAPHIC_2D);

	Default2DCamera->setViewport(0, 0, SeaFoamEngine::GetWidth(), SeaFoamEngine::GetHeight());
	Default2DCamera->setOrthographic(-0.5f * float(SeaFoamEngine::GetWidth()), 0.5f * float(SeaFoamEngine::GetWidth()), -0.5f * float(SeaFoamEngine::GetHeight()), 0.5f * float(SeaFoamEngine::GetHeight()), 1.0f, 1000.0f);

	// Orient Camera
	Vect up2DCam(0.0f, 1.0f, 0.0f);
	Vect pos2DCam(0.0f, 0.0f, 0.0f);
	Vect lookAt2DCam(0.0f, 0.0f, -1.0f);
	Default2DCamera->setOrientAndPosition(up2DCam, lookAt2DCam, pos2DCam);

	Default2DCamera->updateCamera();
}

CameraManager::~CameraManager()
{
	delete DefaultCamera;
	delete Default2DCamera;
}

Camera* CameraManager::GetCurrentCamera()
{
	return camCurrent;
}

void CameraManager::SetCurrentCamera(Camera* newCam)
{
	camCurrent = newCam;
}

Camera* CameraManager::Get2DCamera()
{
	return Default2DCamera;
}
