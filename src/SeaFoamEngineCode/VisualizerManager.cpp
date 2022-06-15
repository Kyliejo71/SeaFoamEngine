#include "VisualizerManager.h"
#include "VisualizerCmd.h"

void VisualizerManger::AddCommand(VisualizerCmd* cmd)
{
	CmdList.push_back(cmd);
}

void VisualizerManger::ExecuteCommands()
{
	for (CommandList::const_iterator it = CmdList.begin(); it != CmdList.end(); it++)
	{
		(*it)->execute();
	}

	CmdList.clear();
}
