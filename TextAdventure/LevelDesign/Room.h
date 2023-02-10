#pragma once
#include <string>
#include <memory>
#include <vector>
using std::shared_ptr;
using std::string;
using std::vector;

class GameObject;

class Room {
public:
	Room(string t_name);
	int GetId() const;
	string getName() const;
	string enter();

	void setIntro(string t_intro);

protected:
	int id;
	static int nextId;
	string name; // name of room
	bool hasVisited = false;

	string intro; // printed on first entry
	string reIntro; // printed on re-entry
	string details; // printed after looking around
	string extraDetails; // chance to print after looking around (with hints)
	vector<GameObject*> objects; // interactable object
	//vector<Room*> connectedRooms; // rooms you can go to
};
