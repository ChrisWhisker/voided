#pragma once
#include "Area.h"
#include "../Management/Printing/Logger.h"

class Ship : public Area {
public:
	Ship(shared_ptr<Printer> t_printer);
	using Area::enter;

	void enter() override;
	void enter(const shared_ptr<Room> entrance) override;

private:
	shared_ptr<Printer> printer;
	Logger log = Logger("Ship");

	vector<shared_ptr<Room>> rooms;
	std::unique_ptr<Graph> roomGraph;
};
