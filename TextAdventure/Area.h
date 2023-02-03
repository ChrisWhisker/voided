#pragma once
#include "Room.h";

class Area
{
public:
	Area() {}
	virtual void Enter(Room room) = 0;
};
