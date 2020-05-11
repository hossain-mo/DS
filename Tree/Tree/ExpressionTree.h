#pragma once
#include "BinaryTree.h"
#include <string>
class ExpressionTree :
	public BinaryTree
{
public :
	ExpressionTree();
	void build(std::string experssion);
};

