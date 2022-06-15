#include "SeaFoamEngine.h"
#include "ShaderManagerAttorney.h"
#include "TextureManagerAttorney.h"
#include "ModelMangerAttorney.h"
#include "SceneManagerAttorney.h"
#include "TimeManagerAttorney.h"
#include "VisualizerAttorney.h"
#include "ImageManagerAttorney.h"

SeaFoamEngine* SeaFoamEngine::ptrInstance = nullptr;

void SeaFoamEngine::Initialize()
{
	this->GameInitialize(); //calls user defined method for initialization
}

void SeaFoamEngine::LoadContent()
{
	this->LoadResorces(); //calls user defined resource loading

	SceneManagerAttorney::InitStartScene();
}

//-----------------------------------------------------------------------------
// Game::Update()
//      Called once per frame, update data, tranformations, etc
//      Use this function to control process order
//      Input, AI, Physics, Animation, and Graphics
//-----------------------------------------------------------------------------
void SeaFoamEngine::Update()
{
	TimeManagerAttorney::UpdateTime(this->GetTimeInSeconds());
	SceneManagerAttorney::Update();
}

//-----------------------------------------------------------------------------
// Game::Draw()
//		This function is called once per frame
//	    Use this for draw graphics to the screen.
//      Only do rendering here
//-----------------------------------------------------------------------------
void SeaFoamEngine::Draw()
{
	SceneManagerAttorney::Draw();
}
void SeaFoamEngine::privDelete()
{
	delete ptrInstance;
	ptrInstance = nullptr;
}


//-----------------------------------------------------------------------------
// Game::UnLoadContent()
//       unload content (resources loaded above)
//       unload all content that was loaded before the Engine Loop started
//-----------------------------------------------------------------------------
void SeaFoamEngine::UnLoadContent()
{
	this->GameEnd(); //User defined cending clean-up

	ShaderManagerAttorney::Delete();
	TextureManagerAttorney::Delete();
	ModelManagerAttorney::Delete();
	SceneManagerAttorney::Delete();
	TimeManagerAttorney::Delete();
	VisualizerAttorney::Delete();
	ImageManagerAttorney::Delete();
}


