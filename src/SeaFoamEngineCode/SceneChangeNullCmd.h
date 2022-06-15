#ifndef _SceneChangeNullCmd
#define _SceneChangeNullCmd

#include "SceneChangeCmdBase.h"

class SceneChangeNullCmd : public SceneChangeCmdBase
{
public:

	SceneChangeNullCmd() = default;
	SceneChangeNullCmd(const SceneChangeNullCmd&) = default;
	SceneChangeNullCmd& operator=(const SceneChangeNullCmd&) = default;
	virtual ~SceneChangeNullCmd() = default;

	virtual void execute() {};

};

#endif _SceneChangeNullCmd
