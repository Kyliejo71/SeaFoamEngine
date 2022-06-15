#ifndef _SceneChangeCmd
#define _SceneChangeCmd

#include "SceneChangeCmdBase.h"

class Scene;

class SceneChangeCmd : public SceneChangeCmdBase
{
public:

	SceneChangeCmd() = default;
	SceneChangeCmd(const SceneChangeCmd&) = default;
	SceneChangeCmd& operator=(const SceneChangeCmd&) = default;
	virtual ~SceneChangeCmd() = default;

	virtual void execute();

	void setNewScene(Scene* s);

private:

	Scene* newScene;

};

#endif _SceneChangeCmd
