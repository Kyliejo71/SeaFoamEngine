#include "SeaFoamEngine.h"
#include "SeaFoamEngineAttorney.h"

int CALLBACK WinMain(HINSTANCE , HINSTANCE ,  LPSTR , int)                  
{ 
	// start the game
	SeaFoamEngine::Run();

	SeaFoamEngineAttorney::Delete();

	return 0;                                       
}

