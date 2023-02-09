#include "Ship.h"
#include "../Graph.h"
#include "ShipBridge.h"
#include "ShipCargoBay.h"
#include "ShipCorridor.h"
#include "ShipEngine.h"
#include "ShipOutside.h"
#include "ShipQuarters.h"
using std::make_shared;

Ship::Ship() {
	auto bridge = make_shared<ShipBridge>();
	auto corridor = make_shared<ShipCorridor>();
	auto engine = make_shared<ShipEngine>();
	auto cargoBay = make_shared<ShipCargoBay>();
	auto quarters = make_shared<ShipQuarters>();
	auto outside = make_shared<ShipOutside>();

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

	//log.print("num nodes (should be 6): ", roomGraph->getNumNodes());

	//auto corridorAdjacents = roomGraph->getAdjacents(corridor);
	//log.warning("Printing corridor adjacents:");

	//for (auto adj : corridorAdjacents) {
	//	log.error(adj->getName() + " " + std::to_string(adj->GetId()));
	//}
}
