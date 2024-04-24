#pragma once
#include "GameObject.h"

// An item is any GameObject that can be picked up
class Item : public GameObject
{
public:
    string pickUp() const;
    string drop() const;
    string throwAt(string target) const;
};
