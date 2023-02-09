#include "Item.h"

string Item::pickUp() const {
	return "You pick it up.";
}

string Item::drop() const {
	return "You drop it on the ground.";
}

string Item::throwAt(string target) const {
	return "You throw the " + names[0] + " at the " + target;
}
