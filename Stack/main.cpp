#include <iostream>
#include "Stack.h"
#include "string"
using namespace std;

int main()
{
     //stack applications
    //1) reversing number
    Stack* stack = new Stack();
    int* value;
    bool done = false;
    cout << "Enter Numbers To Reverse It" << endl;
    while(! done){
        value  = (int *) malloc (sizeof (int) );
        cin >> *value;
        if(*value == 100 || stack->isFull())
            done = true;
        else
        stack->push(value);
    }
   cout << "Reversing Number"<<endl;
    while(!stack->isEmpty()){
        value = (int *) stack->pop();
        cout << *value << "   ";
    }
    //2) Convert Decimal To Binary
    int decimal_number = 0;
    int* digit;
    cout << "Enter Number To Convert It To Binary"<<endl;
    cin  >> decimal_number;
    while(decimal_number > 0){
        digit  = (int *) malloc (sizeof(int));
        *digit = decimal_number % 2 ;
        stack->push(digit);
        decimal_number /= 2;
    }
    cout << "Binary Number"<<endl;
    while(!stack->isEmpty()){
        digit = (int *) stack->pop();
        cout << *digit;
    }
    //3)Verify Parentheses
    string statment;
    int length = 0;
    char* token;
    cout << "Enter The Statment"<<endl;
    cin >> statment;
    length = statment.size();
    for(int i = 0; i< length; i++){
        if(statment[i] == '('){
            token  = (char*) malloc (sizeof(char));
            *token = statment[i];
            stack->push(token);
        }
        else if(statment[i] == ')'){
            if(!stack->isEmpty())
                stack->pop();
            else{
                cout << "Opening Parenthes is Not Matched"<<endl;
                return 1;
            }
        }
    }
    if(!stack->isEmpty())
        cout << "Closed Parenthes is Not Matched"<<endl;
    else
        cout<< "OK" <<endl;
    return 0;
}
