#pragma once
#include "ListNode.h"
class ListHead
{
public:
	int count;
	ListNode* front;
	ListNode* rear;
	int (*compare)(void* argu1, void* argu2);
};

