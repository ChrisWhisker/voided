#pragma once
#include "../Room.h"

class ShipOutside : public Room {
public:
	ShipOutside();
	void enter() const override;
};
