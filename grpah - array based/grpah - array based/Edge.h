#pragma once
class Edge
{
public :
	void *fromVertex, *toVertex;
	int weight;
	Edge(void* fromVertex, void* toVertex, int weight);
};

