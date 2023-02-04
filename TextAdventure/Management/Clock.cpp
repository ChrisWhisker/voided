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
	printer = Printer::getInstance();
	gameTime = 0;
}

bool Clock::tick()
{
	bool success = true;
	gameTime++;
	printer->debug("gameTime is: " + gameTime);

	for (auto timer : timers)
	{
		printer->debug("Timer will call function at gameTime of: " + timer.second);

		if (gameTime >= timer.second)
		{
			if (timer.first("")) // call function
			{
				timers.erase(timer.first);
			}
			else
			{
				success = false;
			}
		}
	}

	return success;
}

int Clock::getGameTime()
{
	return gameTime;
}

void Clock::startTimer(function<bool(string)> func, int length)
{
	timers.insert({ func,  gameTime + length });
}