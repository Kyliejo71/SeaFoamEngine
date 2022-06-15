#ifndef _SceneChangeCmdBase
#define _SceneChangeCmdBase

class SceneChangeCmdBase
{
public:

	SceneChangeCmdBase() = default;
	SceneChangeCmdBase(const SceneChangeCmdBase&) = default;
	SceneChangeCmdBase& operator=(const SceneChangeCmdBase&) = default;
	virtual ~SceneChangeCmdBase() = default;

	virtual void execute() = 0;

};

#endif _SceneChangeCmdBase