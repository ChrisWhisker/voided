#pragma once
#include "Printer.h"
#include <map>
#include <memory>
#include <string>
using std::shared_ptr;
using std::string;

class CommandHandler
{
public:
	static shared_ptr<CommandHandler> getInstance();
	void handle(string command);

private:
	static shared_ptr<CommandHandler> instance;
	CommandHandler();

	shared_ptr<Printer> printer;
	shared_ptr<PlayerState> player;

	bool execute(string command);
	
	const string HELP = "help";
	const string LOOK_AT = "look at";
	const string GO_TO = "go to";
	const string RUN = "run away";
	const string STATS = "view stats";
	const string INVENTORY = "view inventory";
	const string ATTACK = "attack";

	const std::map<string, string> commands = { { HELP, "Print a list of accepted commands." },
		{ LOOK_AT, "Look at an object or location." },
		{ GO_TO, "Go to a location mentioned in the room description." },
		{ RUN, "Run away from a source of danger." },
		{ STATS, "View your stats." },
		{ INVENTORY, "View your inventory." },
		{ ATTACK, "Attack a person or creature" }
	};
};
