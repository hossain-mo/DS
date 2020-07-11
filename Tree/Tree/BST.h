#pragma once
#include "BinaryTree.h"
class BST :
	public BinaryTree
{
public:
	BST(int (*compare)(int* argu1, int* argu2), void(*visit)(void* argu1));
	void insert(void* dataPtr);
	virtual void remove(void* dataPtr);
	void* findLargest();
	void* findSmallest();
	virtual ~BST();
protected:
	virtual void  addNode(BinaryTreeNode*& root, BinaryTreeNode*& node);
	//return parent of node
	BinaryTreeNode* search(BinaryTreeNode*& root, BinaryTreeNode*& node, BinaryTreeNode*& parent, void* dataPtr);
	void* findLargest(BinaryTreeNode* root);
	//return parent of exchanged node
	BinaryTreeNode* exchangeNodes(BinaryTreeNode*& node, BinaryTreeNode*& deletedNode);

};

