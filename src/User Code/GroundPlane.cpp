#include "GroundPlane.h"
#include "ModelManager.h"
#include "ShaderManager.h"
#include "TextureManager.h"
#include "SceneManager.h"
#include "SceneDemo.h"

GroundPlane::~GroundPlane()
{
	delete pGObj_Plane;

	SubmitExit();
}

GroundPlane::GroundPlane(Vect pos)
{
	pGObj_Plane = new GraphicsObject_TextureFlat(ModelManager::Get("plane"), ShaderManager::Get("textureFlat"), TextureManager::Get("grass"));


	// Creating matrices for in-world placement
	Matrix world;
	GroundScale.set(SCALE, 100, 100, 100);
	GroundRot.set(IDENTITY);
	GroundPos.set(pos);
	world = GroundScale * GroundRot * Matrix(TRANS, GroundPos);
	pGObj_Plane->SetWorld(world);

	SubmitEntry();
}

void GroundPlane::Draw()
{
	pGObj_Plane->Render(SceneManager::GetCurrCamera());
}

void GroundPlane::SceneEntry()
{
	SubmitDrawRegistration();
}

void GroundPlane::SceneExit()
{
	SubmitDrawDeregistration();
}
