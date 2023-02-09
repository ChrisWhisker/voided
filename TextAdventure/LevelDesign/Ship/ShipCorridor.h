#pragma once
#include "../Room.h"

class ShipCorridor : public Room {
public:
	ShipCorridor();
	void enter() const override;
};
