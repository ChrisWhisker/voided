#pragma once
#include <array>
#include <string>
using std::string;

class GameObject
{
public:
	std::array<string, 3> names = { "name", "othername", "otherOtherName" };
	string inspect();
	string use(); // use it for its main purpose
};
