#pragma once
#include <vector>
class Vertex
{
public:
	std::vector <void*> vertexVector;
	Vertex();
	int find(void* data);
};

