#pragma once
#include "GameObject.h"

class Item : public GameObject
{
public:
	string pickUp();
	string drop();
	string throwAt(string target);
};
