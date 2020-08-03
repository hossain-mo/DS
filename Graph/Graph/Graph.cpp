#include "Graph.h"
#include <iostream>
#include <list> 
#include <string>

Graph::Graph(int compare(void* argu1, void* argu2), void visit(void* argu)) {
	this->compare = compare;
	this->visit = visit;
	this->size = 0;
	this->first = NULL;
}
//pre: graph has been created
//post: return predecessor of a vertex
vertex* Graph::search(void* dataPtr, vertex*& locPtr) {
	locPtr = this->first;
	vertex* predPtr = NULL;
	while (locPtr && this->compare(dataPtr, locPtr->data) > 0) {
		predPtr = locPtr;
		locPtr = locPtr->next;
	}
	return predPtr;
}
// pre: grapgh has been created
// post: return a data pointer of the vertex if it found else return null
void* Graph::search(void* dataPtr) {
	vertex* locPtr = this->first;
	vertex* predPtr = NULL;
	while (locPtr && this->compare(dataPtr, locPtr->data) > 0) {
		predPtr = locPtr;
		locPtr = locPtr->next;
	}
	return locPtr ? locPtr->data : locPtr;
}
// pre: grapgh has been created
// post : vertix pushed in vertices list
void Graph::insertVertex(void* dataPtr) {
	vertex* newVertex = new vertex(dataPtr);
	this->size++;
	if (!this->first)
		this->first = newVertex;
	else {
		vertex* locPtr;
		vertex* predPtr = this->search(dataPtr, locPtr);
		if (!predPtr)
			this->first = newVertex;
		else
			predPtr->next = newVertex;
		newVertex->next = locPtr;
	}
	return;
}
// pre: graph has been created
//post: delete vertex if it found and its degree is 0
void Graph::deleteVertex(void* dataPtr) {
	if (!this->first)
		return;
	vertex* locPtr;
	vertex* predPtr = this->search(dataPtr, locPtr);
	if (!locPtr || this->compare(dataPtr, locPtr->data) != 0)
		return;
	if (locPtr->indegree > 0 || locPtr->outdegree > 0)
		return;
	if (!predPtr)
		this->first = locPtr->next;
	else
		predPtr->next = locPtr->next;
	free(locPtr);
	this->size--;
	return;
}
// pre: nothing
//post :return graph size
int Graph::count() {
	return this->size;
}
//pre: grapgh created
//post: return true if arc is inserted , false if it not created
bool Graph::insertGrapghArc(void* dataFromPtr, void* dataToPtr) {
	arc* newArc = new arc();
	vertex* fromVertex;
	this->search(dataFromPtr, fromVertex);
	if (!fromVertex && this->compare(dataFromPtr, fromVertex->data) != 0)
		return false;
	vertex* toVertex;
	this->search(dataToPtr, toVertex);
	if (!toVertex && this->compare(dataToPtr, toVertex->data) != 0)
		return false;
	fromVertex->outdegree++;
	toVertex->indegree++;
	newArc->dest = toVertex;
	if (!fromVertex->pArc) {
		fromVertex->pArc = newArc;
		newArc->next = NULL;
		return true;
	}
	arc* arcLocPtr = fromVertex->pArc;
	arc* arcPredPtr = this->searchArc(dataToPtr, arcLocPtr, true);
	if (!arcPredPtr)
		fromVertex->pArc = newArc;
	else
		arcPredPtr->next = newArc;
	newArc->next = arcLocPtr;
	return true;
}
//pre: graph was created
//post: return arc if it found and null if not
arc* Graph::searchArc(void* dataPtr, arc*& arcLocPtr, bool forInsert) {
	arc* arcPredPtr = new arc();
	int resault = this->compare(dataPtr, ((vertex*)(arcLocPtr->dest))->data);
	bool compareResault = forInsert ? resault >= 0 : resault > 0;
	while (arcLocPtr && compareResault) {
		arcPredPtr = arcLocPtr;
		arcLocPtr = arcLocPtr->next;
	}
	return arcPredPtr;
}
//pre : graph was created 
//post delete arc if it found and return true , else false
bool Graph::deleteGrapghArc(void* dataFromPtr, void* dataToPtr) {
	vertex* fromVertex;
	this->search(dataFromPtr, fromVertex);
	if (!fromVertex && this->compare(dataFromPtr, fromVertex->data) != 0 && !fromVertex->pArc)
		return false;
	arc* arcLocPtr = fromVertex->pArc;
	arc* arcPredPtr = this->searchArc(dataToPtr, arcLocPtr, false);
	//search if arc has end vertex or not
	if (!arcLocPtr || this->compare(dataToPtr, ((vertex*)(arcLocPtr->dest))->data) != 0) {
		return false;
	}
	vertex* toVertex = (vertex*)arcLocPtr->dest;
	--fromVertex->outdegree;
	--toVertex->indegree;
	if (!arcPredPtr)
		fromVertex->pArc = arcLocPtr->next;
	else
		arcPredPtr->next = arcLocPtr->next;
	free(arcLocPtr);
	return true;
}
//pre: graph was declared
// post: graph vertices degrees was out;
void Graph::displayVerticesDegrees() {
	vertex* walker = this->first;
	while (walker) {
		std::cout << *(int*)walker->data << "  in: " << walker->indegree << "    out: " << walker->outdegree << "\n";
		walker = walker->next;
	}
}
//pre: graph was declared
// post: graph was traversed;
void Graph::traverse(std::string traverseType) {
	if (!this->first)
		return;
	std::list <vertex *> ds;
	vertex* walkerPtr = this->first;
	vertex* vertexPtr = (vertex*) malloc (sizeof (vertex) );
	vertex* vertexToPtr;
	arc* arcWalkerPtr;
	while (walkerPtr) {
		if (walkerPtr->processed == 0) {
			ds.push_back(walkerPtr);
			walkerPtr->processed = 1;
		}
		while (!ds.empty()) {
			if (traverseType == "depth"){
				vertexPtr = ds.back(); ds.pop_back();
			}
			else {
				vertexPtr = ds.front(); ds.pop_front();
			}
			this->visit(vertexPtr->data);
			vertexPtr->processed = 2;
			arcWalkerPtr = vertexPtr->pArc;
			while (arcWalkerPtr) {
				vertexToPtr = (vertex *)arcWalkerPtr->dest;
				if (vertexToPtr->processed == 0) {
					ds.push_back(vertexToPtr);
					vertexToPtr->processed = 1;
				}
				arcWalkerPtr = arcWalkerPtr->next;
			}
		}
		walkerPtr = walkerPtr->next;
	}
	return;
}

void Graph::breadthFirstTraversal() {
	this->setProcessFlagNotProcessed();
	this->traverse("breadth");
}
void Graph::depthFirstTraversal() {
	this->setProcessFlagNotProcessed();
	this->traverse("depth");
}
void Graph::setProcessFlagNotProcessed() {
	vertex* walkerPtr = this->first;
	while (walkerPtr){
		walkerPtr->processed = 0;
		walkerPtr = walkerPtr->next;
	}
}

Graph::~Graph() {

}
