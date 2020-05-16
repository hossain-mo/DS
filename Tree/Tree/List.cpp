#include "List.h"
#include "List.h"
#include "HuffmanNode.h"
#include "ListHead.h"
#include <iostream>
using namespace std;
#include "HuffmanNode.h"
// this orderd list
List::List() {

}
List::List(int (*compare)(int* argu1, int* argu2) , int (*compareLetter)(void* argu1, void* argu2)) {
	this->list = (ListHead*)malloc(sizeof(ListHead));
	this->list->compare = compare;
	this->list->compareLetter = compareLetter;
	this->list->count = 0;
	this->list->front = NULL;
	this->list->rear = NULL;
}
//search if element in rear less than new elemenmt then it is not foound
// if element not found return the previous node to be inserted and location
//if found return true
bool List::search(int* freq, HuffmanNode** Ppre, HuffmanNode** Ploc) {
	*Ppre = NULL;
	*Ploc = (HuffmanNode*)this->list->front;
	//argu not negative
	if (!this->list->count || (this->list->compare)(freq, this->list->front->frequency) < 0)
		return false;
	if ((this->list->compare)(freq, this->list->rear->frequency) > 0) {
		*Ppre = (HuffmanNode*)this->list->rear;
		*Ploc = NULL;
		return false;
	}

	int result = (this->list->compare)(freq, (*Ploc)->frequency);
	while (result > 0) {
		*Ppre = *Ploc;
		*Ploc = (*Ploc)->link;
		result = (this->list->compare)(freq, (*Ploc)->frequency);
	}
	if (result == 1 || result == -1)
		return false;
	return true;
}
bool List::insert(void* argu, int* freq, HuffmanNode* left, HuffmanNode* right) {

	bool found;
	bool success;
	HuffmanNode* Ppre;
	HuffmanNode* Ploc;
	found = this->search(freq, &Ppre, &Ploc);
	if (!found) {
		success = this->addNode(argu, freq,left,right, Ppre);
		return success;
	}
	return false;
}
bool List::searchByDataPtr(void* argu, HuffmanNode** Ppre, HuffmanNode** Ploc) {
	*Ppre = NULL;
	*Ploc = (HuffmanNode*)this->list->front;
	//argu not negative
	int result = (this->list->compareLetter)(argu, (*Ploc)->dataPtr);
	while (result > 0) {
		*Ppre = *Ploc;
		*Ploc = (*Ploc)->link;
		result = (this->list->compareLetter)(argu, (*Ploc)->dataPtr);
	}
	if (result == 1)
		return false;
	return true;
}
bool List::addNode(void* argu, int* freq, HuffmanNode* left, HuffmanNode* right,HuffmanNode* Ppre) {
	HuffmanNode* newNode = (HuffmanNode*)malloc(sizeof(HuffmanNode));
	if (newNode) {
		newNode->dataPtr = argu;
		newNode->frequency = freq;
		newNode->left = left;
		newNode->right = right;
		newNode->link = NULL;
		//add before first node or to empty lsit
		if (!Ppre) {
			newNode->link = (HuffmanNode*)this->list->front;
			this->list->front = newNode;
		}
		//adding in middle r at end
		else {
			newNode->link = Ppre->link;
			Ppre->link = newNode;
		}
		if (!newNode->link || ((HuffmanNode*)this->list->rear)->link == newNode) {
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
HuffmanNode* List::front() {
	HuffmanNode* itemPtr = NULL;
	if (!this->empty()) {
		itemPtr = this->list->front;
	}
	return itemPtr;
}
HuffmanNode* List::rear() {
	HuffmanNode* itemPtr = NULL;
	if (!this->empty()) {
		itemPtr = this->list->rear;
	}
	return itemPtr;
}
bool List::empty() {
	return !this->list->count ? true : false;
}
bool List::full() {
	HuffmanNode* newNode = (HuffmanNode*)malloc(sizeof(HuffmanNode));
	if (newNode) {
		free(newNode);
		return false;
	}
	return true;
}
//remove value from list if it found
bool List::remove(void* argu) {
	HuffmanNode* Ppre;
	HuffmanNode* Ploc;
	bool found = this->searchByDataPtr(argu, &Ppre, &Ploc);
	if (found) {
		if (!Ppre)
			this->list->front = Ploc->link;
		else
			Ppre->link = Ploc->link;
		if (!Ploc->link)
			this->list->rear = Ppre;
		this->list->count--;
		//free(Ploc);
	}
	return found;
}
//traverse all list from index (fromwhere) til last

void  List::traverse(void (*visit)(void* argu), int fromWhere) {
	HuffmanNode* node = (HuffmanNode*)this->list->front;
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
		HuffmanNode* node = (HuffmanNode*)this->list->front;
		for (int i = 0; i < index; i++)
			node = node->link;
		return node->dataPtr;
	}
	int* element = (int*)malloc(sizeof(int));
	*element = -1;
	return element;

}
//search by element if it found return true
bool  List::search(void* argu) {
	HuffmanNode* Ppre;
	HuffmanNode* Ploc;
	return this->searchByDataPtr(argu, &Ppre, &Ploc);
}

List::~List() {
}