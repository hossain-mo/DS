#include "Graph.h"
#include <vector>
#include <iostream>
using namespace std;
Graph::Graph(Vertex* vector) {
    this->vector = vector;
    int size = this->vector->vertexVector.size();
    for (int i = 0; i < size; i++) {
        std::vector <int> v;

        for (int i = 0; i < size; i++) {
            v.push_back(0);
        }
        this->adjacencyMatrix.push_back(v);
    }
    }
    
void Graph::addEdge(void* fromVertex, void* toVertex) {
    int fromIndex = this->vector->find(fromVertex);
    int toIndex   = this->vector->find(toVertex);
    this->adjacencyMatrix[fromIndex][toIndex] = 1;
    this->adjacencyMatrix[toIndex][fromIndex] = 1;
}
void Graph::displayGraph() {
    int i, j;
    int length = this->vector->vertexVector.size();
    for (i = 0; i < length; i++) {
        cout << "     "  << *(char*)this->vector->vertexVector[i];
    }cout << endl;
    for (i = 0; i < length ; i++) {
        cout << *(char *) this->vector->vertexVector[i] << "    ";
        for (j = 0; j < length; j++) {
            cout << this->adjacencyMatrix[i][j] << "     ";
        }
        cout << endl;
    }
}
