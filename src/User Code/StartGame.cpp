#include "StartGame.h"
#include "SeaFoamSprite.h"
#include "SceneManager.h"
#include "DemoGameSceneOne.h"


StartGame::StartGame()
{
	NextScene = new DemoGameSceneOne();

	start = new SeaFoamSprite("StartGame");

	start->SetScalePixel(50.0f, 50.0f);
	start->SetScaleFactor(0.5f, 0.5f);
	start->SetPosition(430, 200);

	lilTank = new SeaFoamSprite("LilTank");

	lilTank->SetScalePixel(50.0f, 50.0f);
	lilTank->SetScaleFactor(0.5f, 0.5f);
	lilTank->SetPosition(400, 400);

	SceneChanged = false;

	SubmitEntry();
}

StartGame::~StartGame()
{
	if(!SceneChanged)
	{
		delete NextScene;
	}
	delete start;
	delete lilTank;
}

void StartGame::Draw2D()
{
	start->Render(SceneManager::Get2DCamera());
	lilTank->Render(SceneManager::Get2DCamera());
}

void StartGame::KeyPressed(AZUL_KEY)
{
	SceneChanged = true;
	SceneManager::SetNextScene(NextScene);
}

void StartGame::SceneEntry()
{
	SubmitDrawRegistration();
	SubmitKeyRegistration(sceneSwitch, Inputable::EventType::KEY_PRESS);
}

void StartGame::SceneExit()
{
	SubmitDrawDeregistration();
	SubmitKeyDeregistration(sceneSwitch, Inputable::EventType::KEY_PRESS);
}
