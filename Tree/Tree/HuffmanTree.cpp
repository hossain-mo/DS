#include "HuffmanTree.h"
#include <iostream>
#include "HuffmanNode.h"
HuffmanTree::HuffmanTree(int (*compare)(int* argu1, int* argu2), int (*compareLetter)(void* argu1, void* argu2)) :BinaryTree::BinaryTree() {
	this->huffmanTreeNodes = new List(compare, compareLetter);
	this->tree->compare = compare;
}
void HuffmanTree::insert(char* dataPtr, int* freq) {
	HuffmanNode* node = new HuffmanNode();
	char* voidDataPtr = (char*)malloc(sizeof(char));
	*voidDataPtr = *(char*)dataPtr;
	node->dataPtr = voidDataPtr;
	node->frequency = freq;
	node->left = node->right = NULL;
	this->huffmanTreeNodes->insert(dataPtr, freq,NULL,NULL);
}
HuffmanNode* HuffmanTree::createNode(void* dataPtr, int* freq, HuffmanNode* left, HuffmanNode* right) {
	HuffmanNode* node = new HuffmanNode();
	node->frequency = freq;
	node->dataPtr = dataPtr;
	node->left = left;
	node->right = right;
	return node;
}
void HuffmanTree::build() {
	HuffmanNode* root = new HuffmanNode();
	HuffmanNode* fNode = new HuffmanNode();
	HuffmanNode* sNode = new HuffmanNode();
	while (this->huffmanTreeNodes->count() > 1) {
		char* fDataPtr = (char*)malloc(sizeof(char));
		char* sDataPtr = (char*)malloc(sizeof(char));
		fNode = this->huffmanTreeNodes->front();   this->huffmanTreeNodes->remove(fNode->dataPtr);
		sNode = this->huffmanTreeNodes->front();   this->huffmanTreeNodes->remove(sNode->dataPtr);
		int* sum = (int*)malloc(sizeof(int));
		*sum = *fNode->frequency + *sNode->frequency;
		char* rootDataPtr = (char*)malloc(sizeof(char));
		root = this->createNode(rootDataPtr, sum, fNode, sNode);
		this->huffmanTreeNodes->insert(root->dataPtr , root->frequency , root->left , root->right);

	}
}
void HuffmanTree::printCode() {
	this->printCode(this->huffmanTreeNodes->front(),"");

}
void HuffmanTree::printCode(HuffmanNode* root,std::string str) {
	if (!root)
		return;
	if(!root->left) {
		std::cout << *(char*)root->dataPtr <<"     code:" << str<< "\n";
	}
	this->printCode(root->left,str+"0");
	this->printCode(root->right,str+"1");


}
HuffmanTree::~HuffmanTree() {

}