#pragma once
#include "ListHead.h"
#include "List.h"
class CircularlyList : public List
{
public:
	CircularlyList(int (*compare)(void* argu1, void* argu2));
	virtual ~CircularlyList();
	void  traverse(void (*visit)(void* argu), int fromWhere);
	bool  remove(void* argu);
private:
	//ListHead* list;
	bool search(void* argu, SingleListNode** Ppre, SingleListNode** Ploc);
	bool addNode(void* argu, SingleListNode* Ppre);
	void linkRearToFront();
};

