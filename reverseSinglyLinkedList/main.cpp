#include "List.h"
#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int tmp[] = {10, 20, 30};
    List* l1 = new List(tmp, 3);
    l1->addItem(5);
    l1->addItem(-2);
    cout << "Initial list: ";
    l1->list();
    List* l2 = l1->reverse();
    cout << "Reversed list: ";
    l2->list();

    int tmp2[] = {l1->getFirstItem()->payload, l2->getFirstItem()->payload};
    List* l3 = new List(tmp2, 2);
    int counter = 1;
    Node* cur1 = l1->getFirstItem()->next;
    Node* cur2 = l2->getFirstItem()->next;
    while (counter < l1->size/2) {
        l3->addItem(cur1->payload);
        l3->addItem(cur2->payload);
        cur1 = cur1->next;
        cur2 = cur2->next;
        counter ++;
    }
    if (l1->size%2 == 1) {
        l3->addItem(cur1->payload);
    }
    cout << "Final list: ";
    l3->list();

    return 0;
}
