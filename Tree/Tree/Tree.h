#pragma once
#include "TreeHead.h"
class Tree
{
public:
	Tree();
	bool isFull();
	bool isEmpty();
	int  size();
	int  height();
	void increaseHeight();
	void increaseSize();
	void decreaseSize();
	virtual ~Tree();
	TreeHead* tree;
};

