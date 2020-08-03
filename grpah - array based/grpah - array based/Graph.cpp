#include "Graph.h"
#include <vector>
#include <list>
#include <iostream>
#include <string>

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
void Graph::traverse(void visit(void* argu), string traverseType) {
    std::vector <bool> isVisited(this->vector->vertexVector.size(),false);

    list <void*> ds;
    ds.push_back(this->vector->vertexVector.front());
    void* currentVertex = (void *) malloc (sizeof (void*) );
    while (!ds.empty()) {
        if (traverseType == "depth") {
            currentVertex = ds.back(); ds.pop_back();
        }
        else {
            currentVertex = ds.front(); ds.pop_front();
        }
        visit(currentVertex);
        int currentIndex = this->vector->find(currentVertex);
        isVisited[currentIndex] = true;
        // For every adjacent vertex to the current vertex 
        for (int i = 0; i < this->vector->vertexVector.size(); i++) {
            if (this->adjacencyMatrix[currentIndex][i] == 1 && (!isVisited[i])) {

                // Push the adjacent node to the queue 
                ds.push_back(this->vector->vertexVector[i]);
                // Set 
                isVisited[i] = true;
            }
        }
    }
}

void Graph::breadthFirstTraversal(void visit(void* argu)) {
    this->traverse(visit,"breadth");
}
void Graph::depthFirstTraversal(void visit(void* argu)) {
    this->traverse(visit,"depth");
}
