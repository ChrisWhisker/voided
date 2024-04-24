#pragma once
#include <memory>
#include <vector>
using std::shared_ptr;
using std::vector;

class Room;

class Graph
{
public:
    Graph(int t_nodeCount);
    int getNumNodes() const;
    void addEdge(const shared_ptr<Room> nodeA, const shared_ptr<Room> nodeB);
    bool hasEdge(const shared_ptr<Room> nodeA, const shared_ptr<Room> nodeB) const;
    const vector<shared_ptr<Room>> getAdjacents(const shared_ptr<Room> node) const;

private:
    int nodeCount;
    vector<vector<shared_ptr<Room>>> adjacencyList;
};
