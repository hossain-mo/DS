#pragma once
#include "BST.h"
class AVL :
    public BST
{
public:
    AVL(int (*compare)(int* argu1, int* argu2), void(*visit)(void* argu1));
    void remove(void* dataPtr);
    virtual ~AVL();
private:
     void addNode(BinaryTreeNode*& root, BinaryTreeNode*& node);
     void leftBalance(BinaryTreeNode*& root);
     void rightBalance(BinaryTreeNode*& root);
     void rotateLeft(BinaryTreeNode*& root);
     void rotateRight(BinaryTreeNode*& root);
};

