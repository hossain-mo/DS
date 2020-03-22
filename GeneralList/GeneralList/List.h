#pragma once
#include "ListNode.h"
#include "ListHead.h"
class List
{
public:
	List(int (* compare)(void* argu1, void* argu2));
	virtual ~List();
	bool insert(void* argu);
	void* front();
	void* rear();
	bool  empty();
	bool  full();
	int count();
private:
	ListHead* list;
	bool search(void* argu, ListNode** Ppre, ListNode** Ploc);
	bool addNode(void* argu, ListNode* Ppre);
};

