// grpah - array based.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Vertex.h"
#include "Graph.h"
#include <algorithm>
using namespace std;
int main()
{
    std::cout << "Hello World!\n";
    Vertex* vector = new Vertex();
    char* vertex = (char*) malloc (sizeof (char) );
    *vertex = 'A';
    vector->vertexVector.push_back(vertex);
    vertex = (char*)malloc(sizeof(char));
    *vertex = 'B';
    vector->vertexVector.push_back(vertex);
    vertex = (char*)malloc(sizeof(char));
    *vertex = 'C';
    vector->vertexVector.push_back(vertex);
    vertex = (char*)malloc(sizeof(char));
    *vertex = 'D';
    vector->vertexVector.push_back(vertex);
    vertex = (char*)malloc(sizeof(char));
    *vertex = 'E';
    vector->vertexVector.push_back(vertex);
    vertex = (char*)malloc(sizeof(char));
    *vertex = 'F';
    vector->vertexVector.push_back(vertex);
    
    Graph* graph = new Graph(vector);
    char* fromVertex = (char*)malloc(sizeof(char));
    char* toVertex = (char*)malloc(sizeof(char));
    *fromVertex = 'A'; *toVertex = 'B';
    graph->addEdge(fromVertex, toVertex);

    fromVertex = (char*)malloc(sizeof(char));
    toVertex = (char*)malloc(sizeof(char));
    *fromVertex = 'B'; *toVertex = 'E';
    graph->addEdge(fromVertex, toVertex);

    fromVertex = (char*)malloc(sizeof(char));
    toVertex = (char*)malloc(sizeof(char));
    *fromVertex = 'B'; *toVertex = 'C';
    graph->addEdge(fromVertex, toVertex);

    fromVertex = (char*)malloc(sizeof(char));
    toVertex = (char*)malloc(sizeof(char));
    *fromVertex = 'C'; *toVertex = 'E';
    graph->addEdge(fromVertex, toVertex);

    fromVertex = (char*)malloc(sizeof(char));
    toVertex = (char*)malloc(sizeof(char));
    *fromVertex = 'C'; *toVertex = 'D';
    graph->addEdge(fromVertex, toVertex);

    fromVertex = (char*)malloc(sizeof(char));
    toVertex = (char*)malloc(sizeof(char));
    *fromVertex = 'E'; *toVertex = 'D';
    graph->addEdge(fromVertex, toVertex);

    fromVertex = (char*)malloc(sizeof(char));
    toVertex = (char*)malloc(sizeof(char));
    *fromVertex = 'E'; *toVertex = 'F';
    graph->addEdge(fromVertex, toVertex);

    graph->displayGraph();
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
