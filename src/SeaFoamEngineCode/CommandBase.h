#ifndef _CommandBase
#define _CommandBase

class CommandBase
{
public:

	CommandBase() = default;
	CommandBase(const CommandBase&) = default;
	CommandBase& operator=(const CommandBase&) = default;
	virtual ~CommandBase() = default;

	virtual void execute() = 0;

};

#endif _CommandBase
