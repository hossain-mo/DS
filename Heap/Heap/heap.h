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
	//also called heapify
	void insert(void* data);
	void* remove();
	void buildHeap(void** arr, int size);

	~heap();

};

