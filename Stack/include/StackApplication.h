#ifndef STACKAPPLICATION_H
#define STACKAPPLICATION_H
#include "Stack.h"
#include "string"
using namespace std;

class StackApplication
{
    public:
        StackApplication();
        Stack  reverse_series(int* series, int size);
        Stack  convert_decimal_to_binary(int decimal);
        string verify_parentheses(string statment);
        string convert_infix_to_postfix(string statment);
        int evaluate_postfix_expertion(string expertion);
        void fill_board (int board_size);
        virtual ~StackApplication();

    protected:

    private:
    Stack* stack;
    int priority(char token);
    bool is_operator(char token);
    int calculate (int operand_one, int operand_two, char oper);
    bool is_queen_guarded(int board[][9],int chk_row,int chk_col,int board_size);
};

#endif // STACKAPPLICATION_H
