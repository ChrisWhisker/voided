#include "Clock.h"
#include "PlayerState.h"

Clock::Clock(const shared_ptr<PlayerState> t_player, const shared_ptr<Printer> t_printer) : player(t_player),
    printer(t_printer)
{
    gameTime = 0;
}

bool Clock::tick()
{
    bool success = true;
    gameTime++;
    log.print("gameTime is: ", gameTime);
    player->addHealth(-3);

    vector<Timer> completedTimers;

    for (auto timer : timers)
    {
        log.print("Timer will call function at gameTime of: ", timer.getDeadline());

        if (gameTime >= timer.getDeadline())
        {
            if (timer.callFunction()) // call function
            {
                completedTimers.push_back(timer);
            }
            else
            {
                success = false;
            }
        }
    }

    // remove completed timers
    for (const auto& completedTimer : completedTimers)
    {
        timers.erase(std::remove(timers.begin(), timers.end(), completedTimer),
                     timers.end());
    }

    return success;
}

int Clock::getGameTime() const
{
    return gameTime;
}

void Clock::startTimer(function<bool(string)> func, string arg1, int length)
{
    Timer timer(func, arg1, gameTime + length);

    timers.push_back(timer);
}
