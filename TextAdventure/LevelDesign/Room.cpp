#include "Room.h"

int Room::nextId = 0;

Room::Room() : id(nextId++) {}

int Room::GetId() const {
	return id;
}

string Room::getName() {
	return name;
}
