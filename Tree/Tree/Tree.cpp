#include "Tree.h"
#include "TreeHead.h"
#include <iostream>
Tree::Tree() {
	this->tree = (TreeHead *) malloc (sizeof(TreeHead));
	this->tree->size   = 0;
	this->tree->height = 0;
}
bool Tree::isEmpty() {
	return !this->tree->size;
}
bool Tree::isFull() {
	return false;
}
int Tree::size() {
	return this->tree->size;
}
int Tree::height() {
	return this->tree->height;
}