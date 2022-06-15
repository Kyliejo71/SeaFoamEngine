#include "CollisionRegistrationCmd.h"
#include "CollidableAttorney.h"

CollisionRegistrationCmd::CollisionRegistrationCmd(Collidable* c)
	:ptrC(c)
{
}

void CollisionRegistrationCmd::execute()
{
	CollidableAttorney::Registration::CollisionRegistration(ptrC);
}
