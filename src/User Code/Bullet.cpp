#include "Bullet.h"
#include "ModelManager.h"
#include "ShaderManager.h"
#include "TextureManager.h"
#include "SceneManager.h"
#include "BulletFactory.h"
#include "AlarmableManager.h"
#include "Visualizer.h"
#include "BaseEnemy.h"

Bullet::Bullet()
{
	Vect LightColor(1.50f, 1.50f, 1.50f, 1.0f);
	Vect LightPos(1.0f, 1.0f, 1.0f, 1.0f);
	pGOBullet = new GraphicsObject_TextureLight(ModelManager::Get("bullet"), ShaderManager::Get("textureLight"), TextureManager::Get("bulletTex"), LightColor, LightPos);
	BulletScale.set(SCALE, 0.05f, 0.05f, 0.05f);
}

Bullet::~Bullet()
{
	delete pGOBullet;
}

void Bullet::Initialize(Vect pos, Matrix rot, Sender x)
{
	Matrix world;

	whoShot = x;

	BulletRot = rot;
	BulletPos.set(pos);
	world = BulletScale * BulletRot * Matrix(TRANS, BulletPos);
	pGOBullet->SetWorld(world);

	SetColliderModel(pGOBullet->getModel(), Collidable::VolumeType::BSPHERE);

	this->UpdateCollisionData(world);

	SubmitEntry();
}

void Bullet::Collision(BaseEnemy*)
{
	switch (whoShot)
	{
	case Bullet::PLAYER:
		Destroy();
		BsphereToggle = true;
		break;
	case Bullet::ENEMY:
		break;
	default:
		break;
	}
}

void Bullet::Collision(PlayerTank*)
{
	switch (whoShot)
	{
	case Bullet::PLAYER:
		break;
	case Bullet::ENEMY:
		Destroy();
		BsphereToggle = true;
		break;
	default:
		break;
	}
}

void Bullet::Collision(FastEnemy*)
{
	BsphereToggle = true;
}

void Bullet::Destroy()
{
	SubmitExit();
}

Bullet::Sender Bullet::WhoShot()
{
	return whoShot;
}

void Bullet::Update()
{
	BulletPos += Vect(0, 0, 0.5f) * BulletRot * BulletTransSpeed;

	Matrix world = BulletScale * BulletRot * Matrix(TRANS, BulletPos);
	pGOBullet->SetWorld(world);

	this->UpdateCollisionData(world);
}

void Bullet::Draw()
{
	pGOBullet->Render(SceneManager::GetCurrCamera());

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

void Bullet::SceneEntry()
{
	SetCollidableGroup<Bullet>();
	SubmitCollisionRegistration();
	SubmitDrawRegistration();
	SubmitUpdateRegistration();
	SubmitAlarmRegistration(2, AlarmableManager::ALARM_0);
}

void Bullet::SceneExit()
{
	SubmitCollisionDeregistration();
	SubmitDrawDeregistration();
	SubmitUpdateDeregistration();
	SubmitAlarmDeregistration(AlarmableManager::ALARM_0);
	BulletFactory::RecycleBullet(this);
}

void Bullet::Alarm0()
{
	Destroy();
}
