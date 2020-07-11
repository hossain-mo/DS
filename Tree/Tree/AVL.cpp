#include "AVL.h"
#include <iostream>
AVL::AVL(int (*compare)(int* argu1, int* argu2), void(*visit)(void* argu1)) : 
	BST::BST(compare,visit) {
	
}
void AVL::addNode(BinaryTreeNode*& root, BinaryTreeNode*& node) {
	if (!root) {
		root = node;
		return;
	}
	if (this->tree->compare((int*)node->dataPtr, (int*)root->dataPtr) == 1) {
		this->addNode(root->right, node);
		if (this->height(root->right) > this->height(root->left) && this->size() > 1)
			       this->rightBalance(root);
	}
	else {
		 this->addNode(root->left, node);
		 if (this->height(root->left) > this->height(root->right) && this->size() > 1)
			      this->leftBalance(root);
	}

}
void AVL::leftBalance(BinaryTreeNode*& root) {
	if (this->height(root->right) > this->height(root->left))
		this->rotateLeft(root->left);
		this->rotateRight(root);
}
void AVL::rightBalance(BinaryTreeNode*& root) {
	if (this->height(root->right) < this->height(root->left) )
		this->rotateRight(root->right);
	this->rotateLeft(root);
}
void AVL::rotateLeft(BinaryTreeNode*& root) {
	BinaryTreeNode* oldRoot = root;
	root = root->right;
	oldRoot->right = root->left;
	root->left = oldRoot;
}
void AVL::rotateRight(BinaryTreeNode*& root) {
	BinaryTreeNode* oldRoot = root;
	root = root->left;
	oldRoot->left = root->right;
	root->right = oldRoot;
}
void AVL::remove(void* dataPtr) {
	BST::remove(dataPtr);
	if (this->height(this->tree->root->right) > this->height(this->tree->root->left) && this->size() > 1)
		this->rightBalance(this->tree->root);
	else if(this->height(this->tree->root->right) < this->height(this->tree->root->left) && this->size() > 1)
		this->leftBalance(this->tree->root);
}

AVL::~AVL() {

}