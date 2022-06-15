#include "WorldPlane.h"
#include "TextureManager.h"
#include "ModelManager.h"
#include "ShaderManager.h"
#include "SceneManager.h"
#include "Camera.h"
#include "TesterScene.h"
#include "DemoGameSceneOne.h"

WorldPlane::WorldPlane()
{
	pGObj_Plane = new GraphicsObject_TextureFlat(ModelManager::Get("plane"), ShaderManager::Get("textureFlat"), TextureManager::Get("texturePlane"));
	pGObj_Axis = new GraphicsObject_ColorNoTexture(ModelManager::Get("axis"), ShaderManager::Get("noTexture"));

	// Creating matrices for in-world placement
	Matrix world;

	// Axis and Plane
	world = Matrix(IDENTITY);
	pGObj_Axis->SetWorld(world);
	world = Matrix(SCALE, 400, 400, 400);
	pGObj_Plane->SetWorld(world);


	testScene = new DemoGameSceneOne();

	SubmitEntry();
}

WorldPlane::~WorldPlane()
{
	SubmitExit();
	delete pGObj_Plane;
	delete pGObj_Axis;
	delete testScene;
	DebugMsg::out("Plane Deleted\n");
}

void WorldPlane::Draw()
{
	Camera* curCam = SceneManager::GetCurrCamera();

	pGObj_Plane->Render(curCam);
	pGObj_Axis->Render(curCam);
}

void WorldPlane::Alarm0()
{
	DebugMsg::out("boop\n");

	//SubmitAlarmRegistration(100);
}

void WorldPlane::SceneEntry()
{
	SubmitAlarmRegistration(5, AlarmableManager::ALARM_0);

	SubmitDrawRegistration();
}

void WorldPlane::SceneExit()
{
	SubmitAlarmDeregistration(AlarmableManager::ALARM_0);

	SubmitDrawDeregistration();
}
