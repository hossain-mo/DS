#include "Queue.h"
#include "QueueNode.h"
#include "QueueHead.h"
#include <iostream>
Queue::Queue(){
    this->queue = (QueueHead *) malloc (sizeof(QueueHead));
    this->queue->count = 0;
    this->queue->front = NULL;
    this->queue->rear  = NULL;
}
bool Queue::enQueue(void* dataPtr){
    QueueNode* node = (QueueNode *) malloc (sizeof (QueueNode) );
    if(node){
        node->dataPtr = dataPtr;
        node->next    = NULL;
        if(this->isEmpty())
            this->queue->front = node;
        else
            this->queue->rear->next = node;
        this->queue->rear = node;
        this->queue->count ++;
        return true;
    }
    return false;
}
void* Queue::deQueue(){
    void * itemPtr;
    if(!this->isEmpty()){
        QueueNode* node;
        node     = this->queue->front;
        if(this->queue->count==1)
            this->queue->rear = this->queue->front = NULL;
        else
            this->queue->front= node->next;
        this->queue->count --;
        itemPtr  = node->dataPtr;
        free(node);

    }
    return itemPtr;
}
bool Queue::isEmpty(){
    if(this->queue->count)
        return false;
    return true;
}
bool Queue::isFull(){
    QueueNode* node = (QueueNode *)  malloc (sizeof(QueueNode));
    if(node){
        free(node);
        return false;
    }
    return true;
}
int Queue::count(){
    return this->queue->count;
}
void* Queue::front(){
    void * itemPtr;
    if(!this->isEmpty()){
        itemPtr  = this->queue->front->dataPtr;
    }
    return itemPtr;
}
void* Queue::rear(){
    void * itemPtr;
    if(!this->isEmpty()){
        itemPtr  = this->queue->rear->dataPtr;
    }
    return itemPtr;
}
QueueHead* Queue::destroy(){
    if(this->queue){
        while(this->queue->front){
            QueueNode* node;
            node = this->queue->front;
            this->queue->front = node->next;
            free(node);
        }
        free(this->queue);
    }
    return NULL;
}
Queue::~Queue(){
    //dtor
}
