#ifndef STACKAPPLICATION_H
#define STACKAPPLICATION_H
#include "Stack.h"
#include "string"
using namespace std;

class StackApplication
{
    public:
        StackApplication();
        Stack reverse_series(int* series, int size);
        Stack convert_decimal_to_binary(int decimal);
        string verify_parentheses(string statment);

        virtual ~StackApplication();

    protected:

    private:
    Stack* stack;
};

#endif // STACKAPPLICATION_H
