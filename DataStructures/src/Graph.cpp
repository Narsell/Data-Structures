#include <iostream>
#include "Graph.h"

const bool Graph::AddVertex(const std::string& vertex)
{
	if (!adjacencyList.contains(vertex)) {
		adjacencyList[vertex];
		return true;
	}
	return false;
}

const bool Graph::AddEdge(const std::string& vertex1, const std::string& vertex2)
{
	if (adjacencyList.contains(vertex1) && adjacencyList.contains(vertex2)) {
		adjacencyList.at(vertex1).insert(vertex2);
		adjacencyList.at(vertex2).insert(vertex1);
		return true;
	}
	return false;
}

const bool Graph::RemoveEdge(const std::string& vertex1, const std::string& vertex2)
{
	if (adjacencyList.contains(vertex1) && 
		adjacencyList.contains(vertex2) &&
		adjacencyList.at(vertex1).contains(vertex2) &&
		adjacencyList.at(vertex2).contains(vertex1)) 
	{
		adjacencyList.at(vertex1).erase(vertex2);
		adjacencyList.at(vertex2).erase(vertex1);
		return true;
	}
	return false;
}

const bool Graph::RemoveVertex(const std::string& vertex)
{
	if (!adjacencyList.contains(vertex)) return false;

	for (const std::string& connectedVertex : adjacencyList.at(vertex)) {
		adjacencyList.at(connectedVertex).erase(vertex);
	}
	adjacencyList.erase(vertex);

	return true;
}

void Graph::Print()
{
	for (const auto& [name, connections] : adjacencyList) {
		std::cout << name << ": [ ";
		for (const std::string& connection : connections) {
			std::cout << connection << " ";
		}
		std::cout << "]\n";
	}
}
