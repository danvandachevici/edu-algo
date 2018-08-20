#ifndef NODE_H
#define NODE_H

#include <iostream>
using namespace std;

class Node {
    private:
        int value;
        Node* leftChild;
        Node* rightChild;
        Node* father;
    public:
        Node();
        Node(int v);
        int val();
        Node* left();
        Node* right();
        Node* parent();
        void left(Node* l);
        void right(Node* r);
        void parent(Node* p);
};

#endif
