#include "DoublyLinkedList.h"
#include "DoubleListNode.h"
#include "ListHead.h"
#include <iostream>
using namespace std;
//this circularly orderd list
DoublyLinkedList::DoublyLinkedList(int (*compare)(void* argu1, void* argu2)) : List::List(compare) {
}
bool DoublyLinkedList::search(void* argu, DoubleListNode** Ppre, DoubleListNode** Ploc) {
	*Ppre = NULL;
	*Ploc = (DoubleListNode*)this->list->front;
	//to be orderd list
	if (!this->list->count || (this->list->compare)(argu, this->list->front->dataPtr) < 0)
		return false;
	if ((this->list->compare)(argu, this->list->rear->dataPtr) > 0) {
		*Ppre = (DoubleListNode*)this->list->rear;
		*Ploc = NULL;
		return false;
	}
	if ((this->list->compare)(argu, this->list->front->dataPtr) == 0)
		return true;
	int result;
	*Ppre = *Ploc;
	*Ploc = (*Ploc)->forward;
	result = (this->list->compare)(argu, (*Ploc)->dataPtr);
	while (result > 0) {
		*Ppre = *Ploc;
		*Ploc = (*Ploc)->forward;
		result = (this->list->compare)(argu, (*Ploc)->dataPtr);
	}
	if (result)
		return false;
	return true;
}
bool DoublyLinkedList::addNode(void* argu, DoubleListNode* Ppre) {
	DoubleListNode* newNode = (DoubleListNode*)malloc(sizeof(DoubleListNode));
	if (newNode) {
		newNode->dataPtr = argu;
		newNode->forward = NULL;
		newNode->backward = NULL;
		//add before first node or to empty lsit
		if (!Ppre) {
			newNode->forward = (DoubleListNode*)this->list->front;
			this->list->front = newNode;
		}
		//adding in middle r at end
		else {
			newNode->forward = Ppre->forward;
			newNode->backward = Ppre;
		}
		//handling backward pointer & forward
		if (!newNode->forward) {
			this->list->rear = newNode;
		}
		else {
			DoubleListNode* successor = Ppre->forward;
			successor->backward = newNode;
		}
		Ppre->forward = newNode;
		this->list->count++;
		return true;
	}
	return false;

}
//
////remove value from list if it found
bool DoublyLinkedList::remove(void* argu) {
	//	
	DoubleListNode* Ppre;
	DoubleListNode* Ploc;
	bool found = this->search(argu, &Ppre, &Ploc);
	if (found) {
		if (!Ppre->backward)
			this->list->front = Ploc->forward;
		else
			Ppre->forward = Ploc->forward;
		//handle successor
		if (!Ploc->forward) {
			DoubleListNode* successor = Ppre->forward;
			successor->backward = Ppre->backward;
		}
		this->list->count--;
		free(Ploc);
	}
	return found;
}
//traverse all list from index (fromwhere) til last
//
void  DoublyLinkedList::traverse(void (*visit)(void* argu), int fromWhere) {
	DoubleListNode* node = (DoubleListNode*)this->list->front;
	for (int i = 0; i < fromWhere; i++)
		node = node->forward;
	while (node) {
		visit(node->dataPtr);
		node = node->forward;
	}
}

DoublyLinkedList::~DoublyLinkedList() {

}
