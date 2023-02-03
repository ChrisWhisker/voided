#include "PlayerState.h"
#include <iostream>
using std::make_shared;
using std::to_string;

shared_ptr<PlayerState> PlayerState::instance = nullptr;

PlayerState::PlayerState()
{
	health = 100;
	oxygen = 100;
	resistance = 5;
	attackStrength = 5;
	speed = 5;
	level = 1;
}

shared_ptr<PlayerState> PlayerState::getInstance()
{
	if (!instance)
	{
		return make_shared<PlayerState>(PlayerState());
	}
	return instance;
}

string PlayerState::mainStats()
{
	return "=====\nHealth: " + to_string(health) + SPACE
		+ "Oxygen Level: " + to_string(oxygen) + SPACE
		+ "Player Level: " + to_string(level);
}

string PlayerState::combatStats()
{
	return "=====\nHealth: " + to_string(health) + SPACE
		+ "Damage Resistance: " + to_string(oxygen) + SPACE
		+ "Attack Strength: " + to_string(oxygen) + SPACE
		+ "Speed: " + to_string(speed) + SPACE;
}

string PlayerState::allStats()
{
	return "=====\nHealth: " + to_string(health) + SPACE
		+ "Oxygen Level: " + to_string(oxygen) + SPACE
		+ "Damage Resistance: " + to_string(oxygen) + SPACE
		+ "Attack Strength: " + to_string(oxygen) + SPACE
		+ "Speed: " + to_string(speed) + SPACE
		+ "Level: " + to_string(level);
}