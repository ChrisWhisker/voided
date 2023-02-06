#pragma once
#include "Item.h"
#include <string>
#include <vector>
using std::string;
using std::vector;

class Room {
public:
	virtual void enter() = 0;
	string getName();

protected:
	string name; // name of room
	string intro; // printed on first entry
	string reIntro; // printed on re-entry
	string details; // printed after looking around
	string extraDetails; // chance to print after looking around (with hints)
	vector<GameObject> objects; // interactable object
	vector<Room> connectedRooms; // rooms you can go to
};
