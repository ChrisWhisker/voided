#pragma once
#include <string>
#include <vector>
using std::string;
using std::vector;

class GameObject;

class Room {
public:
	Room();
	int GetId() const;
	string getName() const;
	virtual void enter() const;

protected:
	int id;
	string name; // name of room
	string intro; // printed on first entry
	string reIntro; // printed on re-entry
	string details; // printed after looking around
	string extraDetails; // chance to print after looking around (with hints)
	vector<GameObject*> objects; // interactable object
	//vector<Room*> connectedRooms; // rooms you can go to

private:
	static int nextId;
};
