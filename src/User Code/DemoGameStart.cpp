#include "DemoGameStart.h"
#include "StartGame.h"

void DemoGameStart::Initialize()
{
	startText = new StartGame();
}

void DemoGameStart::SceneEnd()
{
	delete startText;
}
