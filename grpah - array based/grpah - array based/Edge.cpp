#include "Edge.h"
Edge::Edge(void* fromVertex, void* toVertex, int weight) {
	this->fromVertex = fromVertex;
	this->toVertex   = toVertex;
	this->weight     = weight;
}
