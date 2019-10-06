#include <iostream>
#include "Stack.h"
using namespace std;

int main()
{
    Stack* stack = new Stack();
    int* value;
    for(int i=0; i<10; i++){
        value  = (int *) malloc (sizeof (int) );
        *value = i;
        stack->push(value);
    }
    value = (int *) stack->pop();
    value = (int *) stack->top();
    cout << *value << "ok";
    return 0;
}
