#include "CollisionDeregistrationCmd.h"
#include "CollidableAttorney.h"

CollisionDeregistrationCmd::CollisionDeregistrationCmd(Collidable* c)
	:ptrC(c)
{
}

void CollisionDeregistrationCmd::execute()
{
	CollidableAttorney::Deregistration::CollisionDeregistration(ptrC);
}
