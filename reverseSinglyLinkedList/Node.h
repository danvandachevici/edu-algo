#ifndef NODE_H
#define NODE_H

#include <iostream>

using namespace std;

class Node {
    public:
        int payload;
        Node* next;
        Node(int payload);
};
#endif
