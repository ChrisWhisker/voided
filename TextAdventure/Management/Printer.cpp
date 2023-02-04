#include "Printer.h"
#include <chrono>
#include <iostream>
#include <thread>
using std::chrono::milliseconds;
using std::cout;
using std::endl;
using std::this_thread::sleep_for;

shared_ptr<Printer> Printer::instance = nullptr;

shared_ptr<Printer> Printer::getInstance()
{
	if (!instance)
	{
		instance = std::make_shared<Printer>(Printer());
	}
	return instance;
}

Printer::Printer()
{
	player = PlayerState::getInstance();
	srand(time(0));
}

void Printer::prompt()
{
	cout << endl << endl << prompts[rand() % 10] << endl << "> ";
}

void Printer::print(string str)
{
	if (debugMode)
	{
		cout << str;
		return;
	}
	
	typeText(str, 1, 30, 200);
	cout << endl;
}

void Printer::printByLine(string str)
{
	if (debugMode)
	{
		cout << str;
		return;
	}
	
	typeText(str, 1, 0, 500);
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
	cout << DIVIDER << player->mainStats();
}

void Printer::printCombatStats()
{
	cout << DIVIDER << player->combatStats();
}

void Printer::printAllStats()
{
	cout << DIVIDER << player->allStats();
}
