#include "StackApplication.h"
#include "Stack.h"
#include "position.h"
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
int StackApplication::priority(char token){

        if(token == '*' || token =='/')
            return 2;
        else if(token == '+' || token =='-')
            return 1;
        return 0;

}
bool StackApplication::is_operator(char token){
    if(token == '-' || token == '+' || token == '/' || token == '*' )
        return true;
    return false;
}
string StackApplication::convert_infix_to_postfix(string statment){
    char* token;
    string postfix;
    int length = statment.size();
    for(int i = 0; i< length; i++){
        if(statment[i] == '('){
            token  = (char*) malloc (sizeof(char));
            *token = statment[i];
            this->stack->push(token);
        }
        else if(statment[i] == ')'){
            token = (char *) this->stack->pop();
            while(! this->stack->isEmpty() &&  *token != '('){
               postfix += *token;
               token = (char *) this->stack->pop();
            }
        }
        else if(this->is_operator(statment[i])){
            token = (char *) this->stack->top();
            while(! this->stack->isEmpty() &&  this->priority(*token) >= this->priority(statment[i])){
               token = (char *) this->stack->pop();
               postfix += *token;
               token = (char *) this->stack->top();
            }
            token  = (char *) malloc (sizeof(char));
            *token = statment[i];
            this->stack->push(token);
        }
        else{
           postfix += statment[i];
        }
    }
        while(! this->stack->isEmpty()){
               token = (char *) this->stack->pop();

               postfix += token;
            }
    return postfix;
}
int StackApplication::calculate (int operand_one, int operand_two, char oper){
    int resault;
    switch(oper){
        case '+' : resault = operand_one + operand_two;break;
        case '-' : resault = operand_one - operand_two;break;
        case '*' : resault = operand_one * operand_two;break;
        case '/' : resault = operand_one / operand_two;break;
    }
    return resault;
}
int StackApplication::evaluate_postfix_expertion(string expertion){

    int length = expertion.size(),*token,operand_one,operand_two,value;
    for(int i=0;i<length;i++){
        if(!is_operator(expertion[i])){
            token  = (int *) malloc (sizeof(int));
            *token = int(expertion[i]) -48;
            this->stack->push(token);
        }else{
            operand_two = *(int *)this->stack->pop();
            operand_one = *(int *)this->stack->pop();
            value       = this->calculate(operand_one,operand_two,expertion[i]);
            token  = (int *) malloc (sizeof(int));
            *token = value;
            this->stack->push(token);
        }
    }
    return *(int *)this->stack->pop();
 }
bool StackApplication::is_queen_guarded(int board[][9],int chk_row,int chk_col,int board_size){
    int row , col=chk_col;
    //check current col for a queen
    for( row = 1; row <= chk_row ; row++)
        if(board[row][col])
            return true;
    //check diagonal right-up
    for( row = chk_row - 1, col = chk_col +1; row > 0 && col <= board_size ; row--,col++)
        if(board[row][col])
            return true;
    //check diagonal left-up
    for( row = chk_row - 1, col = chk_col -1; row > 0 && col >0 ; row--,col--)
        if(board[row][col])
            return true;
    return false;
}
void StackApplication::fill_board (int board_size){
    int row=1,col=0,board[9][9]={0};
    position* pPos;
    while(row <= board_size){
        while(col<=board_size && row <= board_size){
            col++;
            if(!this->is_queen_guarded(board,row,col,board_size)){
                board[row][col] = 1;
                pPos = (position*) malloc (sizeof(position));
                pPos->row = row;
                pPos->col = col;
                this->stack->push(pPos);
                row++;
                col=0;
            }
            while(col >= board_size){
                pPos = (position *) this->stack->pop();
                row = pPos->row;
                col = pPos->col;
                board[row][col]=0;
                free(pPos);
            }
        }
    }
    for(int i=1;i<=board_size;i++){
        for(int x=1;x<=board_size;x++){
            if(board[i][x] == 1)
                cout << " Q |";
            else
                cout << "   |";
        }
        cout<<endl;
    }
}
StackApplication::~StackApplication()
{
    //dtor
}
