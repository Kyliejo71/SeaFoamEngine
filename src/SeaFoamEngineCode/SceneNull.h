#ifndef _SceneNull
#define _SceneNull

#include "Scene.h"

class SceneNull : public Scene
{

public:

	SceneNull() = default;
	SceneNull(const SceneNull&) = default;
	SceneNull& operator=(const SceneNull&) = default;
	virtual ~SceneNull() = default;

	virtual void Initialize() {};
	virtual void SceneEnd() {};

};

#endif _SceneNull
