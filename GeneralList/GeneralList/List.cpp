#include "List.h"
#include "ListNode.h"
#include "ListHead.h"
#include <iostream>
using namespace std;
// this orderd list
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
bool List::search(void* argu, ListNode** Ppre, ListNode** Ploc) {
	*Ppre = NULL;
	*Ploc = this->list->front;
	if (!this->list->count || (this->list->compare)(argu, this->list->front->dataPtr) < 0)
		return false;
	if ((this->list->compare)(argu, this->list->rear->dataPtr) > 0 ) {
		*Ppre = this->list->rear;
		*Ploc = NULL;
		return false;
	}

	int result;
	while (result = (this->list->compare)(argu, (*Ploc)->dataPtr) > 0) {
		*Ppre = *Ploc;
		*Ploc = (*Ploc)->link;
	}
	if (result)
		return false;
	return true;
}
bool List::insert(void* argu) {
	bool found;
	bool success;
	ListNode* Ppre;
	ListNode* Ploc;
	found = this->search(argu, &Ppre, &Ploc);
	if (!found) {
		success = this->addNode(argu, Ppre);
		return success;
	}
	return false;
}
bool List::addNode(void* argu,ListNode* Ppre) {
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	if (newNode) {
		newNode->dataPtr = argu;
		newNode->link = NULL;
		//add before first node or to empty lsit
		if (!Ppre) {
			newNode->link        = this->list->front;
			this->list->front    = newNode;
			if (!this->list->count) {
				this->list->rear = newNode;
			}
		}
		//adding in middle r at end
		else {
			newNode->link = Ppre->link;
			Ppre->link = newNode;
		}
		if (!newNode->link) {
			this->list->rear    = newNode;
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
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	if (newNode) {
		free(newNode);
		return false;
	}
	return true;
}
//remove value from list if it found
bool List::remove(void* argu) {
	ListNode* Ppre;
	ListNode* Ploc;
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
	ListNode* node = this->list->front;
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
		ListNode* node = this->list->front;
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
	ListNode* Ppre;
	ListNode* Ploc;
	return this->search(argu,&Ppre,&Ploc);
}

List::~List() {
}