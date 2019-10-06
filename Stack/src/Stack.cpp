#include "Stack.h"
#include <iostream>
using namespace std;
Stack::Stack(){
    this->stack   = (StackHead* ) malloc( sizeof(StackHead) );
    if(stack){
        stack   = new StackHead();
        stack->count       = 0;
        stack->top        = NULL;
    }
}
bool Stack::isEmpty(){
    return !this->stack->count;
}
bool Stack::isFull(){
    StackNode* node    = (StackNode* ) malloc( sizeof(StackNode) );
    if(node){
        free(node);
        return false;
    }
    return true;
}
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
void* Stack::pop (){
    void* dataPointer  = NULL;
    StackNode* node    = new StackNode();
    if(!this->isEmpty()){
        node              = this->stack->top;
        dataPointer       = node->dataPointer;
        this->stack->top  = node->next;
        this->stack->count --;
        free(node);
    }
    return dataPointer;
}
void* Stack::top(){
    void* dataPointer  = NULL;
    if(!this->isEmpty()){
        dataPointer     = this->stack->top->dataPointer;
    }
    return dataPointer;
}
int Stack::count(){
    return this->stack->count;
}
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
