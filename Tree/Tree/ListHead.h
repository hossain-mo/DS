#pragma once
#include "ListNode.h"
#include "HuffmanNode.h"
class ListHead
{
public:
	int count;
	HuffmanNode* front;
	HuffmanNode* rear;
	int (*compare)(int* argu1, int* argu2);
	int (*compareLetter)(void* argu1, void* argu2);
};

