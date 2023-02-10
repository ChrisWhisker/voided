#pragma once
#include "Graph.h"
#include "../Management/Printing/Logger.h"
#include <memory>
using std::shared_ptr;

class Printer;
class Room;

class Area {
protected:
	Area(shared_ptr<Printer> t_printer); // protected to prevent instantiation
	shared_ptr<Printer> printer;
	Logger log = Logger("Area");

	vector<shared_ptr<Room>> rooms;
	std::unique_ptr<Graph> roomGraph;

	virtual void enter();
	virtual void enter(const shared_ptr<Room> entrance);
};
