#pragma once
class priorityQueueNode
{
public :
	priorityQueueNode(int value , int priority);
	int getPriority();
	int getValue();
	virtual ~priorityQueueNode();
private:
	int priority;
	int value;
};

