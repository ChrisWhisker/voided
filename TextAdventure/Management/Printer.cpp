#include "Printer.h"
#include "PlayerState.h"
#include <chrono>
#include <iostream>
#include <thread>
using std::chrono::milliseconds;
using std::cout;
using std::endl;
using std::this_thread::sleep_for;
using std::to_string;

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
	setTextColor(TextColor::green);
	cout << "> ";
}

void Printer::print(string str)
{
	cout << str << endl;
}

void Printer::print(string str, TextColor color)
{
	setTextColor(color);
	print(str);
	resetColor();
}

void Printer::newLine()
{
	print("");
}

void Printer::type(string str)
{
	if (debugMode)
	{
		print(str);
		return;
	}

	typeText(str, 1, 30, 200);
	cout << endl;
}

void Printer::type(string str, TextColor color)
{
	setTextColor(color);
	type(str);
	resetColor();
}

void Printer::typeByLine(string str)
{
	if (debugMode)
	{
		print(str);
		return;
	}

	typeText(str, 1, 0, 200);
	cout << endl;
}

void Printer::typeByLine(string str, TextColor color)
{
	setTextColor(color);
	typeByLine(str);
	resetColor();
}

void Printer::printMainStats()
{
	if (!player)
	{
		debug(DebugType::error, "PlayerState is not set on Printer.");
		return;
	}
	printStats(player->mainStats());
}

void Printer::printCombatStats()
{
	if (!player)
	{
		debug(DebugType::error, "PlayerState is not set on Printer.");
		return;
	}
	printStats(player->combatStats());
}

void Printer::printAllStats()
{
	if (!player)
	{
		debug(DebugType::error, "PlayerState is not set on Printer.");
		return;
	}
	printStats(player->allStats());
}

void Printer::resetColor()
{
	cout << "\033[0m";
}

void Printer::debug(DebugType type, string message)
{
	if (debugMode)
	{
		setTextColor(TextColor::black);
		cout << "\033[" << to_string((int)type) << "m";

		switch (type)
		{
		case DebugType::log:
			cout << "Log";
			break;
		case DebugType::warning:
			cout << "Warning";
			break;
		case DebugType::error:
			cout << "Error";
			break;
		default:
			cout << "Unspecified";
			break;
		}
		resetColor();
		cout << "\t" << message << endl;
	}
}

void Printer::debug(DebugType type, string message, int intVal)
{
	debug(type, to_string(intVal));
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

void Printer::printStats(string stats)
{
	cout << "\n==========\n" << stats << endl;
}

void Printer::setTextColor(TextColor color)
{
	cout << "\033[" + to_string((int)color) + "m";
	// light variations:
	// red 91, yellow 93, green 92, cyan 96, blue 94, magenta 95, black 90
}