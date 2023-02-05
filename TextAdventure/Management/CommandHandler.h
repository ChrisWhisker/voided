#pragma once
#include <functional>
#include <map>
#include <memory>
#include <string>
using std::shared_ptr;
using std::string;

class Clock;
class Printer;

class CommandHandler
{
public:
	CommandHandler(shared_ptr<Clock> clock, shared_ptr<Printer> printer);

	void handle(string command);
	bool testFunc(string str);

private:
	shared_ptr<Clock> clock;
	shared_ptr<Printer> printer;

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
