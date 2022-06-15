#ifndef _TerrainTest
#define _TerrainTest

#include "AzulCore.h"
#include "Drawable.h"

class TerrainTest : public Drawable
{
public:

	TerrainTest() = default;
	TerrainTest(const char* HeightMapFile, uint32_t SideLength, float MaxHeight, float StartingYValue, int RepeatU, int RepeatV);
	TerrainTest(const TerrainTest&) = default;
	TerrainTest& operator=(const TerrainTest&) = default;
	~TerrainTest();

	int TexelIndex(int side, int x, int z) const;

	virtual void Draw();
	void Draw2D() override {}

private:

	Model* pModTerrain;
	Matrix World;
	unsigned int pixel_width;
	GraphicsObject_TextureFlat* pGO;

};

#endif _TerrainTest
