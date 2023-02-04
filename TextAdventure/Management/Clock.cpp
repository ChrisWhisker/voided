#include "Clock.h"

shared_ptr<Clock> Clock::instance = nullptr;

shared_ptr<Clock> Clock::getInstance()
{
	if (!instance)
	{
		instance = std::make_shared<Clock>(Clock());
	}
	return instance;
}

Clock::Clock()
{
	gameTime = 0;
}

vector<string> Clock::tick()
{
	gameTime++;
	vector<string> finishedTimers;

	return finishedTimers;
}

int Clock::getGameTime()
{
	return gameTime;
}
