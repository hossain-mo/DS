#pragma once
#include "BinaryTree.h"
#include "HuffmanNode.h"
#include "List.h"
#include <string>
class HuffmanTree :
	public BinaryTree
{
	public :
	HuffmanTree(int (*compare)(int* argu1, int* argu2), int (*compareLetter)(void* argu1, void* argu2));
	void insert(char* dataPtr, int* freq);
	void build();
	void printCode();
	virtual ~HuffmanTree();
private:
	bool isOperator(char* token);
	bool isOpenningparenthes(char* token);
	bool isClosinggparenthes(char* token);
	HuffmanNode*  createNode(void* dataPtr, int* freq, HuffmanNode* left, HuffmanNode* right);
	List* huffmanTreeNodes;
	void printCode(HuffmanNode* root, std::string str);

};

