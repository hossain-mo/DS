#pragma once
#include "BinaryTree.h"
#include <string>
class ExpressionTree :
	public BinaryTree
{
public :
	ExpressionTree();
	ExpressionTree(void(*visit)(void* argu1));
	void build(std::string experssion);
	virtual ~ExpressionTree();
private:
	bool isOperator(char* token);
	bool isOpenningparenthes(char* token);
	bool isClosinggparenthes(char* token);
	BinaryTreeNode* createNode(void* dataPtr);
};

