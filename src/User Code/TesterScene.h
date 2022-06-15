#ifndef _TesterScene
#define _TesterScene

#include "Scene.h"

class Frigate;

class TesterScene : public Scene
{
public:

	TesterScene() = default;
	TesterScene(const TesterScene&) = default;
	TesterScene& operator=(const TesterScene&) = default;
	~TesterScene() = default;

private:

	friend class SeaFoamEngine;

	virtual void Initialize();
	virtual void SceneEnd();

	//Frigate* GOFrig;

};

#endif _TesterScene
