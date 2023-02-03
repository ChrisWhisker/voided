#pragma once
#include <memory>
#include <string>
using std::shared_ptr;
using std::string;

class PlayerState
{
public:
	static shared_ptr<PlayerState> getInstance();

	string mainStats();
	string combatStats();
	string allStats();

private:
	PlayerState();
	static shared_ptr<PlayerState> instance;

	string name;
	int health;
	int oxygen;
	int resistance;
	int attackStrength;
	int speed;
	int level;

	const string SPACE = "    ";
};
