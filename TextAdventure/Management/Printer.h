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
	Printer(const shared_ptr<PlayerState> t_player);
	void setPlayerState(const shared_ptr<PlayerState> t_player);

	void prompt() const;
	void print(string str) const;
	void print(string str, TextColor color) const;
	void newLine() const;
	void type(string str) const;
	void type(string str, TextColor color) const;
	void typeByLine(string str) const;
	void typeByLine(string str, TextColor color) const;

	void printMainStats() const;
	void printCombatStats() const;
	void printAllStats() const;

	void resetColor() const;

	bool debugMode = true;
	void debug(DebugType type, string str) const;
	void debug(DebugType type, string message, int intVal) const;

private:
	shared_ptr<PlayerState> player;

	std::array<string, 10> prompts = { "What would you like to do?", "What's the plan now?",
		"How do you want to proceed?", "Your next steps?", "What are you doing next?",
		"...and what are you gonna do about it?", "What do you want to do?", "What now?",
		"What are you doing now?", "Your next move?"
	};

	void typeText(string str, int msAfterChar, int msAfterWord, int msAfterLine) const;
	void printStats(string stats) const;
	void setTextColor(TextColor color) const;
};
