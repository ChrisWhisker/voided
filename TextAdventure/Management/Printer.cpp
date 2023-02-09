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

Printer::Printer(const shared_ptr<PlayerState> t_player) : player(t_player) {
	srand((unsigned int)time(0));
}

void Printer::setPlayerState(const shared_ptr<PlayerState> t_player) {
	player = t_player;
}

void Printer::prompt() const {
	setTextColor(TextColor::green);
	cout << "> ";
}

void Printer::print(string str) const {
	cout << str << endl;
}

void Printer::print(string str, TextColor color) const {
	setTextColor(color);
	print(str);
	resetColor();
}

void Printer::newLine() const {
	print("");
}

void Printer::type(string str) const {
	if (debugMode) {
		print(str);
		return;
	}

	typeText(str, 1, 30, 200);
	cout << endl;
}

void Printer::type(string str, TextColor color) const {
	setTextColor(color);
	type(str);
	resetColor();
}

void Printer::typeByLine(string str) const {
	if (debugMode) {
		print(str);
		return;
	}

	typeText(str, 1, 0, 200);
	cout << endl;
}

void Printer::typeByLine(string str, TextColor color) const {
	setTextColor(color);
	typeByLine(str);
	resetColor();
}

void Printer::printMainStats() const {
	if (!player) {
		debug(DebugType::error, "PlayerState is not set on Printer.");
		return;
	}
	printStats(player->mainStats());
}

void Printer::printCombatStats() const {
	if (!player) {
		debug(DebugType::error, "PlayerState is not set on Printer.");
		return;
	}
	printStats(player->combatStats());
}

void Printer::printAllStats() const {
	if (!player) {
		debug(DebugType::error, "PlayerState is not set on Printer.");
		return;
	}
	printStats(player->allStats());
}

void Printer::resetColor() const {
	cout << "\033[0m";
}

void Printer::debug(DebugType type, string message) const {
	if (debugMode) {
		setTextColor(TextColor::black);
		cout << "\033[" << to_string((int)type) << "m";

		switch (type) {
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

void Printer::debug(DebugType type, string message, int intVal) const {
	debug(type, to_string(intVal));
}

void Printer::typeText(string str, int msAfterChar, int msAfterWord, int msAfterLine) const {
	for (char c : str) {
		cout << c;
		if (c == ' ') {
			sleep_for(milliseconds(msAfterWord));
		}
		else if (c == '\n') {
			sleep_for(milliseconds(msAfterLine));
		}
		else {
			sleep_for(milliseconds(msAfterChar));
		}
	}
	cout << endl;
}

void Printer::printStats(string stats) const {
	cout << "==========\n" << stats << endl;
}

void Printer::setTextColor(TextColor color) const {
	cout << "\033[" + to_string((int)color) + "m";
	// light variations:
	// red 91, yellow 93, green 92, cyan 96, blue 94, magenta 95, black 90
}
