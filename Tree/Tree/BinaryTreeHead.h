#pragma once
#include "TreeHead.h"
#include "BinaryTreeNode.h"
class BinaryTreeHead :
	public TreeHead
{
public :
	BinaryTreeNode* root;
	void (*visit)(void* argu);
	int (*compare)(int* argu1, int* argu2);
};

