#pragma once
#include "arc.h"
class vertex
{
public:
	void* data;
	vertex* next;
	int indegree;
	int outdegree;
	int processed;// 0 not processed , 1 in stack , 2 processed
	arc* pArc;
	vertex(void* dataPtr);
};

