#pragma once
#include "Clock.h"
#include "PlayerState.h"
#include "Printer.h"
#include <functional>
#include <map>
#include <memory>
#include <string>
#include <iostream>  // TODO remove
using std::cout; // TODO remove
using std::endl; // TODO remove
using std::shared_ptr;
using std::string;

class CommandHandler
{
public:
	static shared_ptr<CommandHandler> getInstance();
	void handle(string command);

	bool testFunc(string str)
	{
		cout << endl << endl << "THE TEST FUNCTION HAS BEEN CALLED!" << endl << endl;
		return true;
	}

private:
	static shared_ptr<CommandHandler> instance;
	CommandHandler();

	shared_ptr<Clock> clock;
	shared_ptr<Printer> printer;
	shared_ptr<PlayerState> player;

	bool execute(string command);

	// Actions
	const string ATTACK = "attack";
	const string GO_TO = "go to";
	const string LOOK_AT = "look at";
	const string RUN = "run away";
	const string WAIT = "wait";

	// Meta commands
	const string INVENTORY = "view inventory";
	const string STATS = "view stats";
	const string HELP = "help";

	const std::map<string, string> commands = {
		// Actions
		{ ATTACK, "Attack a person or creature" },
		{ GO_TO, "Go to a location mentioned in the room description." },
		{ LOOK_AT, "Look at an object or location." },
		{ RUN, "Run away from a source of danger." },
		{ WAIT, "Just stand there" },
		// Meta commands
		{ INVENTORY, "View your inventory." },
		{ STATS, "View your stats." },
		{ HELP, "See this list of accepted commands." }
	};
};
