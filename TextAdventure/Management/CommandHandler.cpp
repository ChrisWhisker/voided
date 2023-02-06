#include "CommandHandler.h"
#include "Clock.h"
#include "PlayerState.h"
#include "Printer.h"

CommandHandler::CommandHandler(shared_ptr<Clock> clk, shared_ptr<Printer> prtr) : clock(clk), printer(prtr) { }

void CommandHandler::handle(string command)
{
	// TODO trim leading and trailing white space
	// TODO convert entire string to lowercase
	printer->resetColor();
	execute(command);
}

bool CommandHandler::testFunc(string str)
{
	printer->debug(DebugType::log, "Test function called with argument of: " + str);
	return true;
}

bool CommandHandler::execute(string command)
{
	bool executed = true;
	bool shouldTick = true;

	if (command == HELP)
	{
		shouldTick = false;
		printer->newLine();

		for (auto p : commands)
		{
			printer->print(p.first + "\t\t" + p.second); // TODO use setw(20) to align better
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
		printer->type("Your inventory is empty... unless you count pocket lint.");
	}
	else if (command == "start timer")
	{
		clock->startTimer(std::bind(&CommandHandler::testFunc, this, std::placeholders::_1), "my test string", 3);
		shouldTick = false;
	}
	else if (command == WAIT)
	{
		// waiting
	}
	else
	{
		printer->print("That command is not recognized.");
		executed = false;
		shouldTick = false;
	}

	if (shouldTick)
	{
		clock->tick();
	}

	return executed;
}