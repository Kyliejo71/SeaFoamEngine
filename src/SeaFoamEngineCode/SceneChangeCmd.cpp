#include "SceneChangeCmd.h"
#include "SceneManagerAttorney.h"

void SceneChangeCmd::execute()
{
	SceneManagerAttorney::ChangeScene(newScene);
}

void SceneChangeCmd::setNewScene(Scene* s)
{
	newScene = s;
}
