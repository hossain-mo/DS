#include "List.h"
#include "SingleListNode.h"
#include "ListHead.h"
#include <iostream>
using namespace std;
// this orderd list
List::List() {

}
List::List(int (*compare)(void* argu1, void* argu2)) {
	this->list = (ListHead *) malloc ( sizeof (ListHead) );
	this->list->compare= compare;
	this->list->count = 0;
	this->list->front = NULL;
	this->list->rear = NULL;
}
//search if element in rear less than new elemenmt then it is not foound
// if element not found return the previous node to be inserted and location
//if found return true
bool List::search(void* argu, SingleListNode** Ppre, SingleListNode** Ploc) {
	*Ppre = NULL;
	*Ploc = (SingleListNode *)this->list->front;
		//argu not negative
	if (!this->list->count || (this->list->compare)(argu, this->list->front->dataPtr) < 0)
		return false;
	if ((this->list->compare)(argu, this->list->rear->dataPtr) > 0 ) {
		*Ppre = (SingleListNode*)this->list->rear;
		*Ploc = NULL;
		return false;
	}

	int result = (this->list->compare)(argu, (*Ploc)->dataPtr);
	while ( result > 0 ) {
		*Ppre = *Ploc;
		*Ploc = (*Ploc)->link;
		result = (this->list->compare)(argu, (*Ploc)->dataPtr);
	}
	if (result == 1 || result == -1)
		return false;
	return true;
}
bool List::insert(void* argu) {
	bool found;
	bool success;
	SingleListNode* Ppre;
	SingleListNode* Ploc;
	found = this->search(argu, &Ppre, &Ploc);
	if (!found) {
		success = this->addNode(argu, Ppre);
		return success;
	}
	return false;
}
bool List::addNode(void* argu,SingleListNode* Ppre) {
	SingleListNode* newNode = (SingleListNode*)malloc(sizeof(SingleListNode));
	if (newNode) {
		newNode->dataPtr = argu;
		newNode->link = NULL;
		//add before first node or to empty lsit
		if (!Ppre) {
			newNode->link        = (SingleListNode*)this->list->front;
			this->list->front    = newNode;
		}
		//adding in middle r at end
		else {
			newNode->link = Ppre->link;
			Ppre->link = newNode;
		}
		if (!newNode->link || ((SingleListNode*)this->list->rear)->link == newNode) {
			this->list->rear = newNode;
		}
			
		this->list->count++;
		return true;
	}
	return false;
}
int List::count() {
	return this->list->count;
}
void* List::front() {
	void* itemPtr = NULL;
	if (!this->empty()) {
		itemPtr = this->list->front->dataPtr;
	}
	return itemPtr;
}
void* List::rear() {
	void* itemPtr = NULL;
	if (!this->empty()) {
		itemPtr = this->list->rear->dataPtr;
	}
	return itemPtr;
}
bool List::empty() {
	return !this->list->count ? true : false;
}
bool List::full() {
	SingleListNode* newNode = (SingleListNode*)malloc(sizeof(SingleListNode));
	if (newNode) {
		free(newNode);
		return false;
	}
	return true;
}
//remove value from list if it found
bool List::remove(void* argu) {
	SingleListNode* Ppre;
	SingleListNode* Ploc;
	bool found = this->search(argu,&Ppre,&Ploc);
	if (found) {
		if (!Ppre)
			this->list->front = Ploc->link;
		else
			Ppre->link = Ploc->link;
		if (!Ploc->link)
			this->list->rear = Ppre;
		this->list->count--;
		free(Ploc);
	}
	return found;
}
//traverse all list from index (fromwhere) til last

void  List::traverse(void (*visit)(void* argu),int fromWhere) {
	SingleListNode* node = (SingleListNode*)this->list->front;
	for (int i = 0; i < fromWhere; i++)
		node = node->link;
	while (node) {
			visit(node->dataPtr);
			node = node->link;
	}
		
}
//return the element of thie index if it found else return -1
void* List::retrieve(int index) {
	if (index < this->list->count) {
		SingleListNode* node = (SingleListNode*)this->list->front;
		for (int i = 0; i < index; i++)
			node = node->link;
		return node->dataPtr;
	}
	int* element = (int*)malloc(sizeof(int));
	*element = -1;
	return element;
	
}
//search by element if it founf return true
bool  List::search(void* argu) {
	SingleListNode* Ppre;
	SingleListNode* Ploc;
	return this->search(argu,&Ppre,&Ploc);
}

List::~List() {
}