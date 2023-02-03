#include "CommandHandler.h"
#include <iostream>

void CommandHandler::Handle(string command)
{
	// trim leading and trailing white space
	// convert entire string to lowercase
	Execute(command);
}

void CommandHandler::Execute(string command)
{
	if (command == "help")
	{
		std::cout << "\n";
		for (auto p : commands)
		{
			std::cout << p.first << " : " << p.second << "\n";
		}
	}
	else
	{
		std::cout << "\nThat command is not recognized.\n";
	}
}