#include "SeaFoamEngine.h"

//-----------------------------------------------------------------------------
// Game::GameInitialize()
//		Allows the engine to perform any initialization it needs to before 
//      starting to run.  This is where it can query for any required services 
//      and load any non-graphic related content. 
//-----------------------------------------------------------------------------

void SeaFoamEngine::GameInitialize()
{
	// Game Window Device setup
	this->setWindowName("SeaFoam Engine");
	this->setWidthHeight(800, 600);
	this->SetClearColor(0.44f, 0.93f, 0.72f, 1.0f);

	// Use this area, for one time non-graphic creation

}