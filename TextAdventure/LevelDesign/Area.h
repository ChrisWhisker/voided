#pragma once
#include "Graph.h"
#include <memory>
using std::shared_ptr;

class Room;

class Area {
public:
	Area();
	void enter();
	void enter(const shared_ptr<Room> entrance);

protected:
	vector<shared_ptr<Room>> rooms;
	std::unique_ptr<Graph> roomGraph;
};
