// Heap.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "heap.h"
#include "priorityQueueNode.h"
using namespace std;
int compare(void* argu1, void* argu2) {
    if (*(int *)argu1 > * (int*)argu2)
        return 1;
    else
        return 0;
}
int comparePriorityQueue(void* argu1, void* argu2) {
    if (((priorityQueueNode *)argu1)->getPriority() > ((priorityQueueNode*)argu2)->getPriority())
        return 1;
    if (((priorityQueueNode*)argu1)->getPriority() == ((priorityQueueNode*)argu2)->getPriority())
        return ((priorityQueueNode*)argu1)->getValue() > ((priorityQueueNode*)argu2)->getValue();
    else 
        return 0;
}
int main()
{
    std::cout << "Hello World!\n";
    heap *heapObj = new heap(compare,5);
    void** arr = (void**)calloc(5, sizeof(void*));

    int input;
    for (int i = 0; i < 5; i++)
    {
        cin >> input;
        int* element = (int*)malloc(sizeof(int));
        *element = input;
        heapObj->insert(element);
        arr[i] = element;
    }
    cout << "internal heap arr\n";
    //heapity
    heapObj->buildHeap(arr, 5);
    for (int i = 0; i < 5; i++)
    {
        cout << *(int*)arr[i] << "  ";
    }
    //first app on heaps selection algorithm
    cout << "\nselecting third element :  ";
    cout << *(int*)heapObj->selectKElement(3)<<"\n";
    cout << "whole heap: \n";
    for (int i = 0; i < 5; i++)
    {
        cout << *(int*)heapObj->remove() << "  ";
    }
    //second application on heaps priority queue
    cout << "\npriority queue please enter five five values with priorities\n";
    int value, priority;
    heap* priorityQueue = new heap(comparePriorityQueue, 5);
    for (int i = 0; i < 5; i++)
    { 
        cout << "Value : ";
        cin >> value;
        cout << "Priority : ";
        cin >> priority;
        priorityQueueNode* node = (priorityQueueNode*)malloc(sizeof(priorityQueueNode));
        *node =  priorityQueueNode(value, priority);
        priorityQueue->insert(node);
    }
    cout << "\nthe whole queue\n";
    for (int i = 0; i < 5; i++)
    {
        priorityQueueNode* node = (priorityQueueNode*) priorityQueue->remove();
        cout << "value :"<<node->getValue() << "  "<<
            "priority :" << node->getPriority() << "  \n";
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
