#pragma once
class arc
{
public:

	void* dest;
	arc* next;
	int weight;
	arc(int weight = 1);
};

