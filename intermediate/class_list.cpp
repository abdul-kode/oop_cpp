#include<iostream>
using namespace std;

struct node {
    int val;
    node *next = NULL;
};

class List {
    void delete_after_node(node* current);

    public:
    List();
    node *head, *last;
    void push(int val);
    int pop();
    void print_list();
};
List::List () {
    cout<<"Constructor Called: "<<endl;
    head = last = NULL;
}
void List::delete_after_node(node *current){
    node *temp = current->next;
    current->next = current->next->next;
    delete temp;
}
void List::push(int val) {
    node *temp = new node;
    temp->val = val;

    if (head==NULL){
        head = temp;
        last = temp;
    }
    else{
        last->next = temp;
        last = last->next;
    }
}
int List::pop() {
    int val;
    if (head->next == NULL) {
        val = head->val;
        delete head;
        head = NULL;
        last = NULL;
    }
    else {
        val = last->val;
        node* current = head;
        while(current->next != last) {
            current = current->next;
        }
        delete_after_node(current);
        last = current;
    }
    return val;
}
void List::print_list() {
    node* temp = head;
    cout<<"[ ";
    while (temp != NULL) {
        cout<<temp->val<<" ";
        temp = temp->next;
    }
    cout<<"]"<<endl;
}

int main () {
    cout<<"\nCreating list ..."<<endl;

    List *l = new List;
    cout<<"Pushing 10 and 13 value into the list: "<<endl;
    l->push(10);
    l->push(13);
    l->print_list();

    cout<<"Removing value, as it's a stack DS, the last value will be poped ..."<<endl;
    l->pop();
    l->print_list();

    cout<<endl;
    return 0;
}
