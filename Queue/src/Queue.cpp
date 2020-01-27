#include "Queue.h"
#include "QueueNode.h"
#include "QueueHead.h"
#include <iostream>
/*
pre  : nothing
post : the queue head is created and queue ready to work
*/
Queue::Queue(){
    this->queue = (QueueHead *) malloc (sizeof(QueueHead));
    this->queue->count = 0;
    this->queue->front = NULL;
    this->queue->rear  = NULL;
}
/*
pre  : queue is created
post : data is in queue
*/
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
/*
pre  : queue created and not in empty state
post : data in front of queue is out to user
*/
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
/*
pre  : queue is created
post : if queue is empty it return true else false
*/
bool Queue::isEmpty(){
    if(this->queue->count)
        return false;
    return true;
}
/*
pre  : queue is created
post : if queue is full it return true else false
*/
bool Queue::isFull(){
    QueueNode* node = (QueueNode *)  malloc (sizeof(QueueNode));
    if(node){
        free(node);
        return false;
    }
    return true;
}
/*
pre  : queue is created
post : return number of elements in queue
*/
int Queue::count(){
    return this->queue->count;
}
/*
pre  : queue is created
post : if queue is empty it return null else return element in front
*/
void* Queue::front(){
    void * itemPtr;
    if(!this->isEmpty()){
        itemPtr  = this->queue->front->dataPtr;
    }
    return itemPtr;
}
/*
pre  : queue is created
post : if queue is empty it return null else return element in rear
*/
void* Queue::rear(){
    void * itemPtr;
    if(!this->isEmpty()){
        itemPtr  = this->queue->rear->dataPtr;
    }
    return itemPtr;
}
/*
pre  : queue is created
post : it free the space that token from queue in memory delete all data
*/
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
