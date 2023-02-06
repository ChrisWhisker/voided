#pragma once
#include <array>
#include <memory>
#include <string>
using std::shared_ptr;
using std::string;

class PlayerState;
enum class TextColor {
	black = 30, red = 31, green = 32, yellow = 33,
	blue = 34, magenta = 35, cyan = 36, white = 37
};
enum class DebugType { log = 47, warning = 43, error = 41 };

class Printer {
public:
	Printer(shared_ptr<PlayerState> t_player);
	void setPlayerState(shared_ptr<PlayerState> t_player);

	void prompt();
	void print(string str);
	void print(string str, TextColor color);
	void newLine();
	void type(string str);
	void type(string str, TextColor color);
	void typeByLine(string str);
	void typeByLine(string str, TextColor color);

	void printMainStats();
	void printCombatStats();
	void printAllStats();

	void resetColor();

	bool debugMode = false;
	void debug(DebugType type, string str);
	void debug(DebugType type, string message, int intVal);

private:
	shared_ptr<PlayerState> player;

	std::array<string, 10> prompts = { "What would you like to do?", "What's the plan now?",
		"How do you want to proceed?", "Your next steps?", "What are you doing next?",
		"...and what are you gonna do about it?", "What do you want to do?", "What now?",
		"What are you doing now?", "Your next move?"
	};

	void typeText(string str, int msAfterChar, int msAfterWord, int msAfterLine);
	void printStats(string stats);
	void setTextColor(TextColor color);
};
