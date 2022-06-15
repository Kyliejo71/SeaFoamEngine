#include "FastEnemy.h"
#include "ModelManager.h"
#include "ShaderManager.h"
#include "TextureManager.h"
#include "PlayerTank.h"
#include "Visualizer.h"
#include "Wave.h"

FastEnemy::FastEnemy(PlayerTank* player, Vect StartingPos, Wave* currWave)
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

	TurretScale.set(SCALE, 0.5f, 0.5f, 0.5f);
	TurretRot.set(IDENTITY);
	TurretPos.set(StartingPos.X(), 9, StartingPos.Z());
	TurretWorld = TurretScale * TurretRot * Matrix(TRANS, TurretPos);
	pGOTankTurret->SetWorld(TurretWorld);

	speed = 0.4f;

	CurrentPlayer = player;

	CurrentWave = currWave;

	SubmitEntry();
}

FastEnemy::~FastEnemy()
{
	delete pGOTankBody;
	delete pGOTankTurret;
}

void FastEnemy::Collision(PlayerTank*)
{
	BsphereToggle = true;
	CurrentWave->FastDeath(this);
}

void FastEnemy::Collision(Bullet*)
{
	BsphereToggle = true;
	CurrentWave->FastDeath(this);
}

void FastEnemy::Update()
{
	Vect newPos = TankPos + (CurrentPlayer->GetPos() - TankPos).norm() * speed;
	TankPos = newPos;

	Vect fwd = CurrentPlayer->GetFwd();
	Vect up = CurrentPlayer->GetUp();

	TankRot = Matrix(ROT_ORIENT, fwd * -1, up);
	TurretRot = Matrix(ROT_ORIENT, fwd * -1, up);

	TurretWorld = TurretScale * TurretRot * Matrix(TRANS, Vect(TankPos.X(), 9, TankPos.Z()));
	pGOTankTurret->SetWorld(TurretWorld);

	TankWorld = TankScale * TankRot * Matrix(TRANS, TankPos);
	pGOTankBody->SetWorld(TankWorld);

	this->UpdateCollisionData(TankWorld);
}

void FastEnemy::Draw()
{
	pGOTankBody->Render(SceneManager::GetCurrCamera());
	pGOTankTurret->Render(SceneManager::GetCurrCamera());

	if (BsphereToggle)
	{
		Visualizer::ShowCollisionVolume(this->GetCollisionVolume(), Vect(1.0f, 0.0f, 0.0f, 1.0f));
	}
	else
	{
		Visualizer::ShowCollisionVolume(this->GetCollisionVolume(), Vect(1.0f, 1.0f, 1.0f, 1.0f));
	}
	BsphereToggle = false;
}

void FastEnemy::SceneEntry()
{
	SubmitDrawRegistration();
	SubmitUpdateRegistration();
	SetCollidableGroup<FastEnemy>();
	SubmitCollisionRegistration();
}

void FastEnemy::SceneExit()
{
	SubmitDrawDeregistration();
	SubmitUpdateDeregistration();
	SubmitCollisionDeregistration();
}

const Vect FastEnemy::GetFwd() const
{
	return Vect(TankWorld.M8(), TankWorld.M9(), TankWorld.M10());
}
