#pragma once
#include <vector>
#include "Vertex.h"
class Graph
{
public:
	std::vector<std::vector<int>> adjacencyMatrix;
	Vertex *vector;
	Graph(Vertex* vector);
	void addEdge(void* fromVertex, void* toVertex);
	void displayGraph();
};

