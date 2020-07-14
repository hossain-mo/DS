#include "heap.h"
#include <iostream>
heap::heap(int (*compare) (void* argu1, void* argu2), int size) {
	this->size = size;
	this->compare = compare;
	this->lastIndex = 0;
	this->heapArr = (void**)calloc(this->size, sizeof (void *) );
}
void heap::exchangeData(int swapIn, int swapOut) {
	void* temp             = this->heapArr[swapIn];
	this->heapArr[swapIn]  = this->heapArr[swapOut];
	this->heapArr[swapOut] = temp;
}
void heap::reheapUp(int newNodePos) {
	int parentPos = 0;
	if (newNodePos != 0) {
		parentPos = ( newNodePos - 1 ) / 2;
		if (this->compare(this->heapArr[newNodePos] , this->heapArr[parentPos])) {
			this->exchangeData(parentPos,newNodePos);
			reheapUp(parentPos);
		}
	}
	return;
}
void heap::reheapDown(int rootPos) {
	int largePos = (rootPos * 2) + 1;
	if (largePos < this->lastIndex) {
		void* largeData;
		 largeData = this->heapArr[largePos];
		 if ((largePos + 1) < this->lastIndex && this->compare(this->heapArr[(largePos + 1)], largeData)) {
			 largeData = this->heapArr[(largePos + 1)];
			 largePos++;
		 }
		 if (this->compare(largeData, this->heapArr[rootPos])) {
			 exchangeData(rootPos, largePos);
			 reheapDown(largePos);
		 }
	}
	return;
}
void heap::insert(void* data) {
	if (this->lastIndex == this->size )
		return;
	this->heapArr[this->lastIndex] = data;
	reheapUp(lastIndex);
	this->lastIndex++;
}
void* heap::remove() {
	if (this->lastIndex == - 1)
		return NULL;
	void* dataOut;
	dataOut = this->heapArr[0];
	this->lastIndex--;
	this->exchangeData(0, this->lastIndex);
	this->reheapDown(0);
	return dataOut;
}
void heap::buildHeap(void** arr, int size) {
	void** tempHeapArr = this->heapArr;
	this->heapArr = arr;
	for (int i = 1; i < size; i++) {
		this->reheapUp(i);
	}
	this->heapArr = tempHeapArr;
}

void* heap::selectKElement(int k) {
	if (k - 1 > this->size)
		return NULL;
	for (int i = 1; i < k; i++) {
		this->remove();
	}
	void* selectedElement = this->remove();
	for (int i = 0; i < k ; i++) {
		this->reheapUp(lastIndex);
		this->lastIndex++;
	}
	return selectedElement;
}

heap::~heap() {

}
