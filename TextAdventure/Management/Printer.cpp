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

Printer::Printer(shared_ptr<PlayerState> plr) : player(plr)
{
	srand((unsigned int)time(0));
}

void Printer::setPlayerState(shared_ptr<PlayerState> plr)
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

void Printer::type(string str, Color color)
{
	setTextColor(color);
	type(str);
	resetColor();
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

void Printer::typeByLine(string str, Color color)
{
	setTextColor(color);
	typeByLine(str);
	resetColor();
}

void Printer::print(string str)
{
	cout << str << endl;
}

void Printer::print(string str, Color color)
{
	setTextColor(color);
	print(str);
	resetColor();
}

void Printer::newLine()
{
	print("");
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
	if (!player)
	{
		debug("PlayerState is not set on Printer.");
	}
	printStats(player->mainStats());
}

void Printer::printCombatStats()
{
	if (!player)
	{
		debug("PlayerState is not set on Printer.");
	}
	printStats(player->combatStats());
}

void Printer::printAllStats()
{
	if (!player)
	{
		debug("PlayerState is not set on Printer.");
	}
	printStats(player->allStats());
}

void Printer::setTextColor(Color color)
{
	switch (color)
	{
	case Color::red:
		cout << "\033[31m";
		return;
	case Color::yellow:
		cout << "\033[33m";
		return;
	case Color::green:
		cout << "\033[32m";
		return;
	case Color::cyan:
		cout << "\033[36m";
		return;
	case Color::blue:
		cout << "\033[34m";
		return;
	case Color::magenta:
		cout << "\033[35m";
		return;
	case Color::black:
		cout << "\033[30m";
		return;
	}
	// light variations:
	// red 91, yellow 93, green 92, cyan 96, blue 94, magenta 95, black 90
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