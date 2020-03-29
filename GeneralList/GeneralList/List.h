#pragma once
#include "SingleListNode.h"
#include "ListHead.h"
class List
{
public:
	List();
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
	virtual bool search(void* argu, SingleListNode** Ppre, SingleListNode** Ploc);
	virtual bool addNode(void* argu, SingleListNode* Ppre);
};

