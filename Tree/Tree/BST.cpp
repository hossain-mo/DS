#include "BST.h"
#include <iostream>
BST::BST(int (*compare)(int* argu1, int* argu2), void(*visit)(void* argu1)): BinaryTree::BinaryTree() {
	this->tree->compare = compare;
	this->tree->visit = visit;
}
void BST::addNode(BinaryTreeNode*& root, BinaryTreeNode*& node) {
	if (!root) {
		root = node;
		return;
	}
	if (this->tree->compare((int*)node->dataPtr, (int*)root->dataPtr) == 1)
		return this->addNode(root->right, node);
	else 
		return this->addNode(root->left, node);

}
void BST::insert(void* dataPtr) {
	BinaryTreeNode* node = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
	node->dataPtr = dataPtr;
	node->left = node->right = NULL;
	this->addNode(this->tree->root, node);
	this->increaseSize();

}
BinaryTreeNode* BST::search(BinaryTreeNode*& root, BinaryTreeNode*& node, BinaryTreeNode*& parent, void* dataPtr) {
	if (!root)
		return parent;
	int result = this->tree->compare((int*)dataPtr, (int*)root->dataPtr);
	if (result == 1)
		return this->search(root->right, node, root, dataPtr);
	if (result == -1) 
		return this->search(root->left, node, root, dataPtr);
	else {
		node = root;
		return parent;
	}
		
}
void BST::remove(void* dataPtr) {
	BinaryTreeNode* node = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
	BinaryTreeNode* parent = this->tree->root;
	node->dataPtr = dataPtr;
	node->left = node->right = NULL;

	parent = this->search(this->tree->root, node, parent, dataPtr);
	int result = this->tree->compare((int*)node->dataPtr, (int*)parent->dataPtr);
	if (!node->left && !node->right) {
		if (result == 1)
			parent->right = NULL;
		else
			parent->left = NULL;
		free(node);
	}
	else if (node->left && !node->right) {
		if (result == 1) 
			parent->right = node->left;
		else 
			parent->left = node->left;
		free(node);
	}
	else if (!node->left && node->right) {
		if (result == 1)
			parent->right = node->right;
		else
			parent->left = node->right;
		free(node);
	}
	else {
		BinaryTreeNode* deletedNode = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
		BinaryTreeNode* parent = this->exchangeNodes(node,deletedNode);
		if (parent->right == deletedNode)
			parent->right = deletedNode->right;
		else
			parent->left = deletedNode->right;
		free(deletedNode);
	}
	this->decreaseSize();
}
BinaryTreeNode* BST::exchangeNodes(BinaryTreeNode*& node, BinaryTreeNode*& deletedNode) {
	void* deletedNodeDataPtr = NULL;
	void* holdPtr = NULL;
	deletedNodeDataPtr = this->findLargest(node->left);
	BinaryTreeNode* parent = node;
	parent = this->search(node, deletedNode, parent, deletedNodeDataPtr);
	holdPtr = node->dataPtr;
	node->dataPtr = deletedNode->dataPtr;
	deletedNode->dataPtr = holdPtr;
	return parent;
}

void* BST::findLargest(BinaryTreeNode* root) {
	while (root->right) 
		root = root->right;
	return root->dataPtr;
}
void* BST::findLargest() {
	return this->findLargest(this->tree->root);
}
void* BST::findSmallest() {
	BinaryTreeNode* root = this->tree->root;
	while (root->left)
		root = root->left;
	return root->dataPtr;
}

BST::~BST() {

}