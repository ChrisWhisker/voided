#pragma once
#include "../Timer.h"
#include <functional>
#include <memory>
#include <string>
#include <vector>
using std::function;
using std::shared_ptr;
using std::string;
using std::vector;

class PlayerState;
class Printer;

class Clock {
public:
	Clock(shared_ptr<PlayerState> t_player, shared_ptr<Printer> t_printer);

	bool tick();
	int getGameTime();
	void startTimer(function<bool(string)> func, string arg1, int length);

private:
	shared_ptr<PlayerState> player;
	shared_ptr<Printer> printer;
	int gameTime;
	vector<Timer> timers;
};
