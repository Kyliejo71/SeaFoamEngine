#ifndef _CameraManager
#define _CameraManager

#include "AzulCore.h"
#include "SeaFoamEngine.h"

class Camera;

class CameraManager
{
public:
	static CameraManager* ptrInstance;

	CameraManager();
	CameraManager(const CameraManager&) = delete;
	CameraManager& operator=(const CameraManager&) = delete;
	~CameraManager();

	Camera* GetCurrentCamera();
	void SetCurrentCamera(Camera* newCam);
	Camera* Get2DCamera();

private:

	Camera* camCurrent;
	Camera* DefaultCamera;
	Camera* Default2DCamera;

};

#endif _CameraManager
