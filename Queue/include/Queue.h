#ifndef QUEUE_H
#define QUEUE_H
#include "QueueHead.h"
#include "QueueNode.h"

class Queue
{
    public:
        //properties
            QueueHead* queue;
        //methods
        Queue();
        bool  enQueue(void* itemPtr);
        void* deQueue();
        bool  isEmpty();
        bool  isFull();
        int   count();
        void* front();
        void* rear();
        QueueHead* destroy();
        virtual ~Queue();

    protected:

    private:
};

#endif // QUEUE_H
