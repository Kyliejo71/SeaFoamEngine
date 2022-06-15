#ifndef _CollisionTestSelfCmd
#define _CollisionTestSelfCmd

#include "CollisionTestCmdBase.h"

class CollisionGroup;
class CollisionDispatchBase;

class CollisionTestSelfCmd : public CollisionTestCmdBase
{
public:

	CollisionTestSelfCmd() = default;
	CollisionTestSelfCmd(CollisionGroup* g, CollisionDispatchBase* pd);
	CollisionTestSelfCmd(const CollisionTestSelfCmd&) = default;
	CollisionTestSelfCmd& operator=(const CollisionTestSelfCmd&) = default;
	virtual ~CollisionTestSelfCmd();

	virtual void execute();

private:

	CollisionGroup* pG;
	CollisionDispatchBase* pDispatch;

};

#endif _CollisionTestSelfCmd
