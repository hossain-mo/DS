#pragma once
#include "TreeHead.h"
#include "BinaryTreeNode.h"
class BinaryTreeHead :
	public TreeHead
{
public :
	BinaryTreeNode* root;
	void (*visit)(void* argu);

};

