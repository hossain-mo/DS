#include "Tree.h"
#include "TreeHead.h"
#include "BinaryTreeNode.h"
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

void Tree::increaseSize() {
	this->tree->size++;
}
Tree::~Tree()
{
}
void Tree::increaseHeight() {
	this->tree->height++;
}
void Tree::decreaseSize() {
	this->tree->size--;
}