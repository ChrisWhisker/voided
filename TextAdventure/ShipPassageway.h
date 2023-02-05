#pragma once
#include "Room.h"
class ShipPassageway : public Room
{
public:
	ShipPassageway();
	void enter() override;
};
