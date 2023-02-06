#include "Item.h"

string Item::pickUp() {
	return "You pick it up.";
}

string Item::drop() {
	return "You drop it on the ground.";
}

string Item::throwAt(string target) {
	return "You throw the " + names[0] + " at the " + target;
}
