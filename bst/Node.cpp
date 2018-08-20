#include "Node.h"

Node::Node() {
    this->value = -1;
    this->father = nullptr;
    this->leftChild = nullptr;
    this->rightChild = nullptr;
}
Node::Node(int v) {
    this->value = v;
    this->father = nullptr;
    this->leftChild = nullptr;
    this->rightChild = nullptr;
};
int Node::val() {
    return this->value;
};
Node* Node::left() {
    return this->leftChild;
};
Node* Node::right() {
    return this->rightChild;
};
Node* Node::parent() {
    return this->father;
};
void Node::left(Node* l) {
    this->leftChild = l;
    this->leftChild->father = this;
};
void Node::right(Node* r) {
    this->rightChild = r;
    this->rightChild->father = this;
};
void Node::parent(Node* p) {
    this->father = p;
    if (this->val() < p->val()) {
        p->left(this);
    } else {
        p->right(this);
    }
}
