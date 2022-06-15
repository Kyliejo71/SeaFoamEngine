#ifndef _SceneAttorney
#define _SceneAttorney

#include "Scene.h"
#include "CollisionGroup.h"

class CollisionManager;

class SceneAttorney
{
	friend class SceneManager;
	friend class Updatable;
	friend class Drawable;
	friend class Alarmable;
	friend class Inputable;
	friend class GameObject;
	friend class Collidable;
	friend class Visualizer;
public:

	SceneAttorney() = default;
	SceneAttorney(const SceneAttorney&) = delete;
	SceneAttorney& operator=(const SceneAttorney&) = delete;
	~SceneAttorney() = default;

private:

	static void SubmitCommand(CommandBase* cmd, Scene* scene) { scene->SubmitCommand(cmd); }

	static void Register(Scene* scene, Updatable* up, UpdatableManager::StorageListIt& ref) { scene->Register(up, ref); }
	static void Deregister(Scene* scene, UpdatableManager::StorageListIt& ref) { scene->Deregister(ref); }
	static void Register(Scene* scene, Drawable* dr, DrawableManager::StorageListIt& ref) { scene->Register(dr, ref); }
	static void Deregister(Scene* scene, DrawableManager::StorageListIt& ref) { scene->Deregister(ref); }
	static void Register(Scene* scene, Alarmable* al, float t, AlarmableManager::ALARM_ID id, AlarmableManager::TimeLineIT& ref) { scene->Register(al, t, id, ref); }
	static void Deregister(Scene* scene, AlarmableManager::TimeLineIT& ref) { scene->Deregister(ref); }
	static void Register(Scene* scene, Inputable* in, AZUL_KEY k, Inputable::EventType e) { scene->Register(in, k, e); }
	static void Deregister(Scene* scene, Inputable* in, AZUL_KEY k, Inputable::EventType e) { scene->Deregister(in, k, e); }
	static void Register(Scene* scene, Collidable* co, CollisionGroup::CollidableCollectionRef& ref, int id) { scene->GetCollisionMgr().GetColGroup(id)->Register(co, ref); }
	static void Deregister(Scene* scene, CollisionGroup::CollidableCollectionRef& ref, int id) { scene->GetCollisionMgr().GetColGroup(id)->Deregister(ref); }

	static void Update(Scene* scene) { scene->Update(); }
	static void Draw(Scene* scene) { scene->Draw(); }
	static void SetCurrCamera(Scene* scene, Camera* cam) { scene->SetCurrCamera(cam); }
	static Camera* GetCurrCamera(Scene* scene) { return scene->GetCurrCamera(); }
	static Camera* Get2DCamera(Scene* scene) { return scene->Get2DCamera(); }

	static CollisionManager& GetCollisionMgr(Scene* scene) { return scene->GetCollisionMgr(); }

	static void AddVisualizerCmd(Scene* scene, VisualizerCmd* cmd) { scene->AddVisualizerCmd(cmd); }

};

#endif _SceneAttorney



