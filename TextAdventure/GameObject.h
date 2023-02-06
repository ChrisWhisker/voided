#pragma once
#include <string>
#include <vector>
using std::string;

class GameObject {
public:
	std::vector<string> names = { "name", "othername", "otherOtherName" };
	string inspect();
	string use(); // use it for its main purpose
};
