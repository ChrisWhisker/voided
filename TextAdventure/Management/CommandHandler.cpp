#include "CommandHandler.h"
#include <iostream>
using std::cout;

shared_ptr<CommandHandler> CommandHandler::instance = nullptr;

shared_ptr<CommandHandler> CommandHandler::getInstance()
{
	if (!instance)
	{
		instance = std::make_shared<CommandHandler>(CommandHandler());
	}
	return instance;
}

CommandHandler::CommandHandler()
{
	clock = Clock::getInstance();
	printer = Printer::getInstance();
	player = PlayerState::getInstance();
}

void CommandHandler::handle(string command)
{
	// TODO trim leading and trailing white space
	// TODO convert entire string to lowercase
	if (execute(command))
	{
		player->addHealth(-3);
	}
}

bool CommandHandler::execute(string command)
{
	bool executed = true;
	bool shouldTick = true;

	if (command == HELP)
	{
		shouldTick = false;
		
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
		shouldTick = false;
	}
	else if (command == INVENTORY)
	{
		shouldTick = false;
		printer->print("Your inventory is empty... unless you count pocket lint.");
	}
	else if (command == "start timer")
	{
		clock->startTimer(std::bind(&CommandHandler::testFunc, this, std::placeholders::_1), 3);
		shouldTick = false;
	}
	else if (command == WAIT)
	{
		// waiting
	}
	else
	{
		cout << ("That command is not recognized.\n");
		executed = false;
		shouldTick = false;
	}

	if (shouldTick)
	{
		clock->tick();
	}

	return executed;
}