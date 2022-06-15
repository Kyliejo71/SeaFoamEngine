#ifndef _CollisionTestCmdBase
#define _CollisionTestCmdBase

class CollisionTestCmdBase
{
public:

	CollisionTestCmdBase() = default;
	CollisionTestCmdBase(const CollisionTestCmdBase&) = default;
	CollisionTestCmdBase& operator=(const CollisionTestCmdBase&) = default;
	virtual ~CollisionTestCmdBase() = default;

	virtual void execute() = 0;

	//template CollisionDispatch* pDispatch<Collidable*;
};

#endif _CollisionTestCmdBase

