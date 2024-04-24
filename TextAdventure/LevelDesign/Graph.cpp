#include "Graph.h"
#include "Room.h"
#include <algorithm>

Graph::Graph(const int t_nodeCount) : nodeCount(t_nodeCount)
{
    adjacencyList.resize(t_nodeCount);
}

int Graph::getNumNodes() const
{
    return nodeCount;
}

void Graph::addEdge(const shared_ptr<Room> nodeA, const shared_ptr<Room> nodeB)
{
    if (hasEdge(nodeA, nodeB))
    {
        return;
    }

    adjacencyList[nodeA->GetId()].push_back(nodeB);
    adjacencyList[nodeB->GetId()].push_back(nodeA);
}

bool Graph::hasEdge(const shared_ptr<Room> nodeA, const shared_ptr<Room> nodeB) const
{
    vector<shared_ptr<Room>> adjacents = getAdjacents(nodeA);
    return std::any_of(adjacents.begin(), adjacents.end(), [&nodeB](const shared_ptr<Room> x)
    {
        return x->GetId() == nodeB->GetId();
    });
}

const vector<shared_ptr<Room>> Graph::getAdjacents(const shared_ptr<Room> node) const
{
    return adjacencyList[node->GetId()];
}
