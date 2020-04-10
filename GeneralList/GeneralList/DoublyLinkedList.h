#pragma once
#include "ListHead.h"
#include "List.h"
#include "DoubleListNode.h"
class DoublyLinkedList : public List
{
public:
	DoublyLinkedList(int (*compare)(void* argu1, void* argu2));
	virtual ~DoublyLinkedList();
	void  traverse(void (*visit)(void* argu), int fromWhere);
	bool  remove(void* argu);
private:
	bool search(void* argu, DoubleListNode** Ppre, DoubleListNode** Ploc);
	bool addNode(void* argu, DoubleListNode* Ppre);
};

