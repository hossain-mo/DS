// Tree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Tree.h"
#include "BinaryTree.h"
#include "ExpressionTree.h"
#include "List.h"
#include <string>
#include "HuffmanTree.h"
using namespace std;
void visit(void* argu) {
    cout << *(char*)argu << "   ";
}
int compare(int* argu1, int* argu2) {
    if (*argu1 >= *argu2)
        return 1;
    else 
        return -1;
}
int compareLetter(void* argu1, void* argu2) {
    if (*(char*)argu1 == *(char*)argu2)
        return 0;
    else
        return 1;
}
int main()
{
    std::cout << "Hello World!\n";
    //1)ExpressionTree
    /*string exp;
    ExpressionTree *expressionTree = new ExpressionTree(visit);
    cout << "enter the infix expression\n";
    cin >> exp;
    cout << "size of expression : " << exp.size();
    expressionTree->build(exp);
    cout << "\nsize of tree = "<< expressionTree->size()<<endl;
    cout << "inOrder traversing\n";
    expressionTree->inOrder();
    cout << "\n";
    cout << "preOrder traversing\n";
    expressionTree->preOrder();
    cout << "\n";
    cout << "postOrder traversing\n";
    expressionTree->postOrder();
    cout << "\n";*/
    //2)HuffmanTree
    HuffmanTree* huffmanTree = new HuffmanTree(compare,compareLetter);
    int freq;
    char letter=' ';
    while (letter != '?') {
        cout << "Enter Letter : ";
        cin >> letter;
        if (letter == '?')
            break;
        cout << "\nEnter its Frequency : ";
        cin >> freq;
        cout << "\n";
        int* element = (int*)malloc(sizeof(int));
        *element = freq;
        char* letterPtr = (char*)malloc(sizeof(char));
        *letterPtr = letter;
        if (letter != '?')
        huffmanTree->insert(letterPtr,element);
    }
    huffmanTree->build();
    huffmanTree->printCode();

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
