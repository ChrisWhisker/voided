#pragma once
#include <memory>
#include <vector>
using std::shared_ptr;
using std::vector;

class Room;

class Graph {
public:
	Graph(int t_nodeCount);
	void AddEdge(shared_ptr<Room> nodeA, shared_ptr<Room> nodeB);
	const vector<shared_ptr<Room>> GetAdjacents(const shared_ptr<Room> node) const;
	int GetNumNodes() const;
	bool HasEdge(const shared_ptr<Room> nodeA, const shared_ptr<Room> nodeB) const;

private:
	int nodeCount;
	vector<vector<shared_ptr<Room>>> adjacencyList;
};
