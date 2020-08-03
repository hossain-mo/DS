// Graph.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include"Graph.h"
using namespace std;


void visit(void* argu) {
    cout << *(int*)argu << "   ";
}
int compare(void* argu1, void* argu2) {
    if (*(int*)argu1 > * (int*)argu2)
        return 1;
    if (*(int*)argu1 < *(int*)argu2)
        return -1;
    else
        return 0;
}

int main()
{
    std::cout << "Hello World!\n";
    Graph* graphPtr = new Graph(compare, visit);
    int input;
    //inset vertics
    for (int i = 0; i < 6; i++)
    {
        cin >> input;
        int* element = (int*)malloc(sizeof(int));
        *element = input;
        graphPtr->insertVertex(element);
    }
    //count of grapgh
    cout << graphPtr->count() << "\n";
    int* element = (int*)malloc(sizeof(int));
    *element = 2;
    ////delete vertex
    //graphPtr->deleteVertex(element);
    //cout << graphPtr->count() << "\n";
    //insert arcs
    int* from = (int*)malloc(sizeof(int));
    *from = 5;
    int* to = (int*)malloc(sizeof(int));
    *to = 10;
    cout << graphPtr->insertGrapghArc(from, to) << "\n";

    *from = 10; *to = 5;
    cout << graphPtr->insertGrapghArc(from, to) << "\n";
    *from = 10; *to = 15;
    cout << graphPtr->insertGrapghArc(from, to) << "\n";
    *from = 10; *to = 25;
    cout << graphPtr->insertGrapghArc(from, to) << "\n";

    *from = 15; *to = 25;
    cout << graphPtr->insertGrapghArc(from, to) << "\n";
    *from = 15; *to = 10;
    cout << graphPtr->insertGrapghArc(from, to) << "\n";
    *from = 15; *to = 20;
    cout << graphPtr->insertGrapghArc(from, to) << "\n";

    *from = 20; *to = 25;
    cout << graphPtr->insertGrapghArc(from, to) << "\n";
    *from = 20; *to = 15;
    cout << graphPtr->insertGrapghArc(from, to) << "\n";

    *from = 25; *to = 10;
    cout << graphPtr->insertGrapghArc(from, to) << "\n";
    *from = 25; *to = 20;
    cout << graphPtr->insertGrapghArc(from, to) << "\n";
    *from = 25; *to = 30;
    cout << graphPtr->insertGrapghArc(from, to) << "\n";
    *from = 25; *to = 15;
    cout << graphPtr->insertGrapghArc(from, to) << "\n";

    *from = 30; *to = 25;
    cout << graphPtr->insertGrapghArc(from, to) << "\n";

    graphPtr->displayVerticesDegrees();

    //cout << graphPtr->deleteGrapghArc(from, to) << "\n";

    graphPtr->displayVerticesDegrees();

    //breadth - first
    cout << "breadth first search :"; graphPtr->breadthFirstTraversal(); cout << "\n";

    //depth - first
    cout << "depth first search :";  graphPtr->depthFirstTraversal(); cout << "\n";

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
