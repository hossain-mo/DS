#include "ExpressionTree.h"
#include <stack>
#include <iostream>
ExpressionTree::ExpressionTree() :BinaryTree::BinaryTree() {

}
ExpressionTree::ExpressionTree(void(*visit)(void* argu1)) : BinaryTree::BinaryTree() {
	this->tree->visit = visit;
}


bool ExpressionTree::isOperator(char * token) {
	if (*token == '-' || *token == '+' || *token == '/' || *token == '*')
		return true;
	return false;
}

bool ExpressionTree::isOpenningparenthes(char* token) {
	return *token == '(';
}

bool ExpressionTree::isClosinggparenthes(char* token) {
	return *token == ')';
}
BinaryTreeNode* ExpressionTree::createNode(void* dataPtr) {
	BinaryTreeNode* node = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
	node->dataPtr = dataPtr;
	node->left = node->right = NULL;
	this->increaseSize();
	return node;
}
void ExpressionTree::build(std::string expression) {
	std::stack<BinaryTreeNode*> operands;
	std::stack<BinaryTreeNode*> operators;
	for (int i = 0; i < expression.length(); i++) {
		if (!this->isClosinggparenthes(&expression[i])) {
			if (!isOpenningparenthes(&expression[i]) && this->isOperator(&expression[i])) {
				char* element = (char*)malloc(sizeof(char));
				*element = expression[i];
				operators.push(this->createNode(element));
			}
			//operand
			else if (!isOpenningparenthes(&expression[i])) {
				char* element = (char*)malloc(sizeof(char));
				*element = expression[i];
				operands.push(this->createNode(element));
			}
		}
		else {
			while (!operators.empty()) {
				BinaryTreeNode* operatorNode = operators.top(); operators.pop();
				BinaryTreeNode* rightOperand = operands.top(); operands.pop();
				BinaryTreeNode* leftOperand = operands.top(); operands.pop();
				operatorNode->right = rightOperand;
				operatorNode->left  = leftOperand;
				operands.push(operatorNode);
			}
		}
	}
	while (!operators.empty()) {
		BinaryTreeNode* operatorNode = operators.top(); operators.pop();
		BinaryTreeNode* rightOperand = operands.top(); operands.pop();
		BinaryTreeNode* leftOperand = operands.top(); operands.pop();
		operatorNode->right = rightOperand;
		operatorNode->left = leftOperand;
		operands.push(operatorNode);
	}
	this->tree->root = operands.top();
}
ExpressionTree::~ExpressionTree() {

}