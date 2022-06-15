#include "BlankFrigate.h"
#include "ModelManager.h"
#include "ShaderManager.h"
#include "TextureManager.h"
#include "Visualizer.h"

BlankFrigate::BlankFrigate()
{
	Vect LightColor(1.50f, 1.50f, 1.50f, 1.0f);
	Vect LightPos(1.0f, 1.0f, 1.0f, 1.0f);
	pGObj_SpaceFrigateLight = new GraphicsObject_TextureLight(ModelManager::Get("spaceFrigate"), ShaderManager::Get("textureLight"), TextureManager::Get("spaceFrigate"), LightColor, LightPos);

	Matrix world;

	ShipScale.set(SCALE, 1, 1, 1);
	ShipRot.set(IDENTITY);
	ShipPos.set(150, 15, 150);
	world = ShipScale * ShipRot * Matrix(TRANS, ShipPos);
	pGObj_SpaceFrigateLight->SetWorld(world);

	SetColliderModel(pGObj_SpaceFrigateLight->getModel(), Collidable::VolumeType::AABB);

	this->UpdateCollisionData(world);

	SubmitEntry();
}

BlankFrigate::~BlankFrigate()
{
	SubmitExit();

	delete pGObj_SpaceFrigateLight;
}

void BlankFrigate::Collision(Frigate*)
{
	BsphereToggle = true;
	DebugMsg::out("Blank Frig has been hit\n");
}

void BlankFrigate::Draw()
{
	pGObj_SpaceFrigateLight->Render(SceneManager::GetCurrCamera());

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

void BlankFrigate::SceneEntry()
{
	SubmitDrawRegistration();
	SetCollidableGroup<BlankFrigate>();
	SubmitCollisionRegistration();
}

void BlankFrigate::SceneExit()
{
	SubmitDrawDeregistration();
	SubmitCollisionDeregistration();
}
