#include "SceneDemo.h"
#include "Frigate.h"
#include "WorldPlane.h"
#include "TesterObject.h"
#include "GodCam.h"
#include "SceneManager.h"
#include "SeaFoamEngine.h"
#include "TreeObj.h"
#include "HUDTest.h"
#include "BlankFrigate.h"
#include "TerrainTest.h"

void SceneDemo::Initialize()
{
	GOFrig = new Frigate();
	GOPlane = new WorldPlane();
	pGodCam = new GodCam();
	//pTree = new TreeObj();
	pHUD = new HUDTest();
	pBlankFrig = new BlankFrigate();
	pTerrain = new TerrainTest("Textures/hmtest2.tga", 100, 100, 0, 10, 10);

	SetCollisionPair<Frigate, BlankFrigate>();
	//SetCollisionPair<Frigate, TreeObj>();
}

void SceneDemo::SceneEnd()
{
	delete GOFrig;
	delete GOPlane;
	delete pGodCam;
	//delete pTree;
	delete pHUD;
	delete pBlankFrig;
	delete pTerrain;
}
