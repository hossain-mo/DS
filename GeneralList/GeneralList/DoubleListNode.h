#pragma once
#include "ListNode.h"

class DoubleListNode : public ListNode
{
public:
	DoubleListNode* forward;
	DoubleListNode* backward;
};

