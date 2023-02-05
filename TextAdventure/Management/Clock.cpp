#include "Clock.h"
#include "PlayerState.h"
#include "Printer.h"

Clock::Clock(shared_ptr<PlayerState> ps, shared_ptr<Printer> prtr) : player(ps), printer(prtr)
{
	gameTime = 0;
}

bool Clock::tick()
{
	bool success = true;
	gameTime++;
	printer->debug(DebugType::log, "gameTime is: " + std::to_string(gameTime));
	player->addHealth(-3);

	for (auto timer : timers)
	{
		printer->debug(DebugType::log, "Timer will call function at gameTime of: " + std::to_string(timer.second));

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
	printer->debug(DebugType::log, "success?: " + std::to_string(success));
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