#ifndef BINARYTREE_H
#define BINARYTREE_H

#include"global.h"

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};


class BinaryTree
{
public:
    BinaryTree();
    ~BinaryTree();

    void insert(int value);
    bool search(int value);
    void remove(int value);
    void printInorder();

private:
    TreeNode* root;
    // TreeNode* insert(TreeNode* node, int value);
    // TreeNode* search(TreeNode* node, int value);
    // TreeNode* remove(TreeNode* node, int value);
    void printInorder(TreeNode* node);
    void deleteTree(TreeNode* node);
};

#endif // BINARYTREE_H
