#include "BaseEnemy.h"
#include "ModelManager.h"
#include "ShaderManager.h"
#include "TextureManager.h"
#include "Visualizer.h"
#include "AlarmableManager.h"
#include "PlayerTank.h"
#include <random>
#include "BulletFactory.h"
#include "Wave.h"

BaseEnemy::BaseEnemy(PlayerTank* player, Vect StartingPos, Wave* currWave)
{
	Vect LightColor(1.50f, 1.50f, 1.50f, 1.0f);
	Vect LightPos(1.0f, 1.0f, 1.0f, 1.0f);
	pGOTankBody = new GraphicsObject_TextureLight(ModelManager::Get("tank"), ShaderManager::Get("textureLight"), TextureManager::Get("bodyTex"), LightColor, LightPos);


	TankScale.set(SCALE, 0.5f, 0.5f, 0.5f);
	TankRot.set(IDENTITY);
	TankPos = StartingPos;
	TankWorld = TankScale * TankRot * Matrix(TRANS, TankPos);
	pGOTankBody->SetWorld(TankWorld);

	SetColliderModel(pGOTankBody->getModel(), Collidable::VolumeType::BSPHERE);

	this->UpdateCollisionData(TankWorld);

	pGOTankTurret = new GraphicsObject_TextureLight(ModelManager::Get("tankTurret"), ShaderManager::Get("textureLight"), TextureManager::Get("bodyTex"), LightColor, LightPos);
	
	TankRotAng = 3.5;
	
	TurretScale.set(SCALE, 0.5f, 0.5f, 0.5f);
	TurretRot.set(IDENTITY);
	TurretPos.set(StartingPos.X(), 9, StartingPos.Z());
	TurretWorld = TurretScale * TurretRot * Matrix(TRANS, TurretPos);
	pGOTankTurret->SetWorld(TurretWorld);

	health = 1;
	speed = 0.2f;

	CurrentPlayer = player;

	CurrentWave = currWave;

	SubmitEntry();
}

BaseEnemy::~BaseEnemy()
{
	delete pGOTankBody;
	delete pGOTankTurret;
}

void BaseEnemy::Collision(Bullet* b)
{
	switch (b->WhoShot())
	{
	case Bullet::ENEMY:
		break;
	case Bullet::PLAYER:
		DebugMsg::out("Enemy Collided\n");

		BsphereToggle = true;
		CurrentWave->BaseDeath(this);
		break;
	default:
		break;
	}
}

void BaseEnemy::UpdateDirection()
{
	TurretRot *= Matrix(ROT_Y, TankRotAng);
}

void BaseEnemy::ShootAtPlayer()
{
	float spawnDistace = 60;
	Vect spawnPos = TurretPos + Vect(TankWorld.M8(), TankWorld.M9(), TankWorld.M10()) * spawnDistace;

	BulletFactory::CreateBullet(spawnPos, TurretRot, Bullet::Sender::ENEMY);
}

void BaseEnemy::Update()
{
	TurretWorld = TurretScale * TurretRot * Matrix(TRANS, Vect(TankPos.X(), 9, TankPos.Z()));
	pGOTankTurret->SetWorld(TurretWorld);

	TankWorld = TankScale * TankRot * Matrix(TRANS, TankPos);
	pGOTankBody->SetWorld(TankWorld);

	this->UpdateCollisionData(TankWorld);
}

void BaseEnemy::Draw()
{
	pGOTankBody->Render(SceneManager::GetCurrCamera());
	pGOTankTurret->Render(SceneManager::GetCurrCamera());

	if (BsphereToggle)
	{
		Visualizer::ShowCollisionVolume(this->GetCollisionVolume(), Vect(1.0f, 0.0f, 0.0f, 1.0f));
	}
	else
	{
		Visualizer::ShowCollisionVolume(this->GetCollisionVolume(), Vect(0.0f, 1.0f, 1.0f, 1.0f));
	}
	BsphereToggle = false;
}

void BaseEnemy::SceneEntry()
{
	SubmitDrawRegistration();
	SubmitUpdateRegistration();
	SetCollidableGroup<BaseEnemy>();
	SubmitCollisionRegistration();
	SubmitAlarmRegistration(5, AlarmableManager::ALARM_0);
}

void BaseEnemy::SceneExit()
{
	SubmitDrawDeregistration();
	SubmitUpdateDeregistration();
	SubmitAlarmDeregistration(AlarmableManager::ALARM_0);
	SubmitCollisionDeregistration();
}

void BaseEnemy::Alarm0()
{
	UpdateDirection();
	ShootAtPlayer();

	int rnd = rand() % 6;

	SubmitAlarmRegistration((float)rnd, AlarmableManager::ALARM_0);
}
