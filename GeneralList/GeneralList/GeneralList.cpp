// GeneralList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "List.h"
#include "ListNode.h"
using namespace std;
int compare (void* argu1, void* argu2) {
    if (*(int*)argu1 > * (int*)argu2)
        return 1;
    else if (*(int*)argu1 < *(int*)argu2)
        return -1;
    else
        return 0;
}
void visit(void* argu) {
    cout << *(int*)argu << "   ";
}
int main()
{
    List* list = new List(compare);
    int input;
    for (int i = 0; i < 5; i++)
    {
        cin >> input;
        int* element = (int*)malloc(sizeof(int));
        *element = input;
        list->insert(element);
    }
    int* element = (int*)malloc(sizeof(int));
    *element = 2;
    
    cout << "front of the list " << *(int*)list->front()  << endl;
    cout << "rear of the list " << *(int*)list->rear()   << endl;
    cout << "number of the elements in list " << list->count()         <<endl;
    cout << "is list is fully  " << list->full()          <<endl;
    cout << "all elements in the list  from index 1  ";
    list->traverse(visit,1);
    cout << endl;
    cout << "if value 2 in list          " << list->search(element) << endl;
    cout << "retrieve value 10 fro list  " << * ( int *) list->retrieve(10) << endl;
    cout << "remove value 2 from list    " << list->remove(element) << endl;
    list->traverse(visit, 0);
    cout << endl;
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
