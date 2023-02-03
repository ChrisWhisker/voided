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
	for (char c : str)
	{
		cout << c;
		if (c == ' ')
		{
			sleep_for(milliseconds(30));
		}
		else
		{
			sleep_for(milliseconds(3));
		}
	}
	sleep_for(milliseconds(200));
}

void Printer::printByLine(string str)
{
	for (char c : str)
	{
		cout << c;
		if (c == '\n')
		{
			sleep_for(milliseconds(200));
		}
	}
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
