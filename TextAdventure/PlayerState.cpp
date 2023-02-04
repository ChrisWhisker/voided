#include "PlayerState.h"
#include <algorithm>
#include <iostream>
using std::to_string;

shared_ptr<PlayerState> PlayerState::instance = nullptr;

shared_ptr<PlayerState> PlayerState::getInstance()
{
	if (!instance)
	{
		instance = std::make_shared<PlayerState>(PlayerState());
	}
	return instance;
}

PlayerState::PlayerState()
{
	health = 62;
	oxygen = 100;
	resistance = 5;
	attackStrength = 5;
	speed = 5;
	level = 1;
}

string PlayerState::mainStats()
{
	return "Health: " + to_string(health) + SPACE
		+ "Oxygen Level: " + to_string(oxygen) + SPACE
		+ "Player Level: " + to_string(level);
}

string PlayerState::combatStats()
{
	return "Health: " + to_string(health) + SPACE
		+ "Damage Resistance: " + to_string(oxygen) + SPACE
		+ "Attack Strength: " + to_string(oxygen) + SPACE
		+ "Speed: " + to_string(speed) + SPACE;
}

string PlayerState::allStats()
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
	return healthToAdd;
}
