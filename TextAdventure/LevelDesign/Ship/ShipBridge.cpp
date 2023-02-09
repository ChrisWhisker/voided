#include "ShipBridge.h"

ShipBridge::ShipBridge() {
	name = "Bridge";
	intro = "You find yourself on the bridge of the ship. The main viewscreen is shattered, preventing you from "
		"getting a view of whatever planet you've crash landed on. The only exit is to the passageway, where you see "
		"flashing red lights and hear a blaring klaxon.";
	details = "Your co-pilot and first mate lie dead against the starboard bulkhead.";
	extraDetails = "Sparks are flying from the console. Looking more closely, you notice the panel has come loose.";
}

void ShipBridge::enter() const {
}
