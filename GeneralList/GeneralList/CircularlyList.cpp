#include "CircularlyList.h"
#include "ListNode.h"
#include "ListHead.h"
#include <iostream>
using namespace std;
// this circularly orderd list
CircularlyList::CircularlyList(int (*compare)(void* argu1, void* argu2)): List::List(compare) {
	
}
bool CircularlyList::search(void* argu, ListNode** Ppre, ListNode** Ploc) {
	*Ppre = NULL;
	*Ploc = this->list->front;
		//argu not negative
	if (!this->list->count || (this->list->compare)(argu, this->list->front->dataPtr) < 0)
		return false;
	if ((this->list->compare)(argu, this->list->rear->dataPtr) > 0) {
		*Ppre = this->list->rear;
		*Ploc = NULL;
		return false;
	}
	if ((this->list->compare)(argu, this->list->front->dataPtr) == 0) 
		return true;
	int result;
	ListNode* startAddress = *Ploc;
	*Ppre = *Ploc;
	*Ploc = (*Ploc)->link;
	while (result = (this->list->compare)(argu, (*Ploc)->dataPtr) > 0 && *Ploc != startAddress) {
		*Ppre = *Ploc;
		*Ploc = (*Ploc)->link;
	}
	if (result)
		return false;
	return true;
}
bool CircularlyList::addNode(void* argu, ListNode* Ppre) {

	bool isInserted = List::addNode(argu, Ppre);
	if (isInserted)
		this->linkRearToFront();
	return isInserted;
}

//remove value from list if it found
bool CircularlyList::remove(void* argu) {
	bool isRemoved = List::remove(argu);
	if (isRemoved)
		this->linkRearToFront();
	return isRemoved;
}
//traverse all list from index (fromwhere) til last

void  CircularlyList::traverse(void (*visit)(void* argu), int fromWhere) {
	ListNode* node = this->list->front;
	for (int i = 0; i < fromWhere ; i++)
		node = node->link;
	if (node == this->list->front) {
		visit(node->dataPtr);
		node = node->link;
	}
	while (node && node != this->list->front) {
		visit(node->dataPtr);
		node = node->link;
	}

}
void CircularlyList::linkRearToFront() {
	this->list->rear->link = this->list->front;
}
CircularlyList::~CircularlyList (){

}

