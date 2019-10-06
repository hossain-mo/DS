#ifndef STACK_H
#define STACK_H
#include "StackNode.h"
#include "StackHead.h"
class Stack
{
    public:
        Stack();
        virtual ~Stack();
        StackHead* stack;
        bool isEmpty();
        bool isFull();
        bool push(void* itemPointer);
        void* pop ();
        void* top();
        int count();
        StackHead* destroy();
    protected:

    private:
};

#endif // STACK_H
