#include "priorityQueueNode.h"
priorityQueueNode::priorityQueueNode(int value, int priority) {
	this->value = value;
	this->priority = priority;
}
int priorityQueueNode::getPriority() {
	return this->priority;
}
int priorityQueueNode::getValue() {
	return this->value;
}

priorityQueueNode::~priorityQueueNode() {

}
