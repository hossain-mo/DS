#include <iostream>
#include "Queue.h"
using namespace std;

int main()
{
    Queue* queue = new Queue();
    int* item = (int *) malloc(sizeof(int));
    *item = 5;
    queue->enQueue(item);
    cout << *(int*)(queue->rear());
    return 0;
}
