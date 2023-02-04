#pragma once
#include "PlayerState.h"
#include <array>
#include <string>
using std::string;

class Printer
{
public:
	static shared_ptr<Printer> getInstance();
	
	void prompt();
	void print(string str);
	void printByLine(string str);
	void printMainStats();
	void printCombatStats();
	void printAllStats();
	
	bool debugMode = false;
	void debug(string str);

	const string DIVIDER = "\n==========\n";

private:
	Printer();
	static shared_ptr<Printer> instance;

	std::array<string, 10> prompts = { "What would you like to do?", "What's the plan now?",
		"How do you want to proceed?", "Your next steps?", "What are you doing next?",
		"...and what are you gonna do about it?", "What do you want to do?", "What now?",
		"What are you doing now?", "Your next move?"
	};

	shared_ptr<PlayerState> player;
	void typeText(string str, int msAfterChar, int msAfterWord, int msAfterLine);
};
