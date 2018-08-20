#include "Tree.h"

Node* Tree::recursiveSearch(Node* cur, int val) {
    if (cur == nullptr) {
        return nullptr;
    }
    if (cur->val() < val) {
        return this->recursiveSearch(cur->left(), val);
    }
    if (cur->val() > val) {
        return this->recursiveSearch(cur->right(), val);
    }
    return cur;
};
int Tree::recursiveInsert(Node* cur, int val) {
    Node* tmp;

    depth++;
    if (val < cur->val()) {
        if (cur->left() == nullptr) {
            tmp = new Node(val);
            cur->left(tmp);
            return 1;
        } else {
            return 1 + this->recursiveInsert(cur->left(), val);
        }
    } else {
        if (cur->right() == nullptr) {
            tmp = new Node(val);
            cur->right(tmp);
            return 1;
        } else {
            return 1 + this->recursiveInsert(cur->right(), val);
        }
    }
};

Tree::Tree() {
    this->count = 0;
    this->depth = 0;
    this->root = nullptr;
};
Tree::Tree(Node* root) {
    this->root = root;
    this->count = 1;
    this->depth = 1;
};
Tree::Tree(int val) {
    this->root = new Node(val);;
    this->count = 1;
    this->depth = 1;
};
bool Tree::findValue(int v) {
    Node* r = this->recursiveSearch(this->root, v);
    if (r == nullptr) {
        return false;
    }
    return true;
};
int Tree::getMaxDepth(int numberOfNodes) {
    int count = 0;
    int index = 0;
    int lastIndex = -1;

    while (numberOfNodes) {//while any bits are set not sure how you are getting the value

        if (numberOfNodes & 1) {
            count += index-lastIndex;
            lastIndex = index;
        }
        index++;
        numberOfNodes = numberOfNodes >> 1;
    }

    return count;
}
void Tree::insertValue(int val) {
    if (this->root == nullptr) {
        this->root = new Node(val);
        this->depth = 1;
    } else {
        int depth = this->recursiveInsert(this->root, val);
        this->depth = depth > this->depth ? depth : this->depth;
    }
    this->count ++;
//    int depthShouldBe = this->getMaxDepth(this->count);
//    if (depthShouldBe > depth) {
//        balanceTree();
//    }
};
int Tree::getNumberOfNodesAtLevel(int level) {
    return (2^(level-1));
}
void Tree::recursiveInorder(Node* node){
    if (node == nullptr) {
        return;
    }
    recursiveInorder(node->left());
    cout << node->val() << " ";
    recursiveInorder(node->right());
}
void Tree::inorder() {
    cout << endl;
    this->recursiveInorder(this->root);
    cout << endl;
}
