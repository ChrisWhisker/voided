#pragma once
#include <memory>
#include <string>
using std::shared_ptr;
using std::string;

class Printer;

class PlayerState
{
public:
    PlayerState(const shared_ptr<Printer> t_printer);

    string mainStats() const;
    string combatStats() const;
    string allStats() const;

    int addHealth(int healthToAdd);

private:
    shared_ptr<Printer> printer;

    string name;
    int health;
    int oxygen;
    int resistance;
    int attackStrength;
    int speed;
    int level;

    const string SPACE = "    ";
};
