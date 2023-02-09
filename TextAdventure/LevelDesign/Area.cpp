#include "Area.h"
#include "Room.h"

Area::Area() {
}

void Area::enter() {
	rooms[0]->enter();
}

void Area::enter(const shared_ptr<Room> entrance) {
	entrance->enter();
}
