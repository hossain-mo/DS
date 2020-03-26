#pragma once
#include "ListNode.h"
#include "ListHead.h"
class List
{
public:
	List(int (* compare)(void* argu1, void* argu2));
	virtual ~List();
	bool  insert(void* argu);
	void* front();
	void* rear();
	bool  empty();
	bool  full();
	int   count();
	virtual void  traverse(void (* visit)(void* argu), int fromWhere);
	virtual bool  remove(void* argu);
	void* retrieve(int index);
	bool  search(void* argu);
protected:
	ListHead* list;
	virtual bool search(void* argu, ListNode** Ppre, ListNode** Ploc);
	virtual bool addNode(void* argu, ListNode* Ppre);
};

