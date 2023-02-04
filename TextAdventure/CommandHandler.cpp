#include "CommandHandler.h"
#include <iostream>
using std::cout;

shared_ptr<CommandHandler> CommandHandler::instance = nullptr;

shared_ptr<CommandHandler> CommandHandler::getInstance()
{
	if (!instance)
	{
		return std::make_shared<CommandHandler>(CommandHandler());
	}
	return instance;
}

CommandHandler::CommandHandler()
{
	printer = Printer::getInstance();
}

void CommandHandler::handle(string command)
{
	// trim leading and trailing white space
	// convert entire string to lowercase
	execute(command);
}

void CommandHandler::execute(string command)
{
	if (command == HELP)
	{
		cout << "\n";
		for (auto p : commands)
		{
			cout << p.first << " : " << p.second << std::endl;
		}
	}
	// look at object
	//else if (command.rfind(LOOK_AT, 0) > -1)
	//{

	//}
	else if (command == STATS)
	{
		printer->printAllStats();
	}
	else if (command == INVENTORY)
	{
		printer->print("Your inventory is empty... unless you count pocket lint.");
	}
	else
	{
		cout << ("That command is not recognized.\n");
	}
}