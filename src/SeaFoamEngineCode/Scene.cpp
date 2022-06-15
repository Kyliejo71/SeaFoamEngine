#include "Scene.h"
#include "Updatable.h"
#include "Drawable.h"
#include "Alarmable.h"

Scene::~Scene()
{

}

void Scene::Update()
{

	Registrationbrkr.ExecuteCommands();

	AlarmableMgr.ProcessAlarms(); 

	KBEventMgr.ProcessKeyEvent();

	UpdateMgr.ProcessElements();

	CollisionMgr.UpdateCollisionGroups();

	CollisionMgr.ProcessCollisions();

}

void Scene::Draw()
{
	VisualizerMgr.ExecuteCommands();

	DrawableMgr.ProcessElements();
}

void Scene::Register(Updatable* up, UpdatableManager::StorageListIt& ref)
{
	UpdateMgr.Register(up, ref);
}

void Scene::Register(Drawable* up, DrawableManager::StorageListIt& ref)
{
	DrawableMgr.Register(up, ref);
}

void Scene::Register(Alarmable* al, float t, AlarmableManager::ALARM_ID id, AlarmableManager::TimeLineIT& ref)
{
	AlarmableMgr.Register(al, t, id, ref);
}

void Scene::Register(Inputable* in, AZUL_KEY k, Inputable::EventType e)
{
	KBEventMgr.Register(in, k, e);
}

void Scene::Deregister(UpdatableManager::StorageListIt& ref)
{
	UpdateMgr.Deregister(ref);
}

void Scene::Deregister(DrawableManager::StorageListIt& ref)
{
	DrawableMgr.Deregister(ref);
}

void Scene::Deregister(AlarmableManager::TimeLineIT& ref)
{
	AlarmableMgr.Deregister(ref);
}

void Scene::Deregister(Inputable* in, AZUL_KEY k, Inputable::EventType e)
{
	KBEventMgr.Deregister(in, k, e);
}

void Scene::AddVisualizerCmd(VisualizerCmd* cmd)
{
	VisualizerMgr.AddCommand(cmd);
}

Camera* Scene::GetCurrCamera()
{
	return CameraMgr.GetCurrentCamera();
}

Camera* Scene::Get2DCamera()
{
	return CameraMgr.Get2DCamera();
}

void Scene::SetCurrCamera(Camera* c)
{
	CameraMgr.SetCurrentCamera(c);
}

CollisionManager& Scene::GetCollisionMgr()
{
	return CollisionMgr;
}

void Scene::SubmitCommand(CommandBase* cmd)
{
	Registrationbrkr.AddCommand(cmd);
}
