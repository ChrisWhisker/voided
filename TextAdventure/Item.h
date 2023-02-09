#pragma once
#include "GameObject.h"

class Item : public GameObject {
public:
	string pickUp() const;
	string drop() const;
	string throwAt(string target) const;
};
