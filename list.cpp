#include <cstddef>
#include<iostream>
using namespace std;

struct node {
  int val = 0;
  node *next = NULL;
};

int main () {
    // simply creating a list
    node *n;
    n = new node;

    n->val = 2;
    n->next = new node;

    n->next->val = 3;
    n->next->next = new node;

    n->next->next->val = 5;

    cout<<n->next->next->val<<endl;

    // using another pointer for ease

    node *head; node *current;

    head = new node;
    head->val = 2;

    current = new node;
    head->next = current;
    current->val = 3;
    current->next = NULL;

    node *temp = current;

    current = new node;
    current->val = 5;
    current->next = NULL;

    temp->next = current;


    current = head;
    while (current != NULL) {
        cout<<current->val<<endl;
        current = current->next;
    }


}
