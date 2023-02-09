#include "Graph.h"
#include "Room.h"
#include <algorithm>

Graph::Graph(int t_nodeCount) : nodeCount(t_nodeCount) {
	adjacencyList.resize(t_nodeCount);
}

void Graph::AddEdge(const shared_ptr<Room> nodeA, const shared_ptr<Room> nodeB) {
	if (HasEdge(nodeA, nodeB)) {
		return;
	}

	adjacencyList[nodeA->GetId()].push_back(nodeB);
	adjacencyList[nodeB->GetId()].push_back(nodeA);
}

const vector<shared_ptr<Room>> Graph::GetAdjacents(const shared_ptr<Room> node) const {
	return adjacencyList[node->GetId()];
}

int Graph::GetNumNodes() const {
	return nodeCount;
}

bool Graph::HasEdge(const shared_ptr<Room> nodeA, const shared_ptr<Room> nodeB) const {
	vector<shared_ptr<Room>> adjacents = GetAdjacents(nodeA);
	return std::any_of(adjacents.begin(), adjacents.end(), [&nodeB](const shared_ptr<Room> x) {
		return x->GetId() == nodeB->GetId();
		});
}
