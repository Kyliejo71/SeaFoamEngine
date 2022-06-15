#ifndef _Scene
#define _Scene

#include "UpdatableManager.h"
#include "DrawableManager.h"
#include "SceneRegistrationBroker.h"
#include "AlarmableManager.h"
#include "AlarmableAttorney.h"
#include "Inputable.h"
#include "KeyBoardEventManager.h"
#include "CameraManager.h"
#include "AzulCore.h"
#include "CollisionManager.h"
#include "VisualizerManager.h"

class CommandBase;
class VisualizerCmd;

class Scene
{
	friend class SceneAttorney;

public:

	Scene() = default;
	Scene(const Scene&) = default;
	Scene& operator=(const Scene&) = default;
	virtual ~Scene();

	virtual void Initialize() = 0;
	virtual void SceneEnd() = 0;

private:

	UpdatableManager UpdateMgr;
	DrawableManager DrawableMgr; 
	AlarmableManager AlarmableMgr;
	SceneRegistrationBroker Registrationbrkr;
	KeyBoardEventManager KBEventMgr;
	CameraManager CameraMgr;
	CollisionManager CollisionMgr;
	VisualizerManger VisualizerMgr;

	void Update();
	void Draw();

	void Register(Updatable* up, UpdatableManager::StorageListIt &ref);
	void Register(Drawable* dr, DrawableManager::StorageListIt &ref);
	void Register(Alarmable* al, float t, AlarmableManager::ALARM_ID id, AlarmableManager::TimeLineIT &ref);
	void Register(Inputable* in, AZUL_KEY k, Inputable::EventType e);

	void Deregister(UpdatableManager::StorageListIt& ref);
	void Deregister(DrawableManager::StorageListIt &ref);
	void Deregister(AlarmableManager::TimeLineIT &ref);
	void Deregister(Inputable* in, AZUL_KEY k, Inputable::EventType e);

	void AddVisualizerCmd(VisualizerCmd* cmd);

	Camera* GetCurrCamera();
	Camera* Get2DCamera();
	void SetCurrCamera(Camera* c);
	CollisionManager& GetCollisionMgr();

	void SubmitCommand(CommandBase* cmd);

protected:
	template<typename c1, typename c2>
	void SetCollisionPair()
	{
		CollisionMgr.SetCollisionPair<c1, c2>();
	}
};

#endif _Scene


