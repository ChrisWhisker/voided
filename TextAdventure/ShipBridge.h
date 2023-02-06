#pragma once
#include "Room.h"

class ShipBridge : public Room {
public:
	ShipBridge();
	void enter() override;
};
