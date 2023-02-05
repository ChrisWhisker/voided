#pragma once
#include <functional>
#include <map>
#include <memory>
#include <string>
#include <vector>
using std::function;
using std::shared_ptr;
using std::string;
using std::vector;

class PlayerState;
class Printer;

class Clock
{
public:
	Clock(PlayerState* ps, Printer* printer);

	bool tick();
	int getGameTime();
	void startTimer(function<bool(string)> func, int length);

private:
	PlayerState* player;
	Printer* printer;

	int gameTime;

	// needed in order to pass functions as parameters
	struct CompareFunction
	{
		bool operator()(const function<bool(string)>& f1, const function<bool(string)>& f2) const
		{
			return &f1 < &f2;
		}
	};

	std::map<function<bool(string)>, int, CompareFunction> timers;
};
