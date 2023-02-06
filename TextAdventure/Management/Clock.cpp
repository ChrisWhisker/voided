#include "Clock.h"
#include "PlayerState.h"
#include "Printer.h"

Clock::Clock(shared_ptr<PlayerState> ps, shared_ptr<Printer> prtr) : player(ps), printer(prtr) {
	gameTime = 0;
}

bool Clock::tick() {
	bool success = true;
	gameTime++;
	printer->debug(DebugType::log, "gameTime is: " + std::to_string(gameTime));
	player->addHealth(-3);

	vector<Timer> completedTimers;

	for (auto timer : timers) {
		printer->debug(DebugType::log, "Timer will call function at gameTime of: " + std::to_string(timer.getDeadline()));

		if (gameTime >= timer.getDeadline()) {
			if (timer.callFunction()) // call function
			{
				completedTimers.push_back(timer);
			}
			else {
				success = false;
			}
		}
	}

	// remove completed timers
	for (const auto& completedTimer : completedTimers) {
		timers.erase(std::remove(timers.begin(), timers.end(), completedTimer), timers.end());
	}

	return success;
}

int Clock::getGameTime() {
	return gameTime;
}

void Clock::startTimer(function<bool(string)> func, string arg1, int length) {
	Timer timer(func, arg1, gameTime + length);

	timers.push_back(timer);
}
