#include "StackApplication.h"
#include "Stack.h"
#include <iostream>
#include "string"
using namespace std;

StackApplication::StackApplication()
{
    //ctor
    this->stack   = new Stack();
}
Stack StackApplication::reverse_series(int *series,int size){
    int* dataPtr;
    for(int i =0; i < size; i++){
        if(! this->stack->isFull()){
        dataPtr  = (int *) malloc (sizeof(int));
        *dataPtr = *(series+i);
            this->stack->push(dataPtr);
        }
    }
    return *this->stack;
}
Stack StackApplication::convert_decimal_to_binary(int decimal){
    int* dataPtr;
    while(decimal && ! this->stack->isFull()){
        dataPtr  = (int *) malloc (sizeof(int));
        *dataPtr = decimal % 2;
        decimal /= 2;
            this->stack->push(dataPtr);
    }
    return *this->stack;
}
string StackApplication::verify_parentheses(string statment){
    char* token;
    string message;
    int length = statment.size();
    for(int i = 0; i< length; i++){
        if(statment[i] == '('){
            token  = (char*) malloc (sizeof(char));
            *token = statment[i];
            this->stack->push(token);
        }
        else if(statment[i] == ')'){
            if(! this->stack->isEmpty())
                 this->stack->pop();
            else{
                message = "Opening Parenthes is Not Matched";
            }
        }
    }
    if(!this->stack->isEmpty())
        message = "Closed Parenthes is Not Matched";
    else
        message = "OK";
    return message;
}
StackApplication::~StackApplication()
{
    //dtor
}
