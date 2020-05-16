#pragma once
#include "TreeNode.h"
class HuffmanNode :
	public TreeNode
{
public:
	HuffmanNode* left;
	HuffmanNode* right;
	HuffmanNode* link;
	int* frequency;
};

