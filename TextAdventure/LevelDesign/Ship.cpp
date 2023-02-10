#include "Ship.h"
#include "../Management/Printing/Printer.h"
#include "Graph.h"
#include "Room.h"
using std::make_shared;

Ship::Ship(shared_ptr<Printer> t_printer) : Area(t_printer), printer(t_printer) {
	auto bridge = make_shared<Room>("Bridge");
	auto corridor = make_shared<Room>("Passageway");
	auto engine = make_shared<Room>("Engine Room");
	auto cargoBay = make_shared<Room>("Cargo Bay");
	auto quarters = make_shared<Room>("Quarters");
	auto outside = make_shared<Room>("Outside");

	rooms = {
		bridge,
		corridor,
		engine,
		cargoBay,
		quarters,
		outside
	};

	roomGraph = std::make_unique<Graph>((int)rooms.size());
	roomGraph->addEdge(bridge, corridor);
	roomGraph->addEdge(corridor, engine);
	roomGraph->addEdge(corridor, cargoBay);
	roomGraph->addEdge(corridor, quarters);
	roomGraph->addEdge(cargoBay, outside);
	roomGraph->addEdge(quarters, outside);

	bridge->setIntro("You awaken with a throbbing headache. Slowly opening your eyes, you see you're alone, still "
		"buckled into the pilot's seat of a star frighter. Looking around the bridge, you see the captain and "
		"first mate's bodies slumped against the bulkheads. The last thing you remember is losing control of the ship and "
		"preparing for a crash landing on an unknown planet. The blaring klaxon down the passageway barely drowns out the "
		"ringing in your ears. A sudden sensation of wetness makes itself known on the side of your head. You need to find "
		"a way to stop the bleeding.");

	//log.print("num nodes (should be 6): ", roomGraph->getNumNodes());
	//auto corridorAdjacents = roomGraph->getAdjacents(corridor);
	//log.print("Printing corridor adjacents:");
	//for (auto adj : corridorAdjacents) {
	//	log.print(adj->getName() + " " + std::to_string(adj->GetId()));
	//}
}

void Ship::enter() {
	printer->type(rooms[0]->enter());
}

void Ship::enter(const shared_ptr<Room> entrance) {
	printer->type(entrance->enter());
}
