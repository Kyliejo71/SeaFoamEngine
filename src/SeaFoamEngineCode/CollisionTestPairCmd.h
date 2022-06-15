#ifndef _CollisionTestPairCmd
#define _CollisionTestPairCmd

#include "CollisionTestCmdBase.h"

class CollisionGroup;
class CollisionDispatchBase;

class CollisionTestPairCmd : public CollisionTestCmdBase
{
public:

	CollisionTestPairCmd() = default;
	CollisionTestPairCmd(CollisionGroup* g1, CollisionGroup* g2, CollisionDispatchBase* pd);
	CollisionTestPairCmd(const CollisionTestPairCmd&) = default;
	CollisionTestPairCmd& operator=(const CollisionTestPairCmd&) = default;
	virtual ~CollisionTestPairCmd();

	virtual void execute();

private:

	CollisionGroup* pG1;
	CollisionGroup* pG2;
	CollisionDispatchBase* pDispatch;

};

#endif _CollisionTestPairCmd
