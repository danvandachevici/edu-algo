#include "Tree.h"

int main() {
    Tree* bst = new Tree();
    bst->insertValue(5);
    bst->insertValue(3);
    bst->insertValue(1);
    bst->insertValue(4);
    bst->insertValue(8);
    bst->insertValue(6);
    bst->insertValue(10);
    bst->inorder();
    return 0;
};
