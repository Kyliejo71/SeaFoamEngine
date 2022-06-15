#ifndef _SceneManager
#define _SceneManager

#include "Scene.h"

class SceneChangeCmdBase;
class SceneChangeNullCmd;
class SceneChangeCmd;

class SceneManager
{
	friend class SceneManagerAttorney;
private:
	static SceneManager* ptrInstance;

	SceneManager();
	SceneManager(const SceneManager&) = delete;
	SceneManager& operator=(const SceneManager&) = delete;
	~SceneManager();

	static SceneManager& Instance()
	{
		if (!ptrInstance)
			ptrInstance = new SceneManager();
		return *ptrInstance;
	}

	Scene* ptrCurrentScene;
	SceneChangeCmdBase* sceneCmd;
	SceneChangeNullCmd* sceneNullCmd;
	SceneChangeCmd* sceneChangeCmd;

	void privDraw();
	void privDelete();
	Scene* privGetCurrentScene();
	void privInitStartScene();
	void privUpdate();
	void privSetCurrCamera(Camera* c);
	Camera* privGetCurrCamera();
	void privSetNextScene(Scene* s);
	void privChangeScene(Scene* s);
	Camera* privGet2DCamera();

	static void Draw() { Instance().privDraw(); }
	static void Delete() { Instance().privDelete(); }
	static void InitStartScene() { Instance().privInitStartScene(); }
	static void Update() {Instance().privUpdate(); }
	static void ChangeScene(Scene* s) { Instance().privChangeScene(s); }

public:

	static Scene* GetCurrentScene() { return Instance().privGetCurrentScene(); }
	static void SetCurrCamera(Camera* c) { Instance().privSetCurrCamera(c); }
	static Camera* GetCurrCamera() { return Instance().privGetCurrCamera(); }
	static void SetNextScene(Scene* s) { Instance().privSetNextScene(s); }
	static Camera* Get2DCamera() { return Instance().privGet2DCamera(); }
};

#endif _SceneManager

