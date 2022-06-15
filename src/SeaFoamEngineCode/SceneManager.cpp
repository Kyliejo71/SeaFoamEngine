#include "SceneManager.h"
#include "Scene.h"
#include "CameraManager.h"
#include "SceneNull.h"
#include "SceneChangeCmd.h"
#include "SceneChangeNullCmd.h"
#include "SceneAttorney.h"

SceneManager* SceneManager::ptrInstance = nullptr;

SceneManager::SceneManager()
{
	ptrCurrentScene = new SceneNull();
	sceneNullCmd = new SceneChangeNullCmd();
	sceneChangeCmd = new SceneChangeCmd();
	sceneCmd = sceneNullCmd;
}

SceneManager::~SceneManager()
{
	delete sceneNullCmd;
	delete sceneChangeCmd;

	ptrCurrentScene->SceneEnd();
	delete ptrCurrentScene;
}

void SceneManager::privDraw()
{
	SceneAttorney::Draw(ptrCurrentScene);
}

void SceneManager::privDelete()
{
	delete ptrInstance;
	ptrInstance = nullptr;
}

Scene* SceneManager::privGetCurrentScene()
{
	return ptrCurrentScene;
}

void SceneManager::privInitStartScene()
{
	ptrCurrentScene->Initialize();
}

void SceneManager::privUpdate()
{
	sceneCmd->execute();
	SceneAttorney::Update(ptrCurrentScene);
}

void SceneManager::privSetCurrCamera(Camera* c)
{
	SceneAttorney::SetCurrCamera(ptrCurrentScene, c);
}

Camera* SceneManager::privGetCurrCamera()
{
	return SceneAttorney::GetCurrCamera(ptrCurrentScene);
}

void SceneManager::privSetNextScene(Scene* s)
{
	sceneChangeCmd->setNewScene(s);
	sceneCmd = sceneChangeCmd;
}

void SceneManager::privChangeScene(Scene* s)
{
	ptrCurrentScene->SceneEnd();
	delete ptrCurrentScene;

	ptrCurrentScene = s;
	ptrCurrentScene->Initialize();

	sceneCmd = sceneNullCmd;
}

Camera* SceneManager::privGet2DCamera()
{
	return SceneAttorney::Get2DCamera(ptrCurrentScene);
}
