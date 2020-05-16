#pragma once
#include "HuffmanNode.h"
class ListNode
{
public:
	void* dataPtr;
	int* frequency;
	HuffmanNode* left;
	HuffmanNode* right;
};

