#pragma once
#include <array>
#include <string>
using std::string;

class GameObject
{
public:
	std::array<string, 3> names = { "name", "othername", "otherOtherName" };

	string inspect();
	void interact();

private:
};
