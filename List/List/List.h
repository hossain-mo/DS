#pragma once
#include "Node.h"
class List
{
public:
	List();
	virtual ~List();
	bool search(Node **Ppre, );
private:
	int count;
	Node* head;
	Node* rear;
	int (*compare)(void* argu1, void* argu2);
};

