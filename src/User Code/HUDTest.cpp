#include "HUDTest.h"
#include "SeaFoamSprite.h"
#include "SceneManager.h"

HUDTest::HUDTest()
{
	stitch = new SeaFoamSprite("Stitch");

	stitch->SetScalePixel(50.0f, 50.0f);
	stitch->SetScaleFactor(0.5f, 0.5f);
	stitch->SetPosition(150, 500);

	SubmitEntry();
}

HUDTest::~HUDTest()
{
	delete stitch;
}

void HUDTest::Draw2D()
{
	stitch->Render(SceneManager::Get2DCamera());
}

void HUDTest::SceneEntry()
{
	SubmitDrawRegistration();
}

void HUDTest::SceneExit()
{
	SubmitDrawDeregistration();
}
