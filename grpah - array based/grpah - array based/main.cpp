// grpah - array based.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Vertex.h"
#include "Graph.h"
#include <algorithm>
using namespace std;
void visit(void* argu) {
    cout << *(char*)argu << "   ";
}
int compareEdges(const Edge* firstEdge, const Edge* secondEdge) {

    return firstEdge->weight < secondEdge->weight;

}

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
    cout << endl;
    //depth- first traverse
    cout << "depth - first traverse  :"; graph->depthFirstTraversal(visit); cout << endl;

    //vreadth- first traverse
    cout << "breadth - first traverse  :"; graph->breadthFirstTraversal(visit); cout << endl;

    //2)networks (weighted graphs)
    vertex = (char*)malloc(sizeof(char));
    *vertex = 'G';
    vector->vertexVector.push_back(vertex);

    vertex = (char*)malloc(sizeof(char));
    *vertex = 'H';
    vector->vertexVector.push_back(vertex);

    vertex = (char*)malloc(sizeof(char));
    *vertex = 'K';
    vector->vertexVector.push_back(vertex);

    cout << endl << "network :"<<endl;
    Graph* network = new Graph(vector);
    fromVertex = (char*)malloc(sizeof(char));
    toVertex = (char*)malloc(sizeof(char));
    *fromVertex = 'A'; *toVertex = 'B';
    network->addEdge(fromVertex, toVertex, 4);

    fromVertex = (char*)malloc(sizeof(char));
    toVertex = (char*)malloc(sizeof(char));
    *fromVertex = 'A'; *toVertex = 'H';
    network->addEdge(fromVertex, toVertex, 8);

    fromVertex = (char*)malloc(sizeof(char));
    toVertex = (char*)malloc(sizeof(char));
    *fromVertex = 'B'; *toVertex = 'C';
    network->addEdge(fromVertex, toVertex, 8);

    fromVertex = (char*)malloc(sizeof(char));
    toVertex = (char*)malloc(sizeof(char));
    *fromVertex = 'B'; *toVertex = 'H';
    network->addEdge(fromVertex, toVertex, 11);

    fromVertex = (char*)malloc(sizeof(char));
    toVertex = (char*)malloc(sizeof(char));
    *fromVertex = 'C'; *toVertex = 'F';
    network->addEdge(fromVertex, toVertex, 4);

    fromVertex = (char*)malloc(sizeof(char));
    toVertex = (char*)malloc(sizeof(char));
    *fromVertex = 'C'; *toVertex = 'D';
    network->addEdge(fromVertex, toVertex, 7);

    fromVertex = (char*)malloc(sizeof(char));
    toVertex = (char*)malloc(sizeof(char));
    *fromVertex = 'C'; *toVertex = 'K';
    network->addEdge(fromVertex, toVertex, 2);

    fromVertex = (char*)malloc(sizeof(char));
    toVertex = (char*)malloc(sizeof(char));
    *fromVertex = 'D'; *toVertex = 'E';
    network->addEdge(fromVertex, toVertex, 9);

    fromVertex = (char*)malloc(sizeof(char));
    toVertex = (char*)malloc(sizeof(char));
    *fromVertex = 'D'; *toVertex = 'F';
    network->addEdge(fromVertex, toVertex, 14);

    fromVertex = (char*)malloc(sizeof(char));
    toVertex = (char*)malloc(sizeof(char));
    *fromVertex = 'E'; *toVertex = 'F';
    network->addEdge(fromVertex, toVertex, 10);

    fromVertex = (char*)malloc(sizeof(char));
    toVertex = (char*)malloc(sizeof(char));
    *fromVertex = 'H'; *toVertex = 'K';
    network->addEdge(fromVertex, toVertex, 7);

    fromVertex = (char*)malloc(sizeof(char));
    toVertex = (char*)malloc(sizeof(char));
    *fromVertex = 'H'; *toVertex = 'G';
    network->addEdge(fromVertex, toVertex, 1);

    fromVertex = (char*)malloc(sizeof(char));
    toVertex = (char*)malloc(sizeof(char));
    *fromVertex = 'K'; *toVertex = 'G';
    network->addEdge(fromVertex, toVertex, 6);

    fromVertex = (char*)malloc(sizeof(char));
    toVertex = (char*)malloc(sizeof(char));
    *fromVertex = 'G'; *toVertex = 'F';
    network->addEdge(fromVertex, toVertex, 2);

    network->displayGraph();
    cout << endl;
    //depth- first traverse
    cout << "depth - first traverse  :"; network->depthFirstTraversal(visit); cout << endl;

    //breadth- first traverse
    cout << "breadth - first traverse  :"; network->breadthFirstTraversal(visit); cout << endl;


     // graph applications 
    //1) minimum spanning tree using prime
    cout << "minimum spanning tree   :\n"; network->minimumSpanningTree(visit); cout << endl;
    // by complixty O(n^2)
    cout << "minimum spanning tree   :\n"; network->prime(visit); cout << endl;
    // minimum spannig tree using kruskal
    cout << "minimum spanning tree   :\n"; network->kruskal(visit, compareEdges); cout << endl;
    //2) shortest path
    cout << "shortest path  :\n"; network->shortestPath(visit);
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
