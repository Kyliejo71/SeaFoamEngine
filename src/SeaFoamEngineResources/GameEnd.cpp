#include "SeaFoamEngine.h"
#include "..//User Code/BulletFactory.h"

void SeaFoamEngine::GameEnd()
{
	BulletFactory::Terminate();
}
