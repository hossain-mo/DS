#pragma once
#include "TreeHead.h";
class Tree
{
public:
	Tree();
	bool isFull();
	bool isEmpty();
	int  size();
	int  height();
	virtual ~Tree();
	TreeHead* tree;
};

