#include "SeaFoamEngine.h"
#include "ModelManager.h"
#include "TextureManager.h"
#include "ShaderManager.h"
#include "SceneManager.h"
#include "..//User Code/SceneDemo.h"
#include "..//User Code/DemoGameSceneOne.h"
#include "../User Code/DemoGameStart.h"
#include "ImageManager.h"

//-----------------------------------------------------------------------------
// Game::LoadResources()
//		Allows you to load all content needed for your engine,
//	    such as objects, graphics, etc.
//-----------------------------------------------------------------------------

void SeaFoamEngine::LoadResorces()
{
	ModelManager::Load("axis", "Axis.azul");
	ModelManager::Load("plane", "Plane.azul");
	ModelManager::Load("spaceFrigate", "space_frigate.azul");
	ModelManager::Load("sphere", Model::PreMadeModels::UnitSphere);
	ModelManager::Load("box", Model::PreMadeModels::UnitBox_WF);
	ModelManager::Load("tank", "Tank.azul");
	ModelManager::Load("tree", "tree.azul");
	ModelManager::Load("tankBody", "t99body.azul");
	ModelManager::Load("tankTurret", "t99turret.azul");
	ModelManager::Load("tank2", "tank2.azul");
	ModelManager::Load("bullet", "bullet_case.azul");
	ModelManager::Load("spriteModel", Model::PreMadeModels::UnitSquareXY);

	TextureManager::Load("spaceFrigate", "space_frigate.tga");
	TextureManager::Load("texturePlane", "grid.tga");
	TextureManager::Load("blankTex", "HotPink.tga");
	TextureManager::Load("treeTex", "tree_tex.tga");
	TextureManager::Load("stitch", "stitch.tga");
	TextureManager::Load("tankTex", "tank_tex.tga");
	TextureManager::Load("tankTex2", "tank_tex2.tga");
	TextureManager::Load("bodyTex", "body.tga");
	TextureManager::Load("grass", "seamless.tga");
	TextureManager::Load("bulletTex", "bullet_tex.tga");
	TextureManager::Load("StartGame", "StartGame.tga");
	TextureManager::Load("LilTank", "liltank.tga");
	TextureManager::Load("Heart", "life.tga");

	ShaderManager::Load("textureFlat", "textureFlatRender");
	ShaderManager::Load("textureLight", "textureLightRender");
	ShaderManager::Load("colorConstant", "colorConstantRender");
	ShaderManager::Load("noTexture", "colorNoTextureRender");
	ShaderManager::Load("SpriteRender", "spriteRender");

	ImageManager::Load("Stitch", TextureManager::Get("stitch"));
	ImageManager::Load("StartGame", TextureManager::Get("StartGame"));
	ImageManager::Load("LilTank", TextureManager::Get("LilTank"));
	ImageManager::Load("Heart", TextureManager::Get("Heart"));

	//Set Starting scene
	SceneManager::SetNextScene(new DemoGameStart());

}