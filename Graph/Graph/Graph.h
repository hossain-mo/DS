#pragma once
#include "vertex.h"
#include<string>
class Graph
{
private:
	int size;
	vertex* first;
	int (*compare) (void* argu1, void* argu2);
	void (*visit)(void* argu);
	vertex* search(void* dataPtr, vertex*& locPtr);
	void traverse(std::string traverseType);
	void setProcessFlagNotProcessed();
public:
	Graph(int (*compare)(void* argu1, void* argu2), void (*visit)(void* argu));
	void* search(void* dataPtr);
	void insertVertex(void* dataPtr);
	void deleteVertex(void* dataPtr);
	int count();
	bool insertGrapghArc(void* dataFromPtr, void* dataToPtr);
	arc* searchArc(void* dataPtr, arc*& arcLocPtr, bool forInsert);
	bool deleteGrapghArc(void* dataFromPtr, void* dataToPtr);
	void displayVerticesDegrees();
	void breadthFirstTraversal();
	void depthFirstTraversal();
	~Graph();
};

