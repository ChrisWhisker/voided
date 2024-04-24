#pragma once
#include <string>
#include <vector>
using std::string;

// An object in the game that can be inspected and interacted with
class GameObject {
public:
	std::vector<string> names = { "name", "othername", "otherOtherName" };
	virtual string inspect() const;
	virtual string use() const; // use it for its main purpose
};
