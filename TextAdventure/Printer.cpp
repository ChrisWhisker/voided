#include "Printer.h"
#include <chrono>
#include <iostream>
#include <thread>
using std::chrono::milliseconds;
using std::cout;
using std::this_thread::sleep_for;

Printer::Printer()
{
	player = PlayerState::getInstance();
}

void Printer::print(string str)
{
	if (debugMode)
	{
		cout << str;
		return;
	}
	
	typeText(str, 3, 30, 200);
}

void Printer::printByLine(string str)
{
	if (debugMode)
	{
		cout << str;
		return;
	}
	
	typeText(str, 0, 0, 300);
}

void Printer::typeText(string str, int msAfterChar, int msAfterWord, int msAfterLine)
{
	for (char c : str)
	{
		cout << c;
		if (c == ' ')
		{
			sleep_for(milliseconds(msAfterWord));
		}
		else
		{
			sleep_for(milliseconds(msAfterChar));
		}
	}
	sleep_for(milliseconds(msAfterLine));
}

void Printer::printMainStats()
{
	print(player->mainStats() + "\n");
}

void Printer::printCombatStats()
{
	print(player->combatStats() + "\n");
}

void Printer::printAllStats()
{
	print(player->allStats() + "\n");
}


