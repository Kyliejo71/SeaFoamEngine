#ifndef _VisualizerManger
#define _VisualizerManger

#include <list>

class VisualizerCmd;

class VisualizerManger
{
public:

	VisualizerManger() = default;
	VisualizerManger(const VisualizerManger&) = delete;
	VisualizerManger& operator=(const VisualizerManger&) = delete;
	~VisualizerManger() = default;

	void AddCommand(VisualizerCmd* cmd);
	void ExecuteCommands();

private:

	using CommandList = std::list<VisualizerCmd*>;
	CommandList CmdList;
};

#endif _VisualizerManger


