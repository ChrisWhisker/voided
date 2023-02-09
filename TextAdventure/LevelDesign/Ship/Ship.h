#pragma once
#include "../Area.h"
#include "../../Management/Printing/Logger.h"

class Ship : public Area {
public:
	Ship();
private:
	Logger log = Logger("Ship");
};
