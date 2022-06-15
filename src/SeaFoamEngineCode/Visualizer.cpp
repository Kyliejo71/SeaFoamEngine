#include "Visualizer.h"
#include "ModelManager.h"
#include "ShaderManager.h"
#include "CollisionVolumeBSphere.h"
#include "SceneManager.h"
#include "CollisionVolume.h"
#include "CollisionVolumeAABB.h"
#include "CollisionVolumeOBB.h"
#include "VisualizerManager.h"
#include "VisualizerCmd.h"
#include "SceneAttorney.h"
#include "SceneManager.h"

Visualizer* Visualizer::ptrInstance = nullptr;

Visualizer::Visualizer()
{
	Vect Blue(0.0f, 0.0f, 1.0f, 1.0f);

	WFUnitSphere = new GraphicsObject_WireframeConstantColor(ModelManager::Get("sphere"), ShaderManager::Get("colorConstant"), Blue);
	WFUnitBox = new GraphicsObject_WireframeConstantColor(ModelManager::Get("box"), ShaderManager::Get("colorConstant"), Blue);
}
Visualizer::~Visualizer()
{
	delete WFUnitSphere;
	delete WFUnitBox;
}
void Visualizer::Delete()
{
	delete ptrInstance;
	ptrInstance = nullptr;
}

void Visualizer::privRenderBSphere(Matrix& S, const Vect& col)
{
	WFUnitSphere->SetColor(col);
	WFUnitSphere->SetWorld(S);
	WFUnitSphere->Render(SceneManager::GetCurrCamera());
}

void Visualizer::privRenderBox(Matrix& S, const Vect& col)
{
	WFUnitBox->SetColor(col);
	WFUnitBox->SetWorld(S);
	WFUnitBox->Render(SceneManager::GetCurrCamera());
}

void Visualizer::ShowBSphere(const CollisionVolumeBSphere& S, const Vect& col, VisualizerCmd* cmd)
{
	CollisionVolumeBSphere colV = S;

	Vect BSphereSize = colV.GetRadius() * Vect(1, 1, 1);
	const Vect BSpherePos = colV.GetCenter();

	Matrix worldBS = Matrix(SCALE, BSphereSize) *Matrix(IDENTITY)* Matrix(TRANS, BSpherePos);

	Instance().privRenderBSphere(worldBS, col);

	delete cmd;
}

void Visualizer::ShowAABB(const CollisionVolumeAABB& S, const Vect& col, VisualizerCmd* cmd)
{
	CollisionVolumeAABB colV = S;

	const Vect AABBSize = colV.GetMax() - colV.GetMin();

	Matrix worldAABB = Matrix(SCALE, AABBSize) * Matrix(IDENTITY) * Matrix(TRANS, 0.5 * (colV.GetMin() + colV.GetMax()));

	Instance().privRenderBox(worldAABB, col);

	delete cmd;
}

void Visualizer::ShowOBB(const CollisionVolumeOBB& S, const Vect& col, VisualizerCmd* cmd)
{
	CollisionVolumeOBB colV = S;

	const Vect OBBSize = colV.GetMax() - colV.GetMin();

	Matrix worldOBB = Matrix(SCALE, OBBSize) * Matrix(IDENTITY) * Matrix(TRANS, 0.5 * (colV.GetMin() + colV.GetMax()));

	worldOBB = worldOBB * colV.GetWorld();

	Instance().privRenderBox(worldOBB, col);

	delete cmd;
}

void Visualizer::ShowCollisionVolume(const CollisionVolume& c, const Vect& col)
{
	c.DebugView(col);
}

void Visualizer::privShowBSphereCMD(const CollisionVolumeBSphere& S, const Vect& col)
{
	SceneAttorney::AddVisualizerCmd(SceneManager::GetCurrentScene(), new VisualizerCmd(S, col, CollidableType::BSPHERE));
}

void Visualizer::privShowAABBCMD(const CollisionVolumeAABB& S, const Vect& col)
{
	SceneAttorney::AddVisualizerCmd(SceneManager::GetCurrentScene(), new VisualizerCmd(S, col, CollidableType::AABB));
}

void Visualizer::privShowOBBCMD(const CollisionVolumeOBB& S, const Vect& col)
{
	SceneAttorney::AddVisualizerCmd(SceneManager::GetCurrentScene(), new VisualizerCmd(S, col, CollidableType::OBB));
}
