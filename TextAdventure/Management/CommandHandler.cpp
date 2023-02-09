#include "CommandHandler.h"
#include "Clock.h"
#include "PlayerState.h"
#include "Printing/Printer.h"

CommandHandler::CommandHandler(const shared_ptr<Clock> t_clock, const shared_ptr<Printer> t_printer)
	: clock(t_clock), printer(t_printer) {
}

void CommandHandler::handle(string command) {
	printer->resetColor();
	execute(command);
}

bool CommandHandler::testFunc(string str) const {
	log.print("Test function called with argument of: [" + str + "]");
	return true;
}

bool CommandHandler::execute(string command) {
	bool executed = true;
	bool shouldTick = true;

	if (command == HELP) {
		shouldTick = false;
		printer->newLine();

		for (auto command : commands) {
			printer->print(command.names[0] + "\t\t" + command.helpText);
		}
		printer->newLine();
	}
	// look at object
	//else if (command.rfind(LOOK_AT, 0) > -1)
	//{
	//}
	else if (command == STATS) {
		shouldTick = false;
	}
	else if (command == INVENTORY) {
		shouldTick = false;
		printer->type("Your inventory is empty... unless you count pocket lint.");
	}
	else if (command == "start timer") {
		clock->startTimer(std::bind(&CommandHandler::testFunc, this, std::placeholders::_1), "my test string", 3);
		shouldTick = false;
	}
	else if (command == WAIT) {
		// waiting
		printer->type("Time passes...");
	}
	else {
		printer->print("That command is not recognized.");
		executed = false;
		shouldTick = false;
	}

	if (shouldTick) {
		clock->tick();
	}

	return executed;
}
