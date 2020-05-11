#include "BinaryTree.h"
#include "BinaryTreeHead.h"
#include "BinaryTreeNode.h"
#include <iostream>
#include <queue> 
BinaryTree::BinaryTree(){
	this->tree = (BinaryTreeHead*) malloc( sizeof(BinaryTreeHead) );
	this->tree->root = NULL;
	this->tree->height = 0;
	this->tree->size = 0;
}

void BinaryTree::inOrder(BinaryTreeNode* root) {
	if (root) {
		inOrder(root->left);
		this->tree->visit(root->dataPtr);
		inOrder(root->right);
	}
	return;
}

void BinaryTree::preOrder(BinaryTreeNode* root) {
	if (root) {
		this->tree->visit(root->dataPtr);
		preOrder(root->left);
		preOrder(root->right);
	}
	return;
}

void BinaryTree::postOrder(BinaryTreeNode* root) {
	if (root) {
		postOrder(root->left);
		postOrder(root->right);
		this->tree->visit(root->dataPtr);
	}
	return;
	
}
void BinaryTree::breadthFirst() {
	BinaryTreeNode* node = this->tree->root;
	std::queue <BinaryTreeNode *> nodes;
	while (node) {
		this->tree->visit(node);
		nodes.push(node->left);
		nodes.push(node->right);
		if (!nodes.empty())
			nodes.pop();
		else
			node = NULL;
	}
}