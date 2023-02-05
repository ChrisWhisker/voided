#pragma once
#include <array>
#include <memory>
#include <string>
using std::shared_ptr;
using std::string;

class PlayerState;
enum class Color { red, yellow, green, cyan, blue, magenta, black };

class Printer
{
public:
	Printer(shared_ptr<PlayerState> plr);
	void setPlayerState(shared_ptr<PlayerState> plr);
	
	void prompt();
	void type(string str);
	void typeByLine(string str);
	void print(string str);
	void type(string str, Color color);
	void typeByLine(string str, Color color);
	void print(string str, Color color);
	void newLine();

	void printMainStats();
	void printCombatStats();
	void printAllStats();

	void resetColor();

	bool debugMode = false;
	void debug(string str);

private:
	shared_ptr<PlayerState> player;

	std::array<string, 10> prompts = { "What would you like to do?", "What's the plan now?",
		"How do you want to proceed?", "Your next steps?", "What are you doing next?",
		"...and what are you gonna do about it?", "What do you want to do?", "What now?",
		"What are you doing now?", "Your next move?"
	};
	
	void typeText(string str, int msAfterChar, int msAfterWord, int msAfterLine);
	void printStats(string stats);
	void setTextColor(Color color);
};
