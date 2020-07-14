#pragma once
class heap
{
private :
	void** heapArr;
	int size;
	int lastIndex;
	int (*compare) (void* argu1, void* argu2);
	void reheapUp(int newNodePos);
	void reheapDown(int rootPos);
	void exchangeData(int swapIn, int swapOut);
public :
	heap(int (*compare) (void* argu1, void* argu2),int size);
	void insert(void* data);
	void* remove();
	//also called heapify
	void buildHeap(void** arr, int size);
	void* selectKElement(int k);

	~heap();

};

