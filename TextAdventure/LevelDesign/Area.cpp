#include "Area.h"
#include "../Management/Printing/Printer.h"
#include "Room.h"

Area::Area(shared_ptr<Printer> t_printer) : printer(t_printer) {
	log.print("in constructor");
}

void Area::enter() {
	log.print("in enter()");
	printer->type(rooms[0]->enter());
}

void Area::enter(const shared_ptr<Room> entrance) {
	log.print("in enter(shared_ptr<Room>)");
	printer->type(entrance->enter());
}
