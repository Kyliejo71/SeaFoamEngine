#ifndef _SceneRegistrationBroker
#define _SceneRegistrationBroker

//#include "AzulCore.h"
#include <list>

class CommandBase;

class SceneRegistrationBroker
{
public:

	SceneRegistrationBroker() = default;
	SceneRegistrationBroker(const SceneRegistrationBroker&) = delete;
	SceneRegistrationBroker& operator=(const SceneRegistrationBroker&) = delete;
	~SceneRegistrationBroker() = default;

	void AddCommand(CommandBase* cmd);
	void ExecuteCommands();

private:

	using CommandList = std::list<CommandBase*>;
	CommandList CmdList;
};

#endif _SceneRegistrationBroker

