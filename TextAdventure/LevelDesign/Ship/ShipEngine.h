#pragma once
#include "../Room.h"

class ShipEngine : public Room {
public:
	ShipEngine();
	void enter() const override;
};
