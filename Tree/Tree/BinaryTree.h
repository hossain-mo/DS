#pragma once
#include "Tree.h"
#include "BinaryTreeHead.h"
#include "BinaryTreeNode.h"
class BinaryTree :
	public Tree
{
public:
	BinaryTree();
	void inOrder(BinaryTreeNode* root);
	void preOrder(BinaryTreeNode* root);
	void postOrder(BinaryTreeNode* root);
	void breadthFirst();
	virtual ~BinaryTree();
	BinaryTreeHead* tree;

};

