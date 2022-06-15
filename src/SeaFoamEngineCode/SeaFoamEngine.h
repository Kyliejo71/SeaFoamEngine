#ifndef _SeaFoamEngine
#define _SeaFoamEngine

#include "AzulCore.h"

class SeaFoamEngine : public Engine
{
	friend class SeaFoamEngineAttorney;
private:
	static SeaFoamEngine* ptrInstance;

	// constructor
	SeaFoamEngine() = default;
	SeaFoamEngine(const SeaFoamEngine&) = delete;
	SeaFoamEngine& operator=(const SeaFoamEngine&) = delete;
	~SeaFoamEngine() = default;

	static SeaFoamEngine& Instance()
	{
		if (!ptrInstance)
			ptrInstance = new SeaFoamEngine();
		return *ptrInstance;
	};

	// Methods Users need to overload
	virtual void UnLoadContent();
    virtual void Initialize();
    virtual void LoadContent();
	virtual void Update();
    virtual void Draw();

	//For Users to define
	void LoadResorces();
	void GameInitialize();
	void GameEnd();
	
	// legacy
	SeaFoamEngine( const char* windowName, const int Width,const int Height);

	void privDelete();

	static float GetTime() { return Instance().GetTimeInSeconds(); };
	static void Delete() { Instance().privDelete(); }

public:

	static void Run() { Instance().run(); };

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Gets the width. </summary>
	///
	/// <remarks>	Kylie, 3/11/2021. </remarks>
	///
	/// <returns>	The width. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////
	static int GetWidth() { return Instance().getWidth(); };

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Gets the height. </summary>
	///
	/// <remarks>	Kylie, 3/11/2021. </remarks>
	///
	/// <returns>	The height. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	static int GetHeight() { return Instance().getHeight(); };

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Sets window name. </summary>
	///
	/// <remarks>	Kylie, 3/11/2021. </remarks>
	///
	/// <param name="name">	The name you would like for the window. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	static void SetWindowName(const char* name) { Instance().setWindowName(name); };

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Sets the width and height. </summary>
	///
	/// <remarks>	Kylie, 3/11/2021. </remarks>
	///
	/// <param name="w">	The width. </param>
	/// <param name="h">	The height. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	static void SetWidthHeight(int w, int h) { Instance().setWidthHeight(w, h); };

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Sets a clear. </summary>
	///
	/// <remarks>	Kylie, 3/11/2021. </remarks>
	///
	/// <param name="r">	Red. </param>
	/// <param name="g">	Green. </param>
	/// <param name="b">	Blue. </param>
	/// <param name="a">	Alpha. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	static void SetClear(float r, float g, float b, float a) { Instance().SetClearColor(r, g, b, a); };

};

#endif _SeaFoamEngine