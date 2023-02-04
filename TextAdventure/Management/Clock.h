#pragma once
#include <string>
#include <vector>
using std::shared_ptr;
using std::string;
using std::vector;

class Clock
{
public:
	static shared_ptr<Clock> getInstance();

	vector<string> tick();
	int getGameTime();

private:
	static shared_ptr<Clock> instance;
	Clock();

	int gameTime;
};
