#ifndef _SeaFoamSprite
#define _SeaFoamSprite

#include <string>
#include "AzulCore.h"


class SeaFoamSprite
{
public:

	SeaFoamSprite() = default;
	SeaFoamSprite(const SeaFoamSprite&) = delete;
	SeaFoamSprite& operator=(const SeaFoamSprite&) = delete;
	~SeaFoamSprite();

	SeaFoamSprite(std::string imgKey);

	float GetAngle();
	void Render(Camera* pCam);
	void SetAngle(float a);
	void SetCenter(float x, float y);
	void SetPosition(float x, float y);
	void SetScaleFactor(float scalex, float scaley);
	void SetScalePixel(float width, float height);

private:

	float angle;
	float centerX;
	float centerY;
	GraphicsObject_Sprite* pGOSprite;
	float scaleX;
	float scaleY;

};

#endif _SeaFoamSprite
