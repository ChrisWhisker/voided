#pragma once
//#include <memory>
#include <string>
//using std::shared_ptr;
using std::string;

class Printer;

class PlayerState
{
public:
	PlayerState(Printer* prtr);

	string mainStats();
	string combatStats();
	string allStats();

	int addHealth(int healthToAdd);

private:
	Printer* printer;

	string name;
	int health;
	int oxygen;
	int resistance;
	int attackStrength;
	int speed;
	int level;

	const string SPACE = "    ";
};
