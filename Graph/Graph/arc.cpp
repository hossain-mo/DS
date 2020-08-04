#include "arc.h"
#include "iostream"
arc::arc(int weight) {
	this->next = NULL;
	this->dest = NULL;
	this->weight = weight;
}
