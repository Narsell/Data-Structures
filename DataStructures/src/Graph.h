#pragma once
#include <unordered_map>
#include <unordered_set>
#include <sstream>

class Graph {

	/**
	 * Graph with bidirectional edges/connections
	 */

public:

	/**
	 * O(1) time complexity.
	 * Adds a vertex.
	 * Returns true if the vertex was added, otherwise if the vertex already existed returns false.
	 */
	const bool AddVertex(const std::string& vertex);

	/**
	 * O(1) time complexity.
	 * Adds an edge, connecting two vertices together.
	 * Returns true if the connection was successful, false otherwise.
	 */
	const bool AddEdge(const std::string& vertex1, const std::string& vertex2);

	/**
	 * O(1) time complexity.
	 * Removes an edge, disconnecting two vertices together.
	 * Returns true if the connection was successful removed, false otherwise.
	 */
	const bool RemoveEdge(const std::string& vertex1, const std::string& vertex2);

	/**
	 * O(1) time complexity. We can make this constant time because edges are bidirectional.
	 * Removes a vertex from the graph.
	 * Returns true if the vertex was removed succesfully, false otherwise.
	 */
	const bool RemoveVertex(const std::string& vertex1);

	void Print();

private:

	std::unordered_map<std::string, std::unordered_set<std::string>> adjacencyList;

};