#ifndef _DemoGameStart
#define _DemoGameStart

#include "AzulCore.h"
#include "Scene.h"

class StartGame;

class DemoGameStart : public Scene
{
public:

	DemoGameStart() = default;
	DemoGameStart(const DemoGameStart&) = default;
	DemoGameStart& operator=(const DemoGameStart&) = default;
	~DemoGameStart() = default;

private:

	friend class SeaFoamEngine;

	virtual void Initialize();
	virtual void SceneEnd();

	StartGame* startText;

};

#endif _DemoGameStart
