#pragma once
#include "HuffmanNode.h"
#include "ListHead.h"
#include "HuffmanNode.h"
class List
{
public:
	List();
	List(int (*compare)(int* argu1, int* argu2), int (*compareLetter)(void* argu1, void* argu2));
	virtual ~List();
	bool  insert(void* argu, int* freq, HuffmanNode* left, HuffmanNode* right);
	HuffmanNode* front();
	HuffmanNode* rear();
	bool  empty();
	bool  full();
	int   count();
	virtual void  traverse(void (*visit)(void* argu), int fromWhere);
	virtual bool  remove(void* argu);
	void* retrieve(int index);
	bool  search(void* argu);
protected:
	ListHead* list;
	virtual bool search(int* freq, HuffmanNode** Ppre, HuffmanNode** Ploc);
	virtual bool searchByDataPtr(void* argu, HuffmanNode** Ppre, HuffmanNode** Ploc);
	virtual bool addNode(void* argu, int* freq, HuffmanNode* left, HuffmanNode* right, HuffmanNode* Ppre);
};

