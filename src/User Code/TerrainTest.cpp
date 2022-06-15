#include "TerrainTest.h"
#include "TextureTGA.h"
#include "AzulCore.h"
#include "GpuVertTypes.h"
#include "Model.h"
#include "ShaderManager.h"
#include "TextureManager.h"
#include "SceneManager.h"

TerrainTest::TerrainTest(const char* HeightMapFile, uint32_t SideLength, float MaxHeight, float StartingYValue, int RepeatU, int RepeatV)
{
	UNREFERENCED_PARAMETER(StartingYValue);
	//UNREFERENCED_PARAMETER(RepeatU);
	//UNREFERENCED_PARAMETER(RepeatV);
	//UNREFERENCED_PARAMETER(SideLength);

	int imgWidth, imgHeight, icomp;
	unsigned int dtype;
	GLbyte* imgData = gltReadTGABits(HeightMapFile, &imgWidth, &imgHeight, &icomp, &dtype);
	imgData = imgData;
	assert(imgWidth == imgHeight && imgWidth != 0); //SQUARE IMAGES ONLY!

	unsigned int side = imgWidth;
	pixel_width = 3;
	//uint8_t h_val = imgData[TexelIndex(side, 3, 5)];

	int NUM_VERTS = side * side;
	int NUM_TRIANGLES = 2 * ((SideLength - 1) * (SideLength - 1));

	VertexStride_VUN *pVerts = new VertexStride_VUN[NUM_VERTS];
	TriangleIndex* tlist = new TriangleIndex[NUM_TRIANGLES];

	//float imageScale = SideLength / side;
	float yScale = MaxHeight / 255;

	for(unsigned int x = 0; x < side; x++)
	{
		for(unsigned int z = 0; z < side; z++)
		{
			pVerts[int(x * side + z)].set((float)x * SideLength, (float)(static_cast<unsigned char>(imgData[pixel_width * (z * side + x)]) * yScale),
				(float)z * SideLength, (float)((RepeatU / (SideLength - 1)) * z), (float)((RepeatV / (SideLength - 1)) * z), 0.0f, 0.0f, 0.0f); //Normals???
			DebugMsg::out("X val: %d Z val: %d texel: %ud \n", x, z, imgData[pixel_width * (z * side + x)]);
		}
	}



	uint32_t triIndex = 0;
	uint32_t triCount = 2 * ((SideLength - 1) * (SideLength - 1));

	for (uint32_t tri = 0; tri < triCount - 1; tri++)
	{
		tlist[tri].v0 = triIndex;
		tlist[tri].v1 = triIndex + 1;
		tlist[tri].v2 = triIndex + SideLength + 1;

		tlist[tri + 1].v0 = triIndex;
		tlist[tri + 1].v1 = triIndex + SideLength + 1;
		tlist[tri + 1].v2 = triIndex + SideLength;

		triIndex++;

		if ((triIndex + 1) % SideLength == 0)
		{
			triIndex++;
		}
	}

	pModTerrain = new Model(pVerts, NUM_VERTS, tlist, NUM_TRIANGLES);

	pGO = new GraphicsObject_TextureFlat(pModTerrain, ShaderManager::Get("textureFlat"), TextureManager::Get("grass"));

	SubmitDrawRegistration();

	delete pVerts;
	delete tlist;
}

TerrainTest::~TerrainTest()
{
	delete pModTerrain;
	delete pGO;
}

int TerrainTest::TexelIndex(int side, int x, int z) const
{
	return pixel_width * (z * side + x);
}

void TerrainTest::Draw()
{
	pGO->Render(SceneManager::GetCurrCamera());
}
