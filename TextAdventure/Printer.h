#pragma once
#include "PlayerState.h"
#include <string>
using std::string;

class Printer
{
public:
	Printer();
	void print(string str);
	void printByLine(string str);
	void printMainStats();
	void printCombatStats();
	void printAllStats();
	
	bool debugMode = true;

private:
	shared_ptr<PlayerState> player;
	void typeText(string str, int msAfterChar, int msAfterWord, int msAfterLine);
};
