#include "Vertex.h"
Vertex::Vertex() {

}
int Vertex::find(void* data) {
	
	for (int i = 0; i < this->vertexVector.size(); i++) {
		if (*(char *)data == *(char *)(this->vertexVector[i]))
			return i;
	}
}

