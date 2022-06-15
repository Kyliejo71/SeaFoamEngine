#include "SeaFoamSprite.h"
#include "ImageManager.h"
#include "SceneManager.h"
#include "ShaderManager.h"
#include "ModelManager.h"

SeaFoamSprite::~SeaFoamSprite()
{
	delete pGOSprite;
}

SeaFoamSprite::SeaFoamSprite(std::string imgKey)
{
	Image* pImage = ImageManager::Get(imgKey);

	Model* pModelSprite = ModelManager::Get("spriteModel");
	ShaderObject* pShaderObject_sprite = ShaderManager::Get("SpriteRender");

	pGOSprite = new GraphicsObject_Sprite(pModelSprite, pShaderObject_sprite, pImage, pImage->pImageRect);

	angle = 0.0f;
	scaleX = 1.0f;
	scaleY = 1.0f;
	centerX = 0.0f;
	centerY = 0.0f;
}

float SeaFoamSprite::GetAngle()
{
	return angle;
}

void SeaFoamSprite::Render(Camera* pCam)
{
	pGOSprite->Render(pCam);
}

void SeaFoamSprite::SetAngle(float a)
{
	angle = a;
}

void SeaFoamSprite::SetCenter(float x, float y)
{
	centerX = x;
	centerY = y;

	//pGOSprite->origPosX = x;
	//pGOSprite->origPosY = y;
}

void SeaFoamSprite::SetPosition(float x, float y)
{
	Matrix world;
	Matrix RotZ;
	Matrix Scale;
	Matrix Trans;

	Scale.set(SCALE, scaleX, scaleY, 1.0f);
	RotZ.set(ROT_Z, angle);
	Trans.set(TRANS, x, y, 0.0f);

	world = Scale * RotZ * Trans;
	pGOSprite->SetWorld(world);
}

void SeaFoamSprite::SetScaleFactor(float scalex, float scaley)
{
	scaleX = scalex;
	scaleY = scaley;
}

void SeaFoamSprite::SetScalePixel(float width, float height)
{
	pGOSprite->origWidth = width;
	pGOSprite->origHeight = height;
}
