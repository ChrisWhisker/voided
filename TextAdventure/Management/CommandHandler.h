#pragma once
#include "Printing/Logger.h"
#include <functional>
#include <memory>
#include <string>
#include <vector>
using std::shared_ptr;
using std::string;
using std::vector;

class Clock;
class Printer;

class CommandHandler {
public:
	CommandHandler(const shared_ptr<Clock> t_clock, const shared_ptr<Printer> t_printer);

	void handle(string command);
	bool testFunc(string str) const;

private:
	shared_ptr<Clock> clock;
	shared_ptr<Printer> printer;
	Logger log = Logger("CommandHandler");

	bool execute(string command);

	// In-world actions
	const string ATTACK = "attack";
	const string GO_TO = "go to";
	const string LOOK_AT = "look at";
	const string RUN = "run away";
	const string WAIT = "wait";
	// Metagame commands
	const string INVENTORY = "inventory";
	const string STATS = "stats";
	const string HELP = "help";

	struct Command {
		Command(vector<string> n, string h) : names(n), helpText(h) {}
		vector<string> names;
		string helpText;
	};

	const vector<Command> commands = {
		// In-world actions
		Command({ATTACK, "fight", "kill"}, "Attack a person or creature"),
		Command({GO_TO}, "Go to a location"),
		Command({LOOK_AT, "inspect"}, "Look at an object or location"),
		Command({RUN}, "Run away from a source of danger"),
		Command({WAIT}, "Just stand there"),
		// Metagame commands
		Command({INVENTORY}, "View your inventory"),
		Command({STATS}, "View your stats"),
		Command({HELP}, "Repeat this list of commands"),
	};
};
