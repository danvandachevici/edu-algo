#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <vector>
#include "Node.h"

using namespace std;

class List {
    private:
        Node* root;
        Node* last;
    public:
        int size;
        List(int vals[], int length);
        void addItem(int val);
        void unshiftItem(int val);
        Node* getLastItem();
        Node* getFirstItem();
        void list();
        List* reverse();
};
#endif
