#include "DoublyLinkedList.h"
#include "DoubleListNode.h"
#include "ListHead.h"
#include <iostream>
using namespace std;
 //this circularly orderd list
//DoublyLinkedList::DoublyLinkedList(int (*compare)(void* argu1, void* argu2))  {
//
//}
//bool DoublyLinkedList::search(void* argu, DoubleListNode** Ppre, DoubleListNode** Ploc) {
////	*Ppre = NULL;
////	*Ploc = (DoubleListNode *)this->list->front;
////	//to be orderd list
////	if (!this->list->count || (this->list->compare)(argu, this->list->front->dataPtr) < 0)
////		return false;
////	if ((this->list->compare)(argu, this->list->rear->dataPtr) > 0) {
////		*Ppre = (DoubleListNode*)this->list->rear;
////		*Ploc = NULL;
////		return false;
////	}
////	if ((this->list->compare)(argu, this->list->front->dataPtr) == 0)
////		return true;
////	int result;
////	DoubleListNode* startAddress = *Ploc;
////	*Ppre = *Ploc;
////	*Ploc = (*Ploc)->link;
////	while (result = (this->list->compare)(argu, (*Ploc)->dataPtr) > 0 && *Ploc != startAddress) {
////		*Ppre = *Ploc;
////		*Ploc = (*Ploc)->forward;
////	}
////	if (result)
////		return false;
////	return true;
//}
//bool DoublyLinkedList::addNode(void* argu, DoubleListNode* Ppre) {
////	DoubleListNode* newNode = (DoubleListNode*)malloc(sizeof(DoubleListNode));
////	if (newNode) {
////		newNode->dataPtr = argu;
////		newNode->forward = NULL;
////		newNode->backward = NULL;
////		//add before first node or to empty lsit
////		if (!Ppre) {
////			newNode->forward = (DoubleListNode*)this->list->front;
////			this->list->front = newNode;
////		}
////		//adding in middle r at end
////		else {
////			newNode->forward = Ppre->forward;
////			newNode->backward = Ppre;
////		}
////		if (!newNode->link) {
////			this->list->rear = newNode;
////		}
////
////		this->list->count++;
////		return true;
////	}
////	return false;
////	
//}
////
//////remove value from list if it found
//bool DoublyLinkedList::remove(void* argu) {
////	
//}
////traverse all list from index (fromwhere) til last
////
//void  DoublyLinkedList::traverse(void (*visit)(void* argu), int fromWhere) {
////	
////
//}
//
//DoublyLinkedList::~DoublyLinkedList() {
//
//}
