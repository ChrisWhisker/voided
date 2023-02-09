#pragma once
#include "../Room.h"

class ShipQuarters : public Room {
public:
	ShipQuarters();
	void enter() override;
};
