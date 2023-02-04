#include "Clock.h"
#include <iostream>  // TODO remove
using std::cout; // TODO remove remove
using std::endl; // remove

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

bool Clock::tick()
{
	bool success = true;
	gameTime++;
	//cout << endl << endl << "gameTime is: " << gameTime << endl << endl;

	for (auto timer : timers)
	{
		//cout << endl << endl << "time of detonation: " << timer.second << endl << endl;
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