#pragma once
#include "Tree.h"
#include "BinaryTreeHead.h"
#include "BinaryTreeNode.h"
class BinaryTree :
	public Tree
{
public:
	BinaryTree();
	void inOrder();
	void preOrder();
	void postOrder();
	void breadthFirst();
	virtual ~BinaryTree();
	int  height();
	BinaryTreeHead* tree;

private:
	void inOrder(BinaryTreeNode* root);
	void preOrder(BinaryTreeNode* root);
	void postOrder(BinaryTreeNode* root);
protected:
	int height(BinaryTreeNode* root);

};

