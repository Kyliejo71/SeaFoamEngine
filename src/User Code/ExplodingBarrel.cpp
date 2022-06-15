#include "ExplodingBarrel.h"
#include "ModelManager.h"
#include "ShaderManager.h"
#include "TextureManager.h"
#include "SceneManager.h"
#include "Visualizer.h"

ExplodingBarrel::ExplodingBarrel()
{
	explosion = new GraphicsObject_ColorNoTexture(ModelManager::Get("sphere"), ShaderManager::Get("colorConstant"));

	Vect LightColor(1.50f, 1.50f, 1.50f, 1.0f);
	Vect LightPos(1.0f, 1.0f, 1.0f, 1.0f);
	pGOBarrel = new GraphicsObject_TextureLight(ModelManager::Get("sphere"), ShaderManager::Get("textureLight"), TextureManager::Get("blankTex"), LightColor, LightPos);

	Matrix world;

	BarrelScale.set(SCALE, 8, 8, 8);
	BarrelRot.set(IDENTITY);
	BarrelPos.set(100, 10, 200);
	world = BarrelScale * BarrelRot * Matrix(TRANS, BarrelPos);
	pGOBarrel->SetWorld(world);

	SetColliderModel(pGOBarrel->getModel(), Collidable::VolumeType::BSPHERE);

	this->UpdateCollisionData(world);

	exploded = false;

	SubmitEntry();
}

ExplodingBarrel::~ExplodingBarrel()
{
	SubmitExit();
	delete pGOBarrel;
	delete explosion;
}

void ExplodingBarrel::Collision(Collidable*)
{
	BsphereToggle = true;

	DebugMsg::out("Barrel Collided\n");

	if (exploded)
	{
		delete this;
	}
	else
	{
		Explode();
		exploded = true;
	}
}

void ExplodingBarrel::Draw()
{
	pGOBarrel->Render(SceneManager::GetCurrCamera());

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

void ExplodingBarrel::SceneEntry()
{
	SubmitDrawRegistration();
	SetCollidableGroup<ExplodingBarrel>();
	SubmitCollisionRegistration();
}

void ExplodingBarrel::SceneExit()
{
	SubmitDrawDeregistration();
	SubmitCollisionDeregistration();
}

void ExplodingBarrel::Explode()
{
	Matrix world;

	ExScale.set(SCALE, 300, 300, 300);
	ExRot = BarrelRot;
	ExPos = BarrelPos;
	world = ExScale * ExRot * Matrix(TRANS, ExPos);
	explosion->SetWorld(world);

	SetColliderModel(explosion->getModel(), Collidable::VolumeType::BSPHERE);
	this->UpdateCollisionData(world);
}
