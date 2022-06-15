#include "LifeBar.h"
#include "SeaFoamSprite.h"

LifeBar::LifeBar()
{
	Heart1 = new SeaFoamSprite("Heart");

	Heart1->SetScalePixel(50.0f, 50.0f);
	Heart1->SetScaleFactor(0.05f, 0.05f);
	Heart1->SetPosition(50, 550);

	Heart2 = new SeaFoamSprite("Heart");

	Heart2->SetScalePixel(50.0f, 50.0f);
	Heart2->SetScaleFactor(0.05f, 0.05f);
	Heart2->SetPosition(100, 550);

	Heart3 = new SeaFoamSprite("Heart");

	Heart3->SetScalePixel(50.0f, 50.0f);
	Heart3->SetScaleFactor(0.05f, 0.05f);
	Heart3->SetPosition(150, 550);

	SubmitEntry();
}

LifeBar::~LifeBar()
{
	SubmitExit();

	delete Heart1;
	delete Heart2;
	delete Heart3;
}

void LifeBar::UpdateHealth()
{
	TotalLives--;
}

void LifeBar::Draw2D()
{
	if(TotalLives > 2)
	{
		Heart3->Render(SceneManager::Get2DCamera());
	}
	if (TotalLives > 1)
	{
		Heart2->Render(SceneManager::Get2DCamera());
	}
	if (TotalLives > 0)
	{
		Heart1->Render(SceneManager::Get2DCamera());
	}
}

void LifeBar::SceneEntry()
{
	SubmitDrawRegistration();
}

void LifeBar::SceneExit()
{
	SubmitDrawDeregistration();
}
