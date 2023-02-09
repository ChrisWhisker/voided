#pragma once
#include "../Room.h"

class ShipCargoBay : public Room {
public:
	ShipCargoBay();
	void enter() const override;
};
