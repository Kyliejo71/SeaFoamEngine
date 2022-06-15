#include "PlayerTank.h"
#include "ModelManager.h"
#include "ShaderManager.h"
#include "TextureManager.h"
#include "SceneManager.h"
#include "Bullet.h"
#include "BulletFactory.h"
#include "DemoGameSceneOne.h"
#include "Wave.h"
#include "LifeBar.h"

PlayerTank::PlayerTank()
{
	Vect LightColor(1.50f, 1.50f, 1.50f, 1.0f);
	Vect LightPos(1.0f, 1.0f, 1.0f, 1.0f);
	pGOTankBody = new GraphicsObject_TextureLight(ModelManager::Get("tank"), ShaderManager::Get("textureLight"), TextureManager::Get("bodyTex"), LightColor, LightPos);

	TankScale.set(SCALE, 0.5f, 0.5f, 0.5f);
	TankRot.set(IDENTITY);
	TankPos.set(200, 1, 10);
	TankWorld = TankScale * TankRot * Matrix(TRANS, TankPos);
	pGOTankBody->SetWorld(TankWorld);

	pGOTankTurret = new GraphicsObject_TextureLight(ModelManager::Get("tankTurret"), ShaderManager::Get("textureLight"), TextureManager::Get("bodyTex"), LightColor, LightPos);

	TurretScale.set(SCALE, 0.5f, 0.5f, 0.5f);
	TurretRot.set(IDENTITY);
	TurretPos.set(200, 9, 0);
	TurretWorld = TurretScale * TurretRot * Matrix(TRANS, TurretPos);
	pGOTankTurret->SetWorld(TurretWorld);

	SetColliderModel(pGOTankBody->getModel(), Collidable::VolumeType::BSPHERE);

	SubmitEntry();
	
	HealthBar = new LifeBar();

	health = 3;
}

PlayerTank::~PlayerTank()
{
	delete pGOTankBody;
	delete pGOTankTurret;
	delete HealthBar;

	SubmitExit();
}

const Vect PlayerTank::GetPos() const
{
	return TankPos;
}

const Vect PlayerTank::GetFwd() const
{
	return Vect(TankWorld.M8(), TankWorld.M9(), TankWorld.M10());
}

const Vect PlayerTank::GetUp() const
{
	return Vect(TankWorld.M4(), TankWorld.M5(), TankWorld.M6());
}

Matrix PlayerTank::GetRot()
{
	return TankRot;
}

const int PlayerTank::GetLives() const
{
	return health;
}

void PlayerTank::SetWave(Wave* currWave)
{
	CurrentWave = currWave;
}

void PlayerTank::Collision(FastEnemy*)
{
	health--;
	HealthBar->UpdateHealth();
	CheckHealth();
}

void PlayerTank::Collision(Bullet* b)
{
	switch (b->WhoShot())
	{
	case Bullet::ENEMY:
		DebugMsg::out("HIT PLAYER\n");
		health--;
		HealthBar->UpdateHealth();
		CheckHealth();
		BsphereToggle = true;
		break;
	case Bullet::PLAYER:
		break;
	default:
		break;
	}
}

void PlayerTank::Update()
{
	if (Keyboard::GetKeyState(forward))
	{
		TankPos += Vect(0, 0, 0.5f) * TankRot * TankTransSpeed;
	}
	else if (Keyboard::GetKeyState(back))
	{
		TankPos += Vect(0, 0, 0.5f) * TankRot * -TankTransSpeed;
	}
	else if (Keyboard::GetKeyState(left))
	{
		TankRot *= Matrix(ROT_Y, TankRotAng);
		TurretRot *= Matrix(ROT_Y, TankRotAng);
	}
	else if (Keyboard::GetKeyState(right))
	{
		TankRot *= Matrix(ROT_Y, -TankRotAng);
		TurretRot *= Matrix(ROT_Y, -TankRotAng);
	}
	else if (Keyboard::GetKeyState(rotLeft))
	{
		TurretRot *= Matrix(ROT_Y, TankRotAng);
	}
	else if (Keyboard::GetKeyState(rotRight))
	{
		TurretRot *= Matrix(ROT_Y, -TankRotAng);
	}

	TurretPos =  Vect(TankPos.X(), 9, TankPos.Z());
	TurretWorld = TurretScale * TurretRot * Matrix(TRANS, TurretPos);
	pGOTankTurret->SetWorld(TurretWorld);

	TankWorld = TankScale * TankRot * Matrix(TRANS, TankPos);
	pGOTankBody->SetWorld(TankWorld);

	this->UpdateCollisionData(TankWorld);
}

void PlayerTank::Draw()
{
	pGOTankBody->Render(SceneManager::GetCurrCamera());
	pGOTankTurret->Render(SceneManager::GetCurrCamera());
}

void PlayerTank::KeyPressed(AZUL_KEY)
{
	float spawnDistace = 50;
	Vect spawnPos = Vect(TurretPos.X(), TurretPos.Y() + 2, TurretPos.Z()) + Vect(TurretWorld.M8(), TurretWorld.M9(), TurretWorld.M10()) * spawnDistace;

	BulletFactory::CreateBullet(spawnPos, TurretRot, Bullet::Sender::PLAYER);
}

void PlayerTank::SceneEntry()
{
	SubmitDrawRegistration();
	SubmitUpdateRegistration();
	SetCollidableGroup<PlayerTank>();
	SubmitCollisionRegistration();
	SubmitKeyRegistration(fire, Inputable::EventType::KEY_PRESS);
}

void PlayerTank::SceneExit()
{
	SubmitDrawDeregistration();
	SubmitUpdateDeregistration();
	SubmitCollisionDeregistration();
	SubmitKeyDeregistration(fire, Inputable::EventType::KEY_PRESS);
}

void PlayerTank::CheckHealth()
{
	if(health <= 0)
	{
		CurrentWave->GameOverByDeath();
	}
}
