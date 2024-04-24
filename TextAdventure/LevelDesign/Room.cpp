#include "Room.h"
#include "../Management/Printing/Printer.h"

int Room::nextId = 0;

Room::Room(string t_name) : id(nextId++), name(t_name)
{
}

int Room::GetId() const
{
    return id;
}

string Room::getName() const
{
    return name;
}

string Room::enter()
{
    if (!hasVisited)
    {
        hasVisited = true;
        return intro;
    }

    return reEntry;
}

void Room::setIntro(string t_intro)
{
    intro = t_intro;
}

void Room::setReEntry(string t_reEntry)
{
}

void Room::setLookAround(string t_lookAround)
{
}

void Room::setExtraDetails(string t_extraDetails)
{
}
