#include "vertex.h"
#include <iostream>
vertex::vertex(void* dataPtr) {
	this->data = dataPtr;
	this->indegree = 0;
	this->outdegree = 0;
	this->processed = 0;
	this->next = NULL;
	this->pArc = NULL;
}
