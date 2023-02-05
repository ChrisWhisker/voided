#include "Clock.h"
#include "PlayerState.h"
#include "Printer.h"

Clock::Clock(PlayerState* ps, Printer* prtr) : player(ps), printer(prtr)
{
	gameTime = 0;
}

bool Clock::tick()
{
	bool success = true;
	gameTime++;
	printer->debug("gameTime is: " + gameTime);
	player->addHealth(-3);

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