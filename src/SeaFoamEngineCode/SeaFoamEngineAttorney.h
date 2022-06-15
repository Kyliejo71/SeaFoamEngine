#ifndef _SeaFoamEngineAttorney
#define _SeaFoamEngineAttorney

#include "SeaFoamEngine.h"

class SeaFoamEngineAttorney
{
	friend class FreezeTime;
public:

	SeaFoamEngineAttorney() = default;
	SeaFoamEngineAttorney(const SeaFoamEngineAttorney&) = delete;
	SeaFoamEngineAttorney& operator=(const SeaFoamEngineAttorney&) = delete;
	~SeaFoamEngineAttorney() = default;

	friend int CALLBACK WinMain(HINSTANCE, HINSTANCE, LPSTR, int);

private:

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Gets the game time. </summary>
	///
	/// <remarks>	Kylie, 3/11/2021. </remarks>
	///
	/// <returns>	The game time. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	static float GetTime() { return SeaFoamEngine::GetTime(); }
	static void Delete() { SeaFoamEngine::Delete(); }
};

#endif _SeaFoamEngineAttorney