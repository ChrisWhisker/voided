#pragma once
#include <string>
#include <memory>
#include <vector>
using std::shared_ptr;
using std::string;
using std::vector;

class GameObject;

class Room
{
public:
    Room(string t_name);
    int GetId() const;
    string getName() const;
    string enter();

    void setIntro(string t_intro);
    void setReEntry(string t_reEntry);
    void setLookAround(string t_lookAround);
    void setExtraDetails(string t_extraDetails);
    void addGameObject(shared_ptr<GameObject> newObject);

protected:
    int id;
    static int nextId;
    string name; // name of room
    bool hasVisited = false;

    string intro; // first impression on initial entry
    string reEntry; // printed on re-entry
    string lookAround; // printed after looking around
    string extraDetails; // chance to print after looking around (with hints)
    vector<shared_ptr<GameObject>> objects; // interactable object
    //vector<Room*> connectedRooms; // rooms you can go to
};
