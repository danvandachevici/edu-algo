#include "List.h"

List::List(int vals[], int length) {
    this->root = new Node(vals[0]);
    Node* cur = this->root;
    for (int i = 1; i < length; i++) {
        Node* newNode = new Node(vals[i]);
        cur->next = newNode;
        cur = cur->next;
    }
    this->size = length;
    this->last = cur;
}
Node* List::getLastItem(){
    return this->last;
}
Node* List::getFirstItem(){
    return this->root;
}
void List::addItem(int val) {
    Node* newItem = new Node(val);
    this->size ++;
    this->last->next = newItem;
    this->last = newItem;
}
void List::unshiftItem(int val) {
    Node* newItem = new Node(val);
    this->size ++;
    newItem->next = this->root;
    this->root = newItem;
}
void List::list() {
    Node* cur = this->root;
    cout << "List: ";
    while (cur != nullptr) {
        cout << cur->payload << "->";
        cur = cur->next;
    }
    cout << "NULL"<<endl;
}
List* List::reverse() {
    int p[] = {this->root->payload};
    List* newlist = new List(p, 1);
    Node* cur = this->root;
    while (cur->next != nullptr) {
        cur = cur->next;
        newlist->unshiftItem(cur->payload);
    }
    return newlist;
}
