#pragma once
#include <map>
#include <string>
using std::string;

class CommandHandler
{
public:
	void Handle(string command);

private:
	void Execute(string command);
	
	const string HELP = "help";
	const string GO_TO = "go to";
	const string LOOK = "look at";
	const string RUN = "run away";
	const string STATS = "view stats";
	const string ATTACK = "attack";

	const std::map<string, string> commands = { { HELP, "Print a list of accepted commands." },
		{ GO_TO, "Go to a location mentioned in the room description." },
		{ LOOK, "Look at an object or location." },
		{ RUN, "Run away from a source of danger." },
		{ STATS, "View the player stats." },
		{ ATTACK, "Attack a person or creature" }
	};
};
