#ifndef _SceneManagerAttorney
#define _SceneManagerAttorney

#include "SceneManager.h"

class SceneManagerAttorney
{
	friend class SeaFoamEngine;
	friend class SceneChangeCmd;
public:

	SceneManagerAttorney() = default;
	SceneManagerAttorney(const SceneManagerAttorney&) = delete;
	SceneManagerAttorney& operator=(const SceneManagerAttorney&) = delete;
	~SceneManagerAttorney() = default;

private:
	static void Draw() { SceneManager::Draw(); }
	static void Delete() { SceneManager::Delete(); }
	static void InitStartScene() { SceneManager::InitStartScene(); }
	static void Update() { SceneManager::Update(); }
	static void ChangeScene(Scene* s) { SceneManager::ChangeScene(s); }
};

#endif _SceneManagerAttorney


