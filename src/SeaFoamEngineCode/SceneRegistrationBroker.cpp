#include "SceneRegistrationBroker.h"
#include "CommandBase.h"

void SceneRegistrationBroker::AddCommand(CommandBase* cmd)
{
	CmdList.push_back(cmd);
}

void SceneRegistrationBroker::ExecuteCommands()
{
	for (CommandList::const_iterator it = CmdList.begin(); it != CmdList.end(); it++)
	{
		(*it)->execute();
	}

	CmdList.clear();
}
