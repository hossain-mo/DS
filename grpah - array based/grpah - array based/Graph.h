#pragma once
#include <vector>
#include "Vertex.h"
#include "Edge.h"
#include <iostream>
#include <string>
class Graph
{
public:
	std::vector<std::vector<int>> adjacencyMatrix;
	Vertex *vector;
	std::vector<Edge *> edges;
	Graph(Vertex* vector);
	void addEdge(void* fromVertex, void* toVertex ,int weight = 1);
	void displayGraph();
	void traverse(void visit(void* argu), std::string traverseType);
	void breadthFirstTraversal(void visit(void* argu));
	void depthFirstTraversal(void visit(void* argu));
	void minimumSpanningTree(void visit(void* argu));
	void shortestPath(void visit(void* argu));
	void prime(void visit(void* argu));
	void kruskal(void visit(void* argu), int compareEdges(const Edge* firstEdge, const Edge* secondEdge));
};

