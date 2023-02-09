#include "Room.h"

int Room::nextId = 0;

Room::Room() : id(nextId++) {}

int Room::GetId() const {
	return id;
}

string Room::getName() const {
	return name;
}

void Room::enter() const {
	// if first time entering, print intro
	// otherwise print reIntro
}
