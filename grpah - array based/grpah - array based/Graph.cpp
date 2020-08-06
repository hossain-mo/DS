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
    
void Graph::addEdge(void* fromVertex, void* toVertex, int weight) {
    int fromIndex = this->vector->find(fromVertex);
    int toIndex   = this->vector->find(toVertex);
    this->adjacencyMatrix[fromIndex][toIndex] = weight;
    this->adjacencyMatrix[toIndex][fromIndex] = weight;
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
            if (this->adjacencyMatrix[currentIndex][i] && (!isVisited[i])) {

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
void Graph::minimumSpanningTree(void visit(void* argu)) {
    int numberOfVertices = this->vector->vertexVector.size();
    std::vector <bool> isVisited(numberOfVertices, false);
    int edges = 0;
    isVisited[0] = true;
    while (edges < numberOfVertices - 1) {
        int min = INT_MAX;
        int x = 0, y = 0;
        for (int i = 0; i < numberOfVertices; i++) {
            if (isVisited[i]) {
                for (int j = 0; j < numberOfVertices; j++) {
                    if ((!isVisited[j] && this->adjacencyMatrix[i][j]) && min > this->adjacencyMatrix[i][j]) {
                        min = this->adjacencyMatrix[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }
        visit(this->vector->vertexVector[x]);
        visit(this->vector->vertexVector[y]);
        std::cout << "  : " << min << endl;
        isVisited[y] = true;
        edges++;
    }
    return;
}

void Graph::shortestPath(void visit(void* argu)) {
    int numberOfVertices = this->vector->vertexVector.size();
    std::vector <bool> isVisited(numberOfVertices, false);
    std::vector <std::vector<int>> paths(numberOfVertices-1, std::vector<int>(3));
    int edges = 0;
    isVisited[0] = true;
    int total = 0;
    while (edges < numberOfVertices - 1) {
        int min = INT_MAX;
        int x = 0, y = 0;
        for (int i = 0; i < numberOfVertices; i++) {
            if (isVisited[i]) {
                for (int j = 0; j < numberOfVertices; j++) {
                    if ((!isVisited[j] && this->adjacencyMatrix[i][j]) && min > this->adjacencyMatrix[i][j]) {
                        min = this->adjacencyMatrix[i][j];
                        
                        x = i;
                        y = j;
                    }
                }
            }
        }
        total += min;
        paths[edges][0] = x;
        paths[edges][1] = y;
        paths[edges][2] = min;
        isVisited[y] = true;
        edges++;
        //update new weights
        for (int k = 0; k < numberOfVertices; k++) {
            if (!isVisited[k] && this->adjacencyMatrix[y][k]) {
                this->adjacencyMatrix[y][k] += min;
            }
        }
    }
    

    for (int i = 0; i < numberOfVertices - 1; i++) {
        visit(this->vector->vertexVector[paths[i][0]]);
        visit(this->vector->vertexVector[paths[i][1]]); cout << "distance from source  : " << paths[i][2] << endl;
    }
    return;
}

