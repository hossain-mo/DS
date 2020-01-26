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
    int size = 3;
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
    cout << "Enter The Statment To Verify Parentheses"<<endl;
    cin >> statment;
    statment = stackApplication.verify_parentheses(statment);
       cout <<"Verifeing"<<"  "<< statment <<endl;

     //4)convert inix to postfix
    cout << "Enter The Infix Statment To Convert It To Postfix"<<endl;
    cin >> statment;
    statment = stackApplication.convert_infix_to_postfix(statment);
        cout <<"Postfix"<<"   : " << statment <<endl;

     //5)evaluate postfix
    int evaluation_value;
    cout << "Enter The PostFix Experation To Evaluate It"<<endl;
    cin >> statment;
    evaluation_value = stackApplication.evaluate_postfix_expertion(statment);
        cout <<"Postfix Evaluation Value"<<"   : " << evaluation_value <<endl;
      //6)Eight Queens
      int board_size;
      cout<<"Welcome To Eight Queen problem Please Enter Size between 4 and 8"<<endl;
      cin>>board_size;
      if(board_size < 4 || board_size >8)
            cout<<"the size is wrong"<<endl;
      else{

           stackApplication.fill_board(board_size);
      }


    return 0;
}
