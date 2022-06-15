#ifndef _CollisionDeregistrationCmd
#define _CollisionDeregistrationCmd

#include "CommandBase.h"
#include "Collidable.h"


class CollisionDeregistrationCmd : public CommandBase
{
public:

	CollisionDeregistrationCmd(Collidable* c);
	CollisionDeregistrationCmd(const CollisionDeregistrationCmd&) = default;
	CollisionDeregistrationCmd& operator=(const CollisionDeregistrationCmd&) = default;
	virtual ~CollisionDeregistrationCmd() = default;

	virtual void execute();

private:

	Collidable* ptrC;
};

#endif _CollisionDeregistrationCmd
