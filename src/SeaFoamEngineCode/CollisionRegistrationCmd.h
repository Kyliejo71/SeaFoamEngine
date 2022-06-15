#ifndef _CollisionRegistrationCmd
#define _CollisionRegistrationCmd

#include "CommandBase.h"
#include "Collidable.h"


class CollisionRegistrationCmd : public CommandBase
{
public:

	CollisionRegistrationCmd(Collidable* c);
	CollisionRegistrationCmd(const CollisionRegistrationCmd&) = default;
	CollisionRegistrationCmd& operator=(const CollisionRegistrationCmd&) = default;
	virtual ~CollisionRegistrationCmd() = default;

	virtual void execute();

private:

	Collidable* ptrC;
};

#endif _CollisionRegistrationCmd
