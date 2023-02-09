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
	roomGraph->AddEdge(bridge, corridor);

	roomGraph->AddEdge(corridor, engine);
	roomGraph->AddEdge(corridor, cargoBay);
	roomGraph->AddEdge(corridor, quarters);

	roomGraph->AddEdge(cargoBay, outside);

	roomGraph->AddEdge(quarters, outside);

	//cout << "num nodes (should be 6): " << roomGraph->GetNumNodes() << endl;
	//auto corridorAdjacents = roomGraph->GetAdjacents(corridor);
	//cout << "Printing corridor adjacents: " << endl;

	//for (auto adj : corridorAdjacents) {
	//	cout << adj->getName() << " " << adj->GetId() << endl;
	//}
}
