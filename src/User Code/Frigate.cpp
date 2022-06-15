#include "Frigate.h"
#include "SeaFoamEngine.h"
#include "TextureManager.h"
#include "ShaderManager.h"
#include "ModelManager.h"
#include "SceneManager.h"
#include "CollisionVolumeBSphere.h"
#include "Visualizer.h"
#include "TreeObj.h"

Frigate::Frigate()
{
	Vect LightColor(1.50f, 1.50f, 1.50f, 1.0f);
	Vect LightPos(1.0f, 1.0f, 1.0f, 1.0f);
	pGObj_SpaceFrigateLight = new GraphicsObject_TextureLight(ModelManager::Get("spaceFrigate"), ShaderManager::Get("textureLight"), TextureManager::Get("spaceFrigate"), LightColor, LightPos);

	Matrix world;

	ShipScale.set(SCALE, 1, 1, 1);
	ShipRot.set(IDENTITY);
	ShipPos.set(0, 10, 0);
	world = ShipScale * ShipRot * Matrix(TRANS, ShipPos);
	pGObj_SpaceFrigateLight->SetWorld(world);

	SetColliderModel(pGObj_SpaceFrigateLight->getModel(), Collidable::VolumeType::AABB);

	this->UpdateCollisionData(world);

	SubmitEntry();
}

Frigate::~Frigate()
{
	SubmitExit();

	delete pGObj_SpaceFrigateLight;
	DebugMsg::out("Frigate Deleted\n");
}

void Frigate::Collision(BlankFrigate*)
{
	DebugMsg::out("Moveable frigate hit!\n");
	BsphereToggle = true;
}

void Frigate::Update()
{
	if (Keyboard::GetKeyState(AZUL_KEY::KEY_W))
	{
		ShipPos += Vect(0, 0, 0.5f) * ShipRot * ShipTransSpeed;
	}
	else if (Keyboard::GetKeyState(AZUL_KEY::KEY_S))
	{
		ShipPos += Vect(0, 0, 0.5f) * ShipRot * -ShipTransSpeed;
	}

	// Ship Rotation movement (not using time-based values for simplicity)
	if (Keyboard::GetKeyState(AZUL_KEY::KEY_A))
	{
		ShipRot *= Matrix(ROT_Y, ShipRotAng);
	}
	else if (Keyboard::GetKeyState(AZUL_KEY::KEY_D))
	{
		ShipRot *= Matrix(ROT_Y, -ShipRotAng);
	}

	// Spaceship adjust matrix
	Matrix world = ShipScale * ShipRot * Matrix(TRANS, ShipPos);
	pGObj_SpaceFrigateLight->SetWorld(world);

	this->UpdateCollisionData(world);

}

void Frigate::Draw()
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

void Frigate::SceneEntry()
{
	SubmitUpdateRegistration();
	SubmitDrawRegistration();
	SetCollidableGroup<Frigate>();
	SubmitCollisionRegistration();
}

void Frigate::SceneExit()
{
	SubmitUpdateDeregistration();
	SubmitDrawDeregistration();
	SubmitCollisionDeregistration();
}
