#include "TreeObj.h"
#include "ModelManager.h"
#include "ShaderManager.h"
#include "TextureManager.h"
#include "Visualizer.h"
#include "SceneManager.h"

TreeObj::TreeObj()
{
	Vect LightColor(1.50f, 1.50f, 1.50f, 1.0f);
	Vect LightPos(1.0f, 1.0f, 1.0f, 1.0f);
	pGObj_TreeLight = new GraphicsObject_TextureLight(ModelManager::Get("tree"), 
		ShaderManager::Get("textureLight"), TextureManager::Get("treeTex"), LightColor, LightPos);

	bSphereToggle = false;

	TreeScale.set(SCALE, 1, 1, 1);
	TreeRot.set(IDENTITY);
	TreePos.set(150, 3, 200);

	Matrix World;
	World = TreeScale * TreeRot * Matrix(TRANS, TreePos);
	pGObj_TreeLight->SetWorld(World);

	SetColliderModel(pGObj_TreeLight->getModel(), Collidable::VolumeType::BSPHERE);

	this->UpdateCollisionData(World);

	SubmitEntry();
}

TreeObj::~TreeObj()
{
	SubmitExit();

	delete pGObj_TreeLight;
}

void TreeObj::Collision(Frigate*)
{
	DebugMsg::out("Collision tree with frig!\n");
	bSphereToggle = true;
}

void TreeObj::Draw()
{
	pGObj_TreeLight->Render(SceneManager::GetCurrCamera());

	if (bSphereToggle)
	{
		Visualizer::ShowCollisionVolume(this->GetCollisionVolume(), Vect(1.0f, 0.0f, 0.0f, 1.0f));
	}
	else
	{
		Visualizer::ShowCollisionVolume(this->GetCollisionVolume(), Vect(0.0f, 1.0f, 1.0f, 1.0f));
	}
	bSphereToggle = false;
}

void TreeObj::SceneEntry()
{
	SubmitDrawRegistration();
	SetCollidableGroup<TreeObj>();
	SubmitCollisionRegistration();
}

void TreeObj::SceneExit()
{
	SubmitDrawDeregistration();
	SubmitCollisionDeregistration();
}
