#include "Stack.h"
#include <iostream>
using namespace std;
/*
pre  : nothing
post : the stack head is created and stack ready to work
*/
Stack::Stack(){
    this->stack   = (StackHead* ) malloc( sizeof(StackHead) );
    if(stack){
        stack   = new StackHead();
        stack->count       = 0;
        stack->top        = NULL;
    }
}
/*
pre  : stack ws created
post : return true if stack is have not elements
*/
bool Stack::isEmpty(){
    return !this->stack->count;
}
/*
pre  : stack ws created
post : return true if stack is fully
*/
bool Stack::isFull(){
    StackNode* node    = (StackNode* ) malloc( sizeof(StackNode) );
    if(node){
        free(node);
        return false;
    }
    return true;
}
/*
pre  : stack ws created
post : add element at the top of the stack
*/
bool Stack::push(void* itemPointer){
    StackNode* node    = (StackNode* ) malloc( sizeof(StackNode) );
    if(node){
        node               = new StackNode();
        node->dataPointer  = itemPointer;
        node->next         = this->stack->top;
        this->stack->top   = node;
        this->stack->count ++;
        return true;
    }
    return false;
}
/*
pre   : stack was created
post  : return  the data at the top of the stack and remove it from the stack and null if it empty
*/
void* Stack::pop (){
    void* dataPointer  = NULL;
    if(!this->isEmpty()){
        StackNode* node    = new StackNode();
        node              = this->stack->top;
        dataPointer       = node->dataPointer;
        this->stack->top  = node->next;
        this->stack->count --;
        free(node);
    }
    return dataPointer;
}
/*
pre  : stack ws created
post : return the data only from stack if it contain data
*/
void* Stack::top(){
    void* dataPointer  = NULL;
    if(!this->isEmpty()){
        dataPointer     = this->stack->top->dataPointer;
    }
    return dataPointer;
}
/*
pre  : stack ws created
post : return number of elements contained in stack
*/
int Stack::count(){
    return this->stack->count;
}
/*
pre  : stack ws created
post : free the memory that taken from stack in memory and remove element from stak
*/
StackHead* Stack::destroy(){
    if(this->stack){
        StackNode* node    = new StackNode();
        while(!this->isEmpty()){
            node              = this->stack->top;
            this->stack->top  = node->next;
            this->stack->count --;
            free(node);
        }
    free(this->stack);
    }
    return NULL;
}
Stack::~Stack()
{
    //dtor
}
