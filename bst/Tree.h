#ifndef TREE_H
#define TREE_H

#include "Node.h"

class Tree {
    private: 
        int count;
        int depth;
        Node* recursiveSearch(Node* cur, int val);
        int recursiveInsert(Node* cur, int val);
        void recursiveInorder(Node* node);
        void levelTree(Node* node);
        int countBits(int numberOfNodes);
        int getMaxDepth(int numberOfNodes);
        int getNumberOfNodesAtLevel(int level);
    public:
        Node* root;
        Tree();
        Tree(Node* root);
        Tree(int val);
        bool findValue(int v);
        void insertValue(int v);
        void removeValue(int v);
        void inorder();
        //void printInOrder();
        //void printPreOrder();
        //void printPostOrder();
        //void printBreadthFirst();
        //void printDepthFirst();
};

#endif
