#include "Printer.h"
#include "PlayerState.h"
#include <chrono>
#include <iomanip>
#include <iostream>
#include <thread>
using std::chrono::milliseconds;
using std::cout;
using std::endl;
using std::this_thread::sleep_for;

Printer::Printer(PlayerState* plr) : player(plr)
{
	srand(time(0));
}

void Printer::setPlayerState(PlayerState* plr)
{
	player = plr;
}

void Printer::prompt()
{
	cout << endl << prompts[rand() % 10] << endl << "\033[92m" << "> ";
	// cout << endl << std::setw(20) << "\033[1;7;36m" << str <<"\033[0m\n";
}

void Printer::type(string str)
{
	if (debugMode)
	{
		cout << str;
		return;
	}
	
	typeText(str, 1, 30, 200);
	cout << endl;
}

void Printer::typeByLine(string str)
{
	if (debugMode)
	{
		cout << str;
		return;
	}
	
	typeText(str, 1, 0, 200);
	cout << endl;
}

void Printer::print(string str)
{
	cout << str << endl;
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
		else if (c == '\n')
		{
			sleep_for(milliseconds(msAfterLine));
		}
		else
		{
			sleep_for(milliseconds(msAfterChar));
		}
	}
	cout << endl;
}

void Printer::printMainStats()
{
	printStats(player->mainStats());
}

void Printer::printCombatStats()
{
	printStats(player->combatStats());
}

void Printer::printAllStats()
{
	printStats(player->allStats());
}

void Printer::resetColor()
{
	cout << "\033[0m";
}

void Printer::printStats(string stats)
{
	cout << "\n==========\n" << stats << endl;
}

void Printer::debug(string str)
{
	if (debugMode)
	{
		cout << endl << std::setw(20) << "\033[1;7;36m" << str <<"\033[0m\n";
	}
}