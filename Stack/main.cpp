#include <iostream>
#include "Stack.h"
#include "StackApplication.h"
#include "string"
using namespace std;

int main()
{
     //stack applications
    //1) reversing number
    Stack* stack = new Stack();
    StackApplication stackApplication;
    int size = 10;
    int val ,series [size];
    int* itemPtr;
    cout << "Enter Numbers To Reverse It" << endl;
   for(int i=0; i< size; i++){
        cin>>val;
        series[i] = val;
   }
    *stack = stackApplication.reverse_series(series,size);
   cout << "Reversing Number"<<endl;
    while(!stack->isEmpty()){
        itemPtr  = (int *) stack->pop();
        cout << *itemPtr << "   ";
    }
    cout << endl;
    //2) Convert Decimal To Binary
    int decimal_number = 0;
    int* digit;
    cout << "Enter Number To Convert It To Binary"<<endl;
    cin  >> decimal_number;
    *stack = stackApplication.convert_decimal_to_binary(decimal_number);
    cout << "Binary Number"<<endl;
    while(!stack->isEmpty()){
        digit = (int *) stack->pop();
        cout << *digit;
    }
    cout <<endl;
    //3)Verify Parentheses
    string statment;
    cout << "Enter The Statment"<<endl;
    cin >> statment;
    statment = stackApplication.verify_parentheses(statment);
        cout<< statment <<endl;
    return 0;
}
