#include "PlayerState.h"
#include "Printing/Printer.h"
#include <algorithm>
#include <iostream>
using std::to_string;

PlayerState::PlayerState(shared_ptr<Printer> t_printer) : printer(t_printer)
{
    health = 62;
    oxygen = 100;
    resistance = 5;
    attackStrength = 5;
    speed = 5;
    level = 1;
}

string PlayerState::mainStats() const
{
    return "Health: " + to_string(health) + SPACE
        + "Oxygen Level: " + to_string(oxygen) + SPACE
        + "Player Level: " + to_string(level);
}

string PlayerState::combatStats() const
{
    return "Health: " + to_string(health) + SPACE
        + "Damage Resistance: " + to_string(oxygen) + SPACE
        + "Attack Strength: " + to_string(oxygen) + SPACE
        + "Speed: " + to_string(speed);
}

string PlayerState::allStats() const
{
    return "Health: " + to_string(health) + SPACE
        + "Oxygen Level: " + to_string(oxygen) + SPACE
        + "Damage Resistance: " + to_string(oxygen) + SPACE
        + "Attack Strength: " + to_string(oxygen) + SPACE
        + "Speed: " + to_string(speed) + SPACE
        + "Level: " + to_string(level);
}

int PlayerState::addHealth(int healthToAdd)
{
    healthToAdd = std::clamp(healthToAdd, 0 - health, 100 - health);
    health += healthToAdd;

    if (health <= 0)
    {
        printer->type("You died.");
        exit(0);
    }
    return healthToAdd;
}
